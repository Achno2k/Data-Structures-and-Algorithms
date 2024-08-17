#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node* lchild;
    Node* rchild;
};

class Tree
{
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }  // Passing Private Parameter in Constructor
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    void Levelorder();
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
    int countNodes(Node* p);
    int countNodes() { return countNodes(root); }
    int countLeafNodes(Node* p);
    int countLeafNodes() { return countLeafNodes(root); }
    int Height(Node* p);     
    int Height() { return Height(root); }
    void leftview(Node* p, int level, vector<int>& vec);
    void leftview(vector<int>& vec) { leftview(root, 0, vec); }
private:
    void destroyTree(Node* p);
};

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    destroyTree(root);
}

void Tree::destroyTree(Node* p) {
    if (p) {
        destroyTree(p->lchild);
        destroyTree(p->rchild);
        delete p;
    }
}

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;
    cout << "Enter root data: ";
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.emplace(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(Node* p) {
    if (p != nullptr) {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node* p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::Levelorder() {
    if (!root) return;

    queue<Node*> q;
    q.emplace(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        cout << p->data << " ";

        if (p->lchild) {
            q.emplace(p->lchild);
        }
        if (p->rchild) {
            q.emplace(p->rchild);
        }
    }
}

void Tree::iterativePreorder(Node* p) {
    stack<Node*> stk;
    while (p != nullptr || !stk.empty()) {
        if (p) {
            cout << p->data << " ";
            stk.emplace(p);
            p = p->lchild;
        }
        else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node* p) {
    stack<Node*> stk;
    while (p != nullptr || !stk.empty()) {
        if (p) {
            stk.emplace(p);
            p = p->lchild;
        }
        else {
            p = stk.top();
            stk.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node* p) {
    stack<long int> stk;
    long int temp;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.emplace((long int)p);
            p = p->lchild;
        }
        else {
            temp = stk.top();
            stk.pop();
            if (temp > 0) {
                stk.emplace(-temp);
                p = ((Node*)temp)->rchild;
            }
            else {
                cout << ((Node*)(-1 * temp))->data << " " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int Tree::countNodes(Node* p) {
    if (!p)
        return 0;

    return countNodes(p->lchild) + countNodes(p->rchild) + 1;
}

int Tree::Height(Node* p) {
    int x{ 0 }, y{ 0 };
    if (p) {
        x = Height(p->lchild);
        y = Height(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int Tree::countLeafNodes(Node* p) {
    int x{ 0 }, y{ 0 };
    if (p) {
        x = countLeafNodes(p->lchild);
        y = countLeafNodes(p->rchild);

        if (!p->lchild && !p->rchild)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

void Tree::leftview(Node* p, int level, vector<int>& vec) {
    if (!p) return;
    if (vec.size() == level) {
        cout << p->data << " ";
        vec.push_back(p->data);
    }
    leftview(p->lchild, level + 1, vec);
    leftview(p->rchild, level + 1, vec);
}

int main()
{
    Tree bt;
    bt.CreateTree();
    cout << "Inorder traversal: ";
    bt.Inorder();
    cout << endl;

    cout << "Number of Nodes are: " << bt.countNodes() << endl;
    cout << "The height of the tree is: " << bt.Height() << endl;
    cout << "The number of Leaf Nodes are: " << bt.countLeafNodes() << endl;

    vector<int> vec;
    cout << "The left view of the binary tree: ";
    bt.leftview(vec);
    cout << endl;

    return 0;
}
