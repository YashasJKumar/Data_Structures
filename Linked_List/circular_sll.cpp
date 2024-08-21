#include "iostream"
using namespace std;
typedef struct node
{
    int info;
    struct node *link;

    explicit node(int item)
    {
        info = item;
        link = nullptr;
    }
}*Node;

Node insert_front(Node last,int item)
{
    Node temp = new node(item);
    if (last == nullptr) {
        last = temp;
        temp->link = last;
    }
    else
    {
    temp->link = last->link;
    last->link = temp;
    }
    cout<<"Insertion Successfull\n";
    return last;
}

Node insert_rear(Node last,int item)
{
    if(last == nullptr)
        last = insert_front(last, item);
    else {
        Node temp = new node(item);
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
    cout << "Insertion Successfull\n";
    return last;
}

Node delete_front(Node last)
{
    if(last->link == nullptr)
    {
        cout<<"List is Empty! Unable to delete."<<endl;
        return last;
    }
    cout<<"Deletion Successfull \nDeleted element is : "<<last->link->info<<endl;
    Node cur = last->link;
    last->link = last->link->link;
    free(cur);
    return last;
}

Node delete_rear(Node last)
{
    if(last->link == nullptr)
    {
        cout<<"List is Empty! Unable to delete."<<endl;
        return last;
    }
    Node cur = last->link;
    while(cur->link != last)
        cur = cur->link;
    cout<<"Deletion Successfull! \nDeleted element is : "<<last->info<<endl;
    cur->link = last->link;
    free(last);
    last = cur;
    return last;
}

Node delete_info(Node last, int item)
{
    if(last->link == nullptr)
    {
        cout<<"List is Empty! Deletion Unsuccessfull."<<endl;
        return last;
    }
    else if(last->link->info == item)
    {
        last = delete_front(last);
        return last;
    }
    Node cur,prev;
    cur = last->link;
    while(cur != last)
    {
        if(cur->info == item)
            break;
        prev = cur;
        cur=cur->link;
    }
    if(last->info == item)
    {
        last = delete_rear(last);
        return last;
    }
    else if(cur == last)
    {
        cout<<"Deletion Unsuccessfull! Element not present in the list."<<endl;
        return last;
    }
    prev->link = cur->link;
    cout<<"Deletion Successfull!\nDeleted Element is: "<<cur->info<<endl;
    return last;
}
void display(Node last)
{
    if(last == nullptr || last->link == nullptr)
        cout<<"List is Empty!"<<endl;
    else{
        Node cur;
        cur = last->link;
        cout<<"The List contains : "<<endl;
        while(cur!=last)
        {
            cout<<cur->info<<"->";
            cur = cur->link;
        }
        cout<<last->info<<endl;
    }
}

Node reverse(Node last)
{
    if(last == nullptr || last->link == last)
        return last;
    Node prev = last;
    Node cur = last->link, next;
    while(cur != last)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    //reversing last node.
    last = last->link;
    cur->link = prev;
    return last;
}

int main()
{
    Node last = nullptr;
    int item,ch1,ch2;
    cout<<"---------Circular Singly Linked List--------"<<endl;
    while(true)
    {
        cout<<"\n---------Menu--------\n1.Insert\n2.Delete\n3.Display\n4.Reverse\n5.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch1;
        switch (ch1)
        {
            case 1: cout<<"\n1.Insert Front\n2.Insert Rear"<<endl;
                    cin>>ch2;
                    switch(ch2)
                    {
                        case 1: cout<<"Enter item to be inserted: ";
                                cin>>item;
                                last = insert_front(last, item);
                                break;
                        case 2: cout<<"Enter item to be inserted: ";
                                cin>>item;
                                last = insert_rear(last, item);
                                break;
                        default: cout<<"Invalid choice\n";
                                 break;
                    }
                    break;
            case 2: cout<<"\n1.Delete Front\n2.Delete Rear\n3.Delete info"<<endl;
                    cin>>ch2;
                    switch(ch2)
                    {
                        case 1: last = delete_front(last);
                                break;
                        case 2: last = delete_rear(last);
                                break;
                        case 3: cout<<"Enter item to be deleted: ";
                                cin>>item;
                                last = delete_info(last,item);
                                break;
                        default: cout<<"Invalid choice\n";
                                 break;
                    }
                    break;
            case 3: display(last);
                    break;

            case 4: last = reverse(last);
                    cout<<"\nAfter Reversal.."<<endl;
                    display(last);
                    break;
            case 5: cout<<"\n------Thank You!------"<<endl;
                    exit(0);
            default: cout<<"Invalid choice\n";
                    break;
        }
    }
}