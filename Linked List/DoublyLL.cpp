#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* prev;
	Node* next;

	Node (int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLL {
private:
	Node* head;
public:
	DoublyLL () : head (nullptr) {}

	void append (int key) {
		Node* newNode = new Node(key);
		if (head == nullptr) {
			head = newNode;
			return;

		} else {
			Node* curr = head;
			while (curr->next) {
				curr = curr->next;
			}
			curr->next = newNode;
			newNode->prev = curr;
		}
	}

	void display () {
		Node* curr = head;
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
};

int main () {
	DoublyLL ll;
	ll.append(1);
	ll.append(2);
	ll.append(3);
	ll.append(4);
	ll.append(5);

	ll.display();

	return 0;
}