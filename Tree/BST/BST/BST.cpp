#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node* lchild;
    Node* rchild;
};

class BST
{
private:
    Node* root;
public:
    BST() { root = nullptr; }
    Node* getRoot() { return root; }    //func for getting the root ptr
    void Insert(int key);               //iterative Insert
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }   //using constructor here
    Node* Search(int key);              //iterative Search
    Node* rSearch(Node* p, int key);    //recursive Search
    Node* rInsert(Node* p, int key);    //recursive Insert
    int Height(Node* p);
    Node* inPre(Node* p);               //Inorder Predecessor
    Node* inSucc(Node* p);              //Inorder Successor
    Node* Delete(Node* p, int key);
    void createFromPreorder(int *pre, int n);
};

void BST::Insert(int key) {
    Node* t = root;
    Node* p;
    Node* r = nullptr;

    if (root == nullptr) {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        if (key < t->data) {
            t = t->lchild;
        }
        else if (key > t->data) {
            t = t->rchild;
        }
        else {
        return;
    }

    while (t != nullptr) {
        r = t;
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data) {
        r->lchild = p;
    }
    else {
        r->rchild = p;
    }

}

void BST::Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

Node* BST::Search(int key) {
    Node* t = root;
    if (root == nullptr)
        return nullptr;
    while (t) {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return nullptr;
}

Node* BST::rSearch(Node* p, int key) {
    if (p == nullptr)
        return nullptr;
    
    if (key == p->data)
        return p;
    else if (key < p->data)
        return rSearch(p->lchild, key);
    else
        return rSearch(p->rchild, key);

}


Node* BST::rInsert(Node* p, int key) {
    Node* t = nullptr;
    if (p == nullptr) {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }
    if (key < p->data)
        p->lchild = rInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = rInsert(p->rchild, key);

    return p;
}

int BST::Height(Node* p) {
    if (p == nullptr) return 0;
    int x, y;
    x = Height(p->lchild);
    y = Height(p->rchild);

    return x > y ? x + 1 : y + 1;
}

Node* BST::inPre(Node* p) {
    while (p && p->rchild)
        p = p->rchild;

    return p;
}

Node* BST::inSucc(Node* p) {
    while (p && p->lchild)
        p = p->lchild;

    return p;
}

Node* BST::Delete(Node* p, int key) {
    Node* q = nullptr;
    if (p == nullptr)
        return nullptr;

    if (p->lchild == nullptr && p->rchild == nullptr) {
        if (p == root)
            root = nullptr;
        delete p;
        return nullptr;
    }

    if (key < p->data) 
        p->lchild = Delete(p->lchild, key);
 
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else {
        if (Height(p->lchild) > Height(p->rchild)) {
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, key);
        }
        else {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, key);
        }
    }
    return p;
}

void BST::createFromPreorder(int* pre, int n) {

    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = nullptr;
    root->rchild = nullptr;

    Node* t;
    Node* p = root;
    stack<Node*> stk;

    while (i < n) {
        // Left child case
        if (pre[i] < p->data) {
            t = new Node;
            t->data = pre[i++];
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else {
            // Right child cases
            if (pre[i] > p->data && pre[i] < stk.empty() ? INT16_MAX : stk.top()->data) {
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                p = t;
            }
            else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}


int main()
{
    BST bt;
    bt.Insert(20);
    bt.Insert(30);
    bt.Insert(10);

    //bt.Delete(bt.getRoot(), 20);


    bt.Inorder();   //always returns the values in sorted order
    cout << endl;

    Node* temp = bt.rSearch(bt.getRoot(), 40);
    if (temp) cout << "Element found in BST" << endl;
    else cout << "Element not found in BST" << endl;

    bt.rInsert(bt.getRoot(), 40);
    bt.Inorder();
    cout << endl;


    BST bt1;
    int pre[] = { 10, 20, 30, 40, 50 };
    bt1.createFromPreorder(pre, (sizeof(pre) / sizeof(pre[0])));
    bt1.Inorder();

    return 0;
}