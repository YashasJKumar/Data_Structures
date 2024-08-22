#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int capacity;
    int* stack;

public:
    explicit Stack(int size) {
        capacity = size;
        stack = new int[capacity];
        top = -1;   // Stack is initially empty
    }

    // Destructor to free the memory allocated for the stack
    ~Stack() {
        delete[] stack;
    }

    // Push operation to add an element to the stack
    void push(int item) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << item << endl;
            return;
        }
        stack[++top] = item;
        cout << item << " pushed to stack." << endl;
    }

    // Pop operation to remove the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return -1;
        }
        return stack[top--];
    }

    // Peek operation to return the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return stack[top];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == capacity - 1;
    }

    // Get the current size of the stack
    int size() const {
        return top + 1;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  // This should trigger a stack overflow

    cout << "Top element is: " << s.peek() << endl;

    cout << "Stack size is: " << s.size() << endl;

    cout << s.pop() << " popped from stack." << endl;
    cout << s.pop() << " popped from stack." << endl;
    cout << s.pop() << " popped from stack." << endl;
    cout << s.pop() << " popped from stack." << endl;
    cout << s.pop() << " popped from stack." << endl;
    cout << s.pop() << " popped from stack." << endl;  // This triggers a stack underflow

    return 0;
}