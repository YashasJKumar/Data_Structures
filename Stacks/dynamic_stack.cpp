#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> stack;

public:
    void push(int item) {
        stack.push_back(item);
        cout << item << " pushed to stack." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return -1;  // Return an error value
        }
        int topElement = stack.back();
        stack.pop_back();
        return topElement;
    }

    // Peek operation to return the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;  // Return an error value
        }
        return stack.back();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return stack.empty();
    }

    // Get the current size of the stack
    int size() {
        return stack.size();
    }
};

int main() {
    Stack s;  // Create a dynamic stack

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Top element is: " << s.peek() << endl;
    cout << "Stack size is: " << s.size() << endl;

    cout << s.pop() << " popped from stack." << endl;
    cout << s.pop() << " popped from stack." << endl;

    cout << "Top element is: " << s.peek() << endl;
    cout << "Stack size is: " << s.size() << endl;

    return 0;
}