#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
}*head = NULL;

void create(int A[], int len)
{
	Node* t, * last;
	head = new Node;
	head->data = A[0];
	head->next = head;
	last = head;

	for (int i = 1; i < len; i++) {
		t = new Node;
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

int count(class Node* h) {
	int count{ 0 };
	do {
		h = h->next;
		count++;
	} while (h != head);

	return count;
}

void display(class Node* h) {
	do {
		cout << h->data << " ";
		h = h->next;
	} while (h != head);

	cout << "\n";
}

void insert(class Node* h, int index, int key) {
	if (index < 0 || index > count(head))
		return;

	Node* t = new Node;
	t->data = key;

	if (index == 0) {
		if (head == NULL) {
			head = t;
			head->next = head;
		}
		else {
			t->next = head;
			while (h->next != head)
				h = h->next;

			h->next = t;
			head = t;
		}
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			h = h->next;
		}
		t->next = h->next;
		h->next = t;
	}	
}

int Delete(class Node* h, int index) {
	Node* t;
	int x{ -1 };
	if (index < 0 || index > count(head))
		return -1;

	if (index == 1) {
		while (h->next != head)
			h = h->next;

		if (h == head) {
			x = head->data;
			delete head;
			head = NULL;
		}
		else {
			h->next = head->next;
			x = head->data;
			delete head;
			head = h->next;
		}
	}
	else{
		for (int i = 0; i < index - 2; i++)
			h = h->next;
		
		t = h->next;
		h->next = t->next;
		x = t->data;
		delete t;
	}
	return x;
}

int main()
{
	int A[] = { 1,2,3,4,5 };
	create(A, 5);
	cout << "No. of Nodes: " << count(head) << "\n";
	display(head);

	//insert(head, 7, 7);
	//display(head);

	Delete(head, 1);
	display(head);


	return 0;
}

