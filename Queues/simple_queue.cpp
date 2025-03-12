#include <iostream>
using namespace std;

// Static Queue Implementation
class Queue {
    int front, rear, capacity;
    int* queue;

public:
    explicit Queue(int size) {
        capacity = size;
        front = 0;
        rear = -1;
        queue = new int[capacity];
    }

    // Destructor to free memory
    ~Queue() {
        delete[] queue;
    }

    void enqueue(const int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << data << endl;
            return;
        }

        queue[++rear] = data;
        cout << "Enqueued " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return;
        }

        cout << "Dequeued " << queue[front++] << endl;

        // If the queue becomes empty after dequeueing, reset the front and rear
        if (front > rear) {
            front = 0;
            rear = -1;
        }
    }

    bool isEmpty() const {
        return front > rear;
    }

    bool isFull() const {
        return rear == capacity - 1;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue contains: ";
        for (int i = front; i <= rear; ++i) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.display();

    q.enqueue(60);
    q.display();

    return 0;
}