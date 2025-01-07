#include "iostream"

using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(const int data) {
        this->data = data;
        next = nullptr;
    }
};

typedef Node* node;

class Stack {
    Node *top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int item) {
        node newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        cout<<"Item pushed."<<endl;
    }

    void pop() {
        if(top == nullptr) {
            cout<<"Stack is empty."<<endl;
            return;
        }
        node temp = top;
        cout<<"Item popped: "<<temp->data<<endl;
        top = top->next;
        delete temp;
    }

    bool is_empty() const {
        return top == nullptr;
    }

    int peak() {
        if (top != nullptr)
            return top->data;
        return -1;
    }
};

int main() {
    cout<<std::boolalpha;
    Stack s;

    cout<<"Is Empty: "<<s.is_empty()<<endl;

    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"Peak: "<<s.peak()<<endl;

    s.pop();

}