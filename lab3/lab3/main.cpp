#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Node {
	int info;
	struct Node* next = NULL;
};

struct Node* get_struct(void) {
	struct Node* p = NULL;
	int info;
	int priority = 0;

	if ((p = (struct Node*)malloc(sizeof(struct Node))) == NULL) {
		std::cout << "Memmory error" << std::endl;
		exit(1);
	}
	std::cout << "Enter information about object: ";
	std::cin >> info;

	p->info = info;

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

void deleteElement(struct Node*& head, int info) {
	struct Node* temp = head;
	struct Node* prev = NULL;
	bool flag = 0;

	while (temp && temp->info == info) {
		head = temp->next;
		free(temp);
		temp = head;
	}
	
	while (temp != NULL) {
        while (temp != NULL && temp->info != info) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            return;
        }

        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
}


int main() {
	struct Node* head = NULL;

	push(head);
	push(head);
	push(head);
	push(head);
	push(head);

	review(head);
	deleteElement(head, 2);
	review(head);
	
}