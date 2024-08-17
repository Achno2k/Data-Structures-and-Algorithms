#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public: 
    Node* head;
    LinkedList() : head(nullptr) {}

    void insert(int key) {
        Node* temp = new Node(key);
        if (head == nullptr) {
            head = temp;
            return;
        }
        Node* dummyHead = head;
        while (dummyHead->next) {
            dummyHead = dummyHead->next;
        }
        dummyHead->next = temp;
    }

    void display() {
        Node* p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void createLoop(int index) {
        if (index < 0) return;
        
        Node* curr = head;
        Node* loopNode = nullptr;
        int count = 0;
        while (curr && curr->next) {
            if (count == index) {
                loopNode = curr;
            }
            curr = curr->next;
            count++;
        }

        if (curr && loopNode) {
            curr->next = loopNode;
        }
    }

    bool isLoop() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    void test() {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        cout << prev->data << "\n";
        cout << curr->data << "\n";
    }

    void reverseLL () {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextAddress = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextAddress;
        }

        head = prev;
    }
};

int main() {
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);


    l1.display();
    // l1.test();
    l1.reverseLL();
    l1.display();

    // cout << l1.isLoop() << endl;
    // l1.display();

    return 0;
}
