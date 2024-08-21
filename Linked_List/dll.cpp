//
// Created by YASHAS J KUMAR on 20/08/24.
//
#include "iostream"

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    explicit Node(int data)
    {
        this->data = data;
        next = prev = nullptr;
    }
};

typedef Node* node;

node insert_front(node head, int data)
{
    node temp = new Node(data);
    if(head == nullptr)
        return temp;
    temp->next = head;
    head->prev = temp;
    return temp;
}

node insert_rear(node head, int data)
{
    node temp = new Node(data);
    if(head == nullptr)
        return temp;
    node cur = head;
    while(cur->next != nullptr)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

node delete_front(node head)
{
    if(head == nullptr)
    {
        cout<<"The List is Empty! Unable to Delete."<<endl;
        return head;
    }
    cout<<"Deleted "<<head->data<<endl;
    if(head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    head->next->prev = nullptr; //Broke the chain.
    node cur = head;
    head = head->next;
    delete cur;
    return head;
}

node delete_rear(node head)
{
    if(head == nullptr)
    {
        cout<<"The List is Empty! Unable to Delete."<<endl;
        return head;
    }
    if(head->next == nullptr)
    {
        cout<<"Deleted "<<head->data<<endl;
        delete head;
        return nullptr;
    }
    node cur = head, prev = nullptr;
    while(cur->next != nullptr)
    {
        prev = cur;
        cur = cur->next;
    }
    cout<<"Deleted "<<cur->data<<endl;
    delete cur;
    prev->next = nullptr;
    return head;
}

node reverse(node head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    node cur = head, prev = nullptr;
    while(cur != nullptr)
    {
        cur->prev = cur->next;
        cur->next = prev;
        prev = cur;
        cur = cur->prev;
    }
    cout<<"List is reversed!"<<endl;
    return prev;
}

void display(node head)
{
    if(head == nullptr)
    {
        cout<<"The List is Empty!"<<endl;
        return;
    }
    cout<<"The List Contains: "<<endl;
    cout<<head->data;
    if(head->next == nullptr)
        return;
    node cur = head->next;
    while (cur != nullptr)
    {
        cout<<" -> "<<cur->data;
        cur = cur->next;
    }
}

int main()
{
    node head = nullptr;
    int ch1, ch2, data;
    while(true)
    {
        cout<<"\n\n------------ Doubly Linked List ------------ \n\n";
        cout<<"1.Insert\n2.Delete\n3.Display\n4.Extra's\n5.Exit"<<endl;
        cout<<"\nPlease enter you Choice: ";
        cin>>ch1;
        switch (ch1)
        {
            case 1: cout<<"\n---------- Insert Options ----------"<<endl;
                    cout<< "\n1.Insert Front\n2.Insert Rear"<<endl;
                    cin>>ch2;
                    cout<<"Enter data: ";
                    cin>>data;
                    switch(ch2)
                    {
                        case 1: head = insert_front(head, data);
                                break;

                        case 2: head = insert_rear(head, data);
                                break;

                        default: cout<<"Invalid Choice!"<<endl;
                            break;
                    }
                    cout<<data<<" Inserted Successfully!"<<endl;

                    break;

            case 2: cout<<"\n---------- Delete Options ----------"<<endl;
                    cout<<"\n1.Delete Front\n2.Delete Rear"<<endl;
                    cin>>ch2;
                    switch (ch2)
                    {
                        case 1: head = delete_front(head);
                            break;

                        case 2: head = delete_rear(head);
                            break;

                        default: cout<<"Invalid Choice!"<<endl;
                            break;

                    }
                break;

            case 3:
                display(head);
                break;

            case 4: cout<<"\n------------ Extra's ---------------"<<endl;
                    cout<<"\n1.Reverse"<<endl;
                    cin>>ch2;
                    switch (ch2)
                    {
                        case 1: head = reverse(head);
                            display(head);
                            break;

                        default: cout<<"Invalid Choice!"<<endl;
                            break;
                    }
                break;

            case 5: cout<<"\n Thank You!"<<endl;
                exit(0);

            default: cout<<"Invalid Choice!"<<endl;
                break;
        }
    }
}
