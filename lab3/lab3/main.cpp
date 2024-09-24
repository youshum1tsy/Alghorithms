#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Node {
	char info[256];
	int priority;
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


	while (priority <= 0) {
		std::cout << "Enter priority(> 0) for object: ";
		std::cin >> priority;
	}


	strcpy(p->info, info);
	p->priority = priority;

	p->next = NULL;
	std::cout << "----\n";
	return p;
}

struct Node* findPriority(struct Node* head, int priority) {
	struct Node* prev = head;
	while (priority > head->priority) {
		prev = head;
		head = head->next;
	}
	return prev;
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
	else if (p->priority < head->priority) {
		p->next = head;
		head = p;
	}
	else if (p != NULL && p->priority >= last->priority) {
		last->next = p;
		last = p;
	}
	else {
		prev = findPriority(head, p->priority);
		next = prev->next;

		prev->next = p;
		p->next = next;
	}

	return;
}

void review(struct Node* head) {
	while (head) {
		std::cout << "info: " << head->info << " priority: " << head->priority << "\n";
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
	std::cout << "Deleted this element\ninfo: " << temp->info << " priority: " << temp->priority << "\n";
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