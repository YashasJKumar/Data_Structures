#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* queue;

public:
    explicit Queue(int size) {
        capacity = size;
        front = rear = -1;
        queue = new int[capacity];
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << data << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;  //Circular behaviour
        }

        queue[rear] = data;
        cout << "Enqueued " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return;
        }

        cout << "Dequeued " << queue[front] << endl;

        if (front == rear) {
            front = rear = -1; // Reset the queue after removing the last element
        } else {
            front = (front + 1) % capacity;
        }
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (rear + 1) % capacity == front;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return queue[front];
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << queue[i] << " ";
        }
        cout << queue[rear] << endl; // Display the last element
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
