#include <iostream>
#include <set>
//ограничить размер дерева на 20 node
//найти сколько раз повторяются все элементы в дереве
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
	/*else if (data == r->data) {
		return root;
	}*/
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

Node* count_all_elements_in_tree(Node* root, Node* head, std::set<int> &roots) {
	if (root == NULL) {
		return nullptr;
	}
	if (roots.count(root->data) == 0 ) {
		std::cout << root->data << " count " << count_elements_in_tree(head, root->data) << "\n";
		roots.insert(root->data);
	}
	
	count_all_elements_in_tree(root->left, head, roots);
	count_all_elements_in_tree(root->right, head, roots);	
	
}

int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;
	int find = 0;
	int target = 0;
	int maxNode = 10;
	int i = 0;
	Node* root = NULL;
	std::cout << "enter -1 to end of the tree construction\n";
	while (start && i != maxNode)
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
			i++;
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
		std::cout << "element not found\n";
	}

	separator();
	std::cout << "enter target to count in tree: ";
	std::cin >> target;
	std::cout << "count: " << count_elements_in_tree(root, target) << "\n";
	separator();
	std::set<int> roots;
	count_all_elements_in_tree(root, root, roots);

	return 0;
}