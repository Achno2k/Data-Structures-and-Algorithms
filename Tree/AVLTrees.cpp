#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	int height;
	Node* lchild;
	Node* rchild;
	Node(int val) {
		this->data = val;
		this->height = 0;
		this->lchild = nullptr;
		this->rchild = nullptr;
	}
};

int nodeHeight (Node* p) {
	int hl, hr;
	if p && p->lchild ? p->lchild->height : 0;
	if p && p->rchild ? p->rchild->height : 0; 

	return hl > hr ? hl+1:hr+1;
}

int balanceFactor (Node* p) {
	int hl, hr;
	if p && p->lchild ? p->lchild->height : 0;
	if p && p->rchild ? p->rchild->height : 0;

	return hl-hr;
}

Node* LLRotation (Node* p) {
	Node* pl = p->lchild;
	Node* plr = pl->rchild;

	pl->rchild = p;
	p->lchild = plr;
	p->height = nodeHeight(p);
	pl->height = nodeHeight(pl);

	if (root == p) {
		root = pl;
	}
	return pl;
}

Node* insert (Node* p, int key) {
	if (p == nullptr) {
		Node* temp = new Node(key);
		return temp;
	}
	if (key < p->data) {
		p->lchild = insert(p->lchild, key);
	} else if (key > p->data) {
		p->rchild = insert(p->rchild, key);
	}
	p->height = nodeHeight(p);

	//checking balance factor to perform rotations
	if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
		return LLRotation(p);
	else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
		return LRRotation(p);
	else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
		return RRRotation(p);
	else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
		return RLRotation(p);

	return p;
}

void inorder(Node* p) {
	if (p) {
		inorder(p->lchild);
		cout << p->data << " ";
		inorder(p->rchild);
	}
}
 

int main () {
	Node* root = nullptr;
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 15);

	inorder(root);
	return 0;
}