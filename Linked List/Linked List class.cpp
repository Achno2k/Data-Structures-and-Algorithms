#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class LinkedList : public Node
{
private:
	Node* first;
public:
	LinkedList() { first = NULL; }
	LinkedList(int A[], int len) ;
	~LinkedList() ;
	Node* getFirst() { return first; }
	void display();
	int count() ;
	void Insert(int index, int key) ;
	int Delete(int index) ;
	int getSum();
	void maxMin();
	bool checkSort();
	LinkedList operator + (class LinkedList t);
	bool isLoop();
};

LinkedList::LinkedList(int A[], int len)
{
	Node* t=NULL, * last=NULL;
	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (int i = 1; i < len; i++) {
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

LinkedList::~LinkedList()
{
	Node* p = first;
	while (first != nullptr) {
		first = first->next;
		delete p;
		p = first;
	}
	cout << "Destructor called" << endl;
}

void LinkedList::display()
{
	Node* p = first;
	while (p != 0) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int LinkedList::count()
{
	Node* p = first;
	int count{ 0 };
	while (p != 0) {
		count++;
		p = p->next;
	}
	return count;
}

void LinkedList::Insert(int index, int key)
{
	if (index<0 || index>count())
		return;

	Node* p = first;
	Node* t;
	t = new Node;
	t->data = key;
	if (index == 0) {
		t->next = first;
		first = t;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}
}

int LinkedList::Delete(int index)
{
	if (index<0 || index>count())
		return -1;

	int x{ -1 };
	Node* p = first;
	Node* t = nullptr;
	if (index == 0) {
		t = p;
		x = first->data;
		first = first->next;
		delete t;
		return x;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			t = p;
			p = p->next;
		}
		t->next = p->next;
		x = p->data;
		delete p;
		return x;
	}
}

int LinkedList::getSum()
{
	Node* p = first;
	int sum{ 0 };
	while (p != 0) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

void LinkedList::maxMin()
{
	Node* p = first;
	int max = INT32_MIN;
	int min = INT32_MAX;
	while (p) {
		if (p->data > max)
			max = p->data;
		else if (p->data < min)
			min = p->data;
		p = p->next;
	}
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
}

bool LinkedList::checkSort()
{
	Node* p = first;
	int x = INT32_MIN;
	while (p) {
		if (x > p->data)
			return false;

		x = p->data;
		p = p->next;
	}
	return true;
}

LinkedList LinkedList :: operator + (class LinkedList t)
{
	Node* p = this->first;
	Node* q = t.first;

	LinkedList temp;
	temp.first = p;
	while (p->next != 0) {
		p = p->next;
	}
	p->next = q;
	q = nullptr;

	return temp;
}

bool LinkedList::isLoop()
{
	Node* p = first, * q = first;
	do {
		p = p->next;
		q = q->next;
		q = q ? q->next : nullptr;
		
	} while (p && q && p != q);

	return (p == q);
}

LinkedList mergeSorted(Node* list1, Node* list2)
{
	Node* p = list1;
	Node* q = list2; 
	Node* temp = nullptr;
	Node* last;

	if (list1 == nullptr) return list2;
	if (list2 == nullptr) return list1;

	if (p->data < q->data) {
		temp = last =  p;
		last->next = nullptr;
		p = p->next;
	}
	else {
		temp = last = q;
		last->next = nullptr;
		q = q->next;
	}

	while (p && q) {
		if (p->data < q->data) {
			last->next = p;
			last = p;
			p = p->next;
		}
		else {
			last->next = q;
			last = q;
			q = q->next;
		}
	}

	if (p) last->next = p;
	if (q) last->next = q;

	LinkedList l;
	l.getFirst() = temp;
	return l;
}


int main()
{
	int A[] = { 1,2,3,4,5 };
	LinkedList l1(A, 5);
	int B[] = { 6,7,8,9,10 };
	LinkedList l2(B, 5);

	l1.display();
	cout << l1.isLoop() << endl;
	l2.display();

	return 0;
}