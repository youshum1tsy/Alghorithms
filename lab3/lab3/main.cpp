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


void push(struct Node*& head) {
	struct Node* p = NULL;

	p = get_struct();

	if (head == NULL && p != NULL) {
		head = p;
	}
	else {
		p->next = head;
		head = p;
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

void pop(struct Node*& head) {
	if (head == NULL) {
		std::cout << "List empty";
		return;
	}

	struct Node* temp = head;
	head = head->next;

	temp->next = NULL;
	std::cout << "Deleted this element\ninfo: " << temp->info <<"\n";
	std::cout << "----\n";
	free(temp);
}


int main() {
	struct Node* head = NULL;

	push(head);
	push(head);
	push(head);
	push(head);

	review(head);
	pop(head);
	review(head);
}