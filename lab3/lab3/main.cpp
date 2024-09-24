#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Node {
	char info[256];
	struct Node* next = NULL;
};

struct Node* get_struct(void) {
	struct Node* p = NULL;
	char info[256];
	int priority = 0;

	if ((p = (struct Node*)malloc(sizeof(struct Node))) == NULL) {
		std::cout << "Memmory error" << std::endl;
		exit(1);
	}
	std::cout << "Enter information about object: ";
	std::cin >> info;

	strcpy(p->info, info);

	p->next = NULL;
	std::cout << "----\n";
	return p;
}


void spstore(struct Node*& head, struct Node*& last) {
	struct Node* p = NULL;

	struct Node* prev = NULL;
	struct Node* next = NULL;

	p = get_struct();

	if (head == NULL && p != NULL) {
		head = p;
		last = p;
	}
	else {
		last->next = p;
		last = p;
	}
	return;
}

void review(struct Node* head) {
	while (head) {
		std::cout << "info: " << head->info << "\n";
		head = head->next;
	}
	std::cout << "----\n";
	return;
}

void deleteFirstElement(struct Node*& head, struct Node*& last) {
	if (head == NULL) {
		std::cout << "List empty";
		return;
	}

	struct Node* temp = head;
	head = head->next;

	if (head == NULL) {
		last = NULL;
	}

	temp->next = NULL;
	std::cout << "Deleted this element\ninfo: " << temp->info << "\n";
	std::cout << "----\n";
	free(temp);
}


int main() {
	struct Node* head = NULL;
	struct Node* last = NULL;

	spstore(head, last);
	spstore(head, last);
	spstore(head, last);
	spstore(head, last);

	review(head);
	deleteFirstElement(head, last);
	review(head);
}