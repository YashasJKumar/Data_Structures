#include "iostream"

using namespace std;

class node{
public:
    int data;
    node *address;

    explicit node(int data)
    {
        this->data = data;
        address = nullptr;
    }

};
node* xored_address(node* prev, node* next)
{
    if(prev == nullptr && next == nullptr)
        return nullptr;
    return (node*) ((uintptr_t)prev ^ (uintptr_t)next);
}
typedef node * Node;

void insert_front(Node &head, int data)
{
    Node temp = new node(data);
    if(head == nullptr){
        head = temp;
        return;
    }
    temp->address = xored_address(nullptr, head);
    head->address = xored_address(temp, head->address);
    head = temp;
}

void insert_rear(Node& head, int data)
{
    Node temp = new node(data);
    if(head == nullptr){
        head = temp;
        return;
    }
    Node prev = nullptr, cur = head, next;

    while(cur->address != prev){
        next = (Node)((uintptr_t)prev ^ (uintptr_t)cur->address);
        prev = cur;
        cur = next;
    }

    temp->address = xored_address(cur, nullptr);
    cur->address = xored_address(prev, temp);
}

void display(Node &head)
{
    if(head == nullptr)
        cout<<"List is Empty!"<<endl;
    else{
        Node temp = head, prev = nullptr, next_node;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            next_node = (Node)((uintptr_t)prev ^ (uintptr_t)temp->address);
            prev = temp;
            temp = next_node;
        }
        cout<<endl;
    }
}

int main()
{
    Node head = nullptr;
    insert_front(head, 30);
    insert_front(head, 20);
    insert_front(head, 10);
    insert_rear(head, 40);

    display(head);
}