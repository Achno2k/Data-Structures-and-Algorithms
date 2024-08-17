#include <iostream>
using namespace std;

class Node
{
public:
	Node* prev;
	int data;
	Node* next;
} *first = NULL;

void create(int A[], int len)
{
	Node* t, *last;
	first = new Node;
	first->prev = NULL;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (int i = 1; i < len; i++) {
		t = new Node;
		t->data = A[i];
		t->prev = last;
		t->next = last->next;
		last->next = t;
		last = t;
	}
}

void display(class Node* p) {
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int count(class Node* p) {
	int count{ 0 };
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

void insert(class Node* p, int index, int key)
{
	if (index < 1 || index > count(first))
		return;

	Node* t = new Node;
	t->data = key;

	if (index == 1) {
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else {
		for (int i = 0; i < index - 1; i++)
			p = p->next;

		t->prev = p;
		t->next = p->next;
		p->next = t;
	}

}

int Delete(class Node* p, int index)
{
	if (index < 1 || index > count(first))
		return -1;

	int x{ -1 };

	if (index == 1) {
		first = first->next;
		if(first)
			first->prev = NULL;
		x = p->data;
		delete p;
		return x;
	}
	else {
		for (int i = 0; i < index-1; i++) 
			p = p->next;
		
		p->prev->next = p->next;
		if(p->next) 
			p->next->prev = p->prev;
		x = p->data;
		delete p;
		return x;
	}
}


void reverse(class Node* p)
{
	Node* temp;
	while (p) {
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if (p!=NULL && p->next == NULL)
			first = p;
	}
}

int main()
{
	int A[] = { 1,2,3,4,5 };
	create(A, 5);
	display(first);
	//cout << "Length of the Linked List is: " << count(first) << endl;
	//insert(first, 1, 8);
	//cout << "Deleted Value: " << Delete(first, 1) << endl;
	//display(first);
	reverse(first);
	display(first);

	return 0;
}
