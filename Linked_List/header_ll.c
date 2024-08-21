#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *llink,*rlink;
};
typedef struct node *NODE;

NODE getNODE()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(-1);
    }
    return x;
}
void display(NODE head)
{
    NODE cur;
    if(head->info == 0)
    {
        printf("List is Empty!\n");
        return;
    }
    cur = head->rlink;
    printf("List contains : \n");
    while(cur->rlink!=NULL)
    {
        printf("%d->",cur->info);
        cur = cur->rlink;
    }
    printf("%d\n",cur->info);
}
int search(NODE head, int key)
{
    NODE cur;
    int loc = 1;
    if(head->rlink == NULL)
    {
        printf("List is Empty!\n");
        return 0;
    }
    cur = head->rlink;
    while(cur != NULL)
    {
        if(key == cur->info)
            return loc;
        cur = cur->rlink;
        loc++;
    }
    return 0;
}
NODE insert_front(NODE head,int item)
{
    NODE temp;
    temp = getNODE();
    temp->info = item;
    temp->llink = temp->rlink = NULL;
    if(head->rlink == NULL)
    {
        head->rlink = temp;
        temp->llink = head;
        head->info++;
        return head;
    }
    head->rlink->llink = temp;
    temp->rlink = head->rlink;
    head->rlink = temp;
    temp->llink = head;
    head->info++;
    printf("Insertion Successfull!\n");
    return head;
}
NODE insert_rear(NODE head,int item)
{
    NODE temp,cur;
    temp = getNODE();
    temp->info = item;
    temp->llink = temp->rlink = NULL;
    if(head->rlink == NULL)
    {
        head->rlink = temp;
        temp->llink = head;
        head->info++;
        return head;
    }
    cur = head->rlink;
    while(cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    printf("Insertion Successfull!\n");
    head->info++;
    return head;
}
NODE insert_at_pos(NODE head,int item,int pos)
{
    NODE temp,cur;
    int count = 1;
    if(pos<=0)
    {
        printf("Please Enter correct position!\n");
        return head;
    }
    if(pos ==1)
    {
        head = insert_front(head, item);
        return head;
    }
    cur = head->rlink;
    while(cur != NULL)
    {
        count++;
        if(count == pos)
            break;
        cur = cur->rlink;
    }
    if(count != pos)
    {
        printf("Incorrect Position\n");
        return head;
    }
    if(cur->rlink == NULL)
    {
        head = insert_rear(head, item);
        return head;
    }
    temp = getNODE();
    temp->info = item;
    temp->llink = temp->rlink = NULL;
    temp->rlink = cur->rlink;
    cur->rlink->llink = temp;
    temp->llink = cur;
    cur->rlink = temp;
    head->info++;
    printf("Insertion Successfull!\n");
    return head;
}
NODE insert_left(NODE head, int item, int info)
{
    NODE temp,cur;
    int pos = 1;
    if(info == head->rlink->info)
    {
        head = insert_front(head, item);
        return head;
    }
    cur = head->rlink;
    while(cur != NULL)
    {
        if(cur->info == info)
            break;
        cur = cur->rlink;
        pos++;
    }
    if(cur == NULL)
    {
        printf("Incorrect Position\n");
        return head;
    }
    temp = getNODE();
    temp->info = item;
    temp->llink = cur->llink;
    cur->llink->rlink = temp;
    cur->llink = temp;
    temp->rlink = cur;
    printf("Insertion Successfull!\n");
    head->info++;
    return head;
}
NODE insert_right(NODE head,int item, int pos)
{
    NODE cur, temp;
    if(head->rlink == NULL)
    {
        printf("List is Empty!\nInserting element to the List\n");
        head = insert_front(head, item);
        return head;
    }
    cur = head->rlink;
    while(cur!=NULL)
    {
        if(cur->info == pos)
            break;
        cur = cur->rlink;
    }
    if(cur == NULL)
    {
        printf("Incorrect Position\n");
        return head;
    }
    if(cur->rlink == NULL)
        head = insert_rear(head, item);
    else
    {
        temp = getNODE();
        temp->info = item;
        cur->rlink->llink = temp;
        temp->rlink = cur->rlink;
        cur->rlink = temp;
        temp->llink = cur;
        printf("Insertion Successfull!\n");
        head->info++;
    }
    return head;
}
NODE delete_front(NODE head)
{
    NODE first;
    if(head->rlink == NULL || head->info == 0)
    {
        printf("List Empty! Unable to Delete\n");
        return head;
    }
    first = head->rlink;
    first->rlink->llink = head;
    head->rlink = first->rlink;
    printf("Deleted Element : %d",first->info);
    free(first);
    first = NULL;
    head->info--;
    return head;
}

NODE delete_rear(NODE head)
{
    NODE last;
    if(head->rlink == NULL)
    {
        printf("List is Empty!\nUnable to Delete\n");
        return head;  //return NULL;
    }
    last = head->rlink;
    while(last->rlink != NULL)
    {
        last = last->rlink;
    }
    last->llink->rlink = NULL;  //previous node connection has been detached.
    printf("Deleted Element is: %d\n",last->info);
    free(last);
    last = NULL;
    head->info--;
    return head;
}
NODE delete_info(NODE head, int info)
{
    NODE cur;
    if(head->rlink == NULL)
    {
        printf("List Empty!\n");
        return head;
    }
    cur = head->rlink;
    while(cur != NULL)
    {
        if(cur->info == info)
            break;
        cur = cur->rlink;
    }
    if(cur == NULL)
    {
        printf("Element not found\n");
        return head;
    }
    if(cur->rlink == NULL)
    {
        head = delete_rear(head);
        return head;
    }
    cur->rlink->llink = cur->llink;
    cur->llink->rlink = cur->rlink;
    printf("Deleted Element is: %d\n",cur->info);
    free(cur);
    cur = NULL;
    head->info--;
    return head;
}
NODE delete_left(NODE head, int item)
{
    NODE cur;
    if(head->rlink == NULL)
    {
        printf("List Empty!\n");
        return head;
    }
    cur = head->rlink;
    if(cur->info == item)
    {
        printf("Deletion Unsuccessfull!\nNo node exists at its left!\n");
        return head;
    }
    while(cur != NULL)
    {
        if(cur->info == item)
            break;
        cur = cur->rlink;
    }
    if(cur == NULL)
    {
        printf("Element not found\n");
        return head;
    }
    cur = cur->llink;    //Pointing cur to the left node since it's delete left.
    cur->rlink->llink = cur->llink;
    cur->llink->rlink = cur->rlink;
    printf("Deleted Element is: %d\n",cur->info);
    free(cur);
    cur = NULL;
    head->info--;
    return head;
}
NODE delete_right(NODE head, int item)
{
    NODE cur;
    if(head->rlink == NULL)
    {
        printf("List is Empty!\n");
        return head;
    }
    cur = head->rlink;
    while(cur->rlink!=NULL)
    {
        if(cur->info == item)
            break;
        cur = cur->rlink;
    }
    if(cur->rlink == NULL)
    {
        printf("Deletion Unsuccessfull.\nNo Node exists to its Right\n");
        return head;
    }
    cur = cur->rlink;    //Pointing cur to the node that has to be deleted.
    if(cur->rlink == NULL)
        head = delete_rear(head);
    else
    {
        cur->rlink->llink = cur->llink;
        cur->llink->rlink = cur->rlink;
        printf("Deleted Element is : %d\n",cur->info);
        free(cur);
        cur = NULL;
        head->info--;
    }
    return head;
}
int main()
{
    int choice, item, pos, n;
    NODE head;
    head = getNODE();
    head->llink = head->rlink = NULL;
    head->info = 0;
    printf("Enter number of NODE's: ");
    scanf("%d",&n);
    if(n!=0)
    {
        printf("Enter items: ");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&item);
            head = insert_rear(head, item);
        }
    }
    while(1)
    {
        printf("\nGrounded Header Linked List\n");
        printf("--------Menu--------\n");
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Number of NODEs\n6.Exit\n");
        printf("Please Enter Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: printf("\n Insert Options \n");
                printf("1.Insert Front\n2.Insert rear\n3.Insert at Position\n4.Insert Left\n5.Insert Right\n");
                scanf("%d",&choice);
                switch (choice)
                {
                    case 1: printf("Enter item: ");
                        scanf("%d",&item);
                        head = insert_front(head, item);
                        break;
                    case 2: printf("Enter item: ");
                        scanf("%d",&item);
                        head = insert_rear(head, item);
                        break;
                    case 3: printf("Enter item: ");
                        scanf("%d",&item);
                        printf("Enter Position(Note: Positioning starts from 1): ");
                        scanf("%d",&pos);
                        head = insert_at_pos(head, item, pos);
                        break;
                    case 4: printf("Enter item to be inserted: ");
                        scanf("%d",&item);
                        printf("Enter key element[which element's left you want to insert]: ");
                        scanf("%d",&pos);
                        head = insert_left(head, item, pos);
                        break;
                    case 5: printf("Enter item to be inserted: ");
                        scanf("%d",&item);
                        printf("Enter key element[which element's right you want to insert]: ");
                        scanf("%d",&pos);
                        head = insert_right(head, item, pos);
                        break;
                    default: printf("Ivalid Choice\n");
                }
                break;
            case 2: printf("\n Delete Options\n");
                printf("1.Delete Front\n2.Delete Rear\n3.Delete Info\n4.Delete Left\n5.Delete Right\n");
                scanf("%d",&choice);
                switch (choice)
                {
                    case 1: head = delete_front(head);
                        break;
                    case 2: head = delete_rear(head);
                        break;
                    case 3: printf("Enter item to be deleted: ");
                        scanf("%d",&item);
                        head = delete_info(head, item);
                        break;
                    case 4: printf("Enter item: ");
                        scanf("%d",&item);
                        head = delete_left(head, item);
                        break;
                    case 5: printf("Enter item: ");
                        scanf("%d",&item);
                        head = delete_right(head, item);
                        break;
                    default: printf("Ivalid Choice\n");
                }
                break;
            case 3: printf("Enter the key element : ");
                scanf("%d",&item);
                pos = search(head, item);
                if(pos == 0)
                    printf("Search Unsuccessfull!\n");
                else
                    printf("Search Successfull!\nElement %d found in Location %d\n",item, pos);
                break;
            case 4: display(head);
                break;
            case 5: item = head->info;
                printf("The List contains %d NODEs.\n",item);
                break;
            case 6: printf("Thank You!\n");
                exit(0);
                break;
            default: printf("Ivalid Choice\n");
        }
    }
    return 0;
}