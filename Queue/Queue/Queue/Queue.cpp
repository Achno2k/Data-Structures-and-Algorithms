#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int front, rear;
    int* arr;
};

void create(Queue* q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->arr = new int[size];
}

void enqueue(Queue* q, int key) {
    if (q->rear == q->size - 1)
        cout << "Queue is Full!" << endl;
    else {
        q->rear++;
        q->arr[q->rear] = key;
    }
}

int dequeue(Queue* q) {
    int x{ -1 };
    if (q->front == q->rear)
        cout << "Queue is empty" << endl;
    else {
        q->front++;
        x = q->arr[q->front];
    }
    return x;
}

void display(Queue q) {
    for (int i = q.front + 1; i < q.rear; i++)
        cout << q.arr[i] << " ";
    cout << endl;
}


//for circular queue
void c_enqueue(Queue* q, int key) {
    if ((q->rear + 1) % q->size == q->front)
        cout << "Queue is full!" << endl;
    else {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = key;
    }
}

int c_dequeue(Queue* q) {
    int x{ -1 };
    if (q->rear == q->front)
        cout << "Queue is empty" << endl;
    else {
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

//main starts
int main()
{
    Queue q;
    create(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(q);
    return 0;
}


