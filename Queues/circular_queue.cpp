#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity, count;
    int* queue;

public:
    explicit Queue(const int size) {
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
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

        rear = (rear + 1) % capacity;  //Circular behaviour

        queue[rear] = data;
        count++;
        cout << "Enqueued " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return;
        }

        cout << "Dequeued " << queue[front] << endl;
        count--;
        front = (front + 1) % capacity;
        if (isEmpty())
            front = 0, rear = -1;
        //Pointers are reset if it becomes empty!.
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
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

    q.isEmpty() == 1 ? cout << "Queue is empty" << endl : cout << "Queue is not empty" << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.enqueue(60);

    q.dequeue();
    q.display();

    q.enqueue(60);
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
