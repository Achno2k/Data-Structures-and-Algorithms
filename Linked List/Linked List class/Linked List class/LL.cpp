#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() : head(nullptr) {}

	void insert(int key) {
		Node* newNode = new Node(key);
		if (head == nullptr) {
			head = newNode;
		} else {
			Node* curr = head;
			while (curr->next) {
				curr = curr->next;
			}
			curr->next = newNode;
		}
	}

	void insertLL (int key, int index) {
		Node* newNode = new Node (key);
		if (index == 0) {
			newNode->next = head;
			head = newNode;
		} else {
			Node* curr = head;
			for(int i=0; i<index; i++) {
				curr = curr->next;
			}
			Node* nextAddress = curr->next;
			curr->next = newNode;
			newNode->next = nextAddress;
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

int main() {
	LinkedList ll;
	ll.insert(1);
	ll.insert(2);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);

	ll.display();
	
	return 0;
}