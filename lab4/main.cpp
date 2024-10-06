#include <iostream>

struct Node {
	Node* right = nullptr;
	Node* left = nullptr;
	int data = 0;
};
struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			std::cout << "Memmory error";
			exit(0);
		}
		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) {
			return r;
		}
		if (data > root->data) {
			root->left = r;
		}
		else {
			root->right = r;
		}
		return r;
	}
	if (data > r->data) {
		CreateTree(r, r->left, data);
	}
	else {
		CreateTree(r, r->right, data);
	}
	return root;
}
void print_tree(struct Node* r, int l)
{
	if (r == NULL)
	{
		return;
	}
	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		std::cout << " ";
		std::cout << " ";
	}
	std::cout << r->data << "\n";
	print_tree(r->left, l + 1);
}
struct Node* find_node(struct Node* root, int find_data) {
	if (root == NULL) {
		return nullptr;
	}
	if (root->data == find_data) {
		return root;
	}
	if (find_data > root->data) {
		return find_node(root->left, find_data);
	}
	else {
		return find_node(root->right, find_data);
	}
}

int count_elements_in_tree(struct Node* root, int target) {
	
	if (root == NULL) {
		return 0;
	}
	int count;
	if (root->data == target) {
		count = 1;
	}
	else {
		count = 0;
	}

	count += count_elements_in_tree(root->right, target);
	count += count_elements_in_tree(root->left, target);
	
	return count;
}

void separator() {
	std::cout << "-----\n";
}

int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;
	int find = 0;
	int target = 0;
	Node* root = NULL;
	std::cout << "enter -1 to end of the tree construction\n";
	while (start)
	{
		std::cout << "enter value of the tree element: ";
		std::cin >> D;
		if (D == -1)
		{
			std::cout << " ";
			start = 0;
		}
		else {
			root = CreateTree(root, root, D);
		}
	}

	separator();
	print_tree(root, 0);
	separator();

	std::cout << "enter find value: ";
	std::cin >> find;
	separator();

	Node* findNode = find_node(root, find);
	if (findNode != nullptr) {
		print_tree(findNode, 0);
	}
	else {
		std::cout << "element not found";
	}

	separator();
	std::cout << "enter target to count in tree: ";
	std::cin >> target;
	std::cout << "count: " << count_elements_in_tree(root, target) << "\n";
	separator();

	return 0;
}