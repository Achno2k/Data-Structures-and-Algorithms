#include <iostream>
using namespace std;


class Node {
public:
	int data;
	Node* next;
};

class HashTable {
private:
	Node** ht;
public:
	HashTable();
	~HashTable();
	int hash(int key);
	void Insert(int key);
	int Search(int key);
};

HashTable::HashTable() {
	ht = new Node * [10] {nullptr};
}

HashTable::~HashTable() {
	for (int i = 0; i < 10; i++) {
		Node* p = ht[i];
		while (p) {
			ht[i] = ht[i]->next;
			delete p;
			p = ht[i];
		}
	}
	delete[] ht;
}

int HashTable::hash(int key) {
	return key % 10;
}


//this insert function inserts elements in sorted order
void HashTable::Insert(int key) {
	int index = hash(key);
	Node* t = new Node;
	t->data = key;
	t->next = nullptr;
	
	if (ht[index] == nullptr)
		ht[index] = t;
	else {
		Node* p = ht[index];
		Node* q = ht[index];
		while (p && p->data < key) {
			q = p;
			p = p->next;
		}
		if (q == ht[index]) {
			t->next = ht[index];
			ht[index] = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}
}

int HashTable::Search(int key) {
	Node* p = ht[hash(key)];
	while (p) {
		if (p->data == key)
			cout << "Key found : " << p->data << endl;
		p = p->next;
	}
	return -1;
}

int main()
{
	int A[] = { 16, 12, 25, 39, 6, 122, 5, 68, 75 };
	int n = sizeof(A) / sizeof(A[0]);
	HashTable H;
	for (int i = 0; i < n; i++) {
		H.Insert(A[i]);
	}

	cout << "Successfull Search\n";
	H.Search(39);

	cout << endl;

	cout << "Unsuccessfull Search";
	H.Search(11);

	return 0;
}
