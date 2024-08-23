#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE new_node;
    new_node = (NODE) malloc(sizeof(NODE));
    if(new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    return new_node;
}

int no_of_items(NODE first) //HELPER FUNCTION FOR ADDITION OF LISTS
{
    NODE cur;
    int count = 0;
    if(first == NULL)
        return 0;
    cur = first;
    while(cur != NULL)
    {
        cur = cur -> link;
        count++;
    }
    return count;
}

NODE display(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    temp = first;
    printf("The List Contains : \n");
    while(temp->link != NULL)
    {
        printf("%d->",temp->info);
        temp = temp->link;
    }
    printf("%d\n",temp->info);
    return first;
}
NODE insert_front(NODE first, int item)
{
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if(first == NULL)
    {
        return temp;
    }
    else
    {
        temp->link = first;
        first = temp;
        return first;
    }
}
NODE insert_rear(NODE first, int item)
{
    NODE temp,cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if(first == NULL)
    {
        return temp;
    }
    else
    {
        cur = first;
        while(cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = temp;
        return first;
    }
}
NODE delete_front(NODE first)
{
    NODE temp;
    temp = first;
    if(first == NULL)
    {
        printf("List Empty!\n");
        return NULL;
    }
    else
    {
        first = first->link;
        printf("Deleted Info = %d\n",temp->info);
        free(temp);
        return first;
    }
}

NODE delete_rear(NODE first)
{
    NODE prev,cur;
    if(first == NULL)
    {
        printf("List Empty!\n");
        return NULL;
    }
    else
    {
        cur = first;
        prev = NULL;
        while(cur->link!=NULL)
        {
            prev = cur;
            cur = cur->link;
        }
        printf("The Deleted Element is : %d\n",cur->info);
        free(cur);
        if(prev != NULL)
            prev->link = NULL;
        return first;
    }
}

NODE insert_at_index(NODE first,int item, int index)
{
    // 0 based indexing is followed.
    NODE temp,cur,prev;
    temp = getnode();
    temp->info = item;
    if(index<0 || index > no_of_items(first))
    {
        printf("Invalid Index\n");
        return first;
    }
    if(index == 0)
    {
        temp->link = first;
        return temp;
    }
    else
    {
        cur = first;
        prev = NULL;
        int count = 0;
        while(count < index)
        {
            prev = cur;
            cur = cur->link;
            count++;
        }
        temp->link = cur;
        prev->link = temp;
        return first;
    }
}
NODE insert_left(NODE first, int item, int info)
{
    NODE temp,cur,prev;
    if(first == NULL)
    {
        printf("List Empty!\n");
        return first;
    }
    else
    {
        cur = first;
        prev = NULL;
        while(cur != NULL)
        {
            if(cur->info == info)
                break;
            prev = cur;
            cur = cur->link;
        }
        if(cur == NULL)
        {
            printf("Item Not Found\n");
            return first;
        }
        temp = getnode();
        temp->info = item;
        temp->link = NULL;
        if(prev == NULL)
            first = temp;
        else
            prev->link = temp;
        temp->link = cur;
    }
    return first;
}

NODE insert_right(NODE first,  int item, int info)
{
    NODE temp,cur;
    if(first == NULL)
    {
        printf("List Empty!\n");
        return first;
    }
    else
    {
        cur = first;
        while(cur != NULL)
        {
            if(cur->info == info)
                break;
            cur = cur->link;
        }
        if(cur == NULL)
        {
            printf("Item Not Found\n");
            return first;
        }
        temp = getnode();
        temp->info = item;
        temp->link = cur->link;
        cur->link = temp;
    }
    return first;
}

NODE delete_pos(NODE first, int pos)
{
    NODE cur, prev;
    int count = 1;
    if(first == NULL || pos <= 0)
    {
        printf("Invalid Position. Deletion not possible\n");
        return first;
    }
    if(pos == 1)
    {
        cur = first;
        printf("Deleted Element is: %d\n",cur -> info);
        first = first -> link;
        free(cur);
    }
    cur = first;
    while(cur != NULL)
    {
        if(count == pos)
            break;
        prev = cur;
        cur = cur -> link;
        count++;
    }
    if(cur == NULL)
    {
        printf("Invalid Position. Deletion not possible\n");
        return first;
    }
    printf("The Deleted Element is : %d\n",cur->info);
    prev -> link = cur -> link;
    free(cur);
    cur = NULL;
    return first;
}
NODE delete_right(NODE first, int pos)
{
    NODE cur, next;
    int count = 1;
    if(first == NULL || pos <= 0)
    {
        printf("Invalid Position. Deletion not possible\n");
        return first;
    }
    if(first-> link == NULL && pos == 1)
    {
        printf("Deletion not possible !\n");
        return first;
    }
    cur = first;
    while (cur != NULL)
    {
        if(count == pos)
            break;
        cur = cur->link;
        count++;
    }
    if(cur == NULL)
    {
        printf("Deletion Not Possible. Invalid Position\n");
        return first;
    }
    next = cur->link;
    cur -> link = next -> link;
    printf("The Deleted Element is %d\n",next->info);
    free(next);
    next = NULL;
    return first;
}

NODE delete_left(NODE first, int pos)
{
    NODE cur, prev;
    int count = 1;
    if(first == NULL || pos <= 1)
    {
        printf("Invalid Position. Deletion not possible\n");
        return first;
    }
    if(pos == 2)
    {
        printf("The Deleted Element is :%d\n",first->info);
        cur = first;
        first = first->link;
        free(cur);
        cur = NULL;
        return first;
    }
    cur = first;
    while (cur != NULL)
    {
        if(count == pos - 1)
            break;
        prev = cur;
        cur = cur->link;
        count++;
    }
    if(cur == NULL)
    {
        printf("Deletion Not Possible. Invalid Position\n");
        return first;
    }
    prev->link = cur->link;
    printf("The Deleted Element is : %d\n",cur->info);
    free(cur);
    cur = NULL;
    return first;
}
NODE delete_info(NODE first, int info)
{
    NODE cur, prev;
    if(first == NULL)
    {
        printf("List Empty!\n");
        return first;
    }
    if(info == first->info)
    {
        cur = first;
        printf("The Deleted Element is : %d\n",cur->info);
        first = first->link;
        free(cur);
        cur = NULL;
        return first;
    }
    prev = NULL;
    cur = first;
    while(cur != NULL)
    {
        if(info == cur->info)
            break;
        prev = cur;
        cur = cur->link;
    }
    if(cur == NULL)
    {
        printf("Deletion Not Possible! Element not found\n");
        return first;
    }
    prev->link = cur->link;
    printf("The Deleted Element is : %d\n",cur->info);
    free(cur);
    cur = NULL;
    return first;
}
NODE reverse_specific(NODE first,int pos)
{
    NODE cur,prev,next,second_half;
    NODE s[20];
    int top = -1;
    cur = first;
    while(cur != NULL)
    {
        if(pos == cur->info)
            break;
        s[++top] = cur;
        cur = cur->link;
    }
    first = cur;
    cur = cur -> link;
    prev = NULL;
    while(cur != NULL)
    {
        next = cur -> link;
        cur -> link = prev;
        prev = cur;
        cur = next;
    }
    first -> link = s[top];
    while(top != -1)
    {
        cur = s[top];
        if(top != 0)
            cur->link = s[--top];
    }
    cur -> link = prev;
    return first;
}

int search(NODE first, int key)
{
    NODE cur;
    if(first == NULL)
    {
        printf("List Empty!\n");
        return 0;
    }
    cur = first;
    while(cur != NULL)
    {
        if(key == cur->info)
        {
            return 1;
        }
        cur = cur->link;
    }
    return 0;
}

NODE reverse(NODE first)
{
    NODE prev,cur,next;
    if(first == NULL)
    {
        printf("List Empty!\n");
        return first;
    }
    prev = NULL;
    cur = first;
    while(cur != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    first = prev;
    return first;
}

NODE anti_clockwise_rotate(NODE first, int key)
{
    NODE prev_first,cur;
    int count = 1;
    if(first == NULL || key<=0)
    {
        printf("List Empty! or Operation not possible\n");
        return first;
    }
    if(first->link == NULL)
    {
        printf("Need atleast 2 nodes to perform this operation!\n");
        return first;
    }
    prev_first = first;
    cur = first;
    while(cur!=NULL)
    {
        if(count == key)
            break;
        cur = cur->link;
        count++;
    }
    if(cur == NULL)
    {
        printf("Key not found!");
        return first;
    }
    first = cur->link;
    cur->link = NULL;
    cur = first;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = prev_first;
    printf("Anti-Clockwise Rotation Successful!\n");
    return first;
}

NODE clockwise_rotate(NODE first, int key)
{
    NODE prev,cur;
    int count = 1;
    if(first == NULL || key<=0)
    {
        printf("List Empty!\n");
        return first;
    }
    if(first->link == NULL)
    {
        printf("Need atleast 2 nodes to perform this operation!\n");
        return first;
    }
    cur = first;
    while(cur!=NULL)
    {
        if(key == count)
            break;
        prev = cur;
        cur = cur->link;
        count++;
    }
    if(cur == NULL)
    {
        printf("Key not found!");
        return first;
    }
    prev->link = NULL;
    prev = first;
    first = cur;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = prev;
    printf("Clockwise Rotation Successfull!\n");
    return first;
}

NODE sort(NODE first)
{
    NODE cur, next;
    int temp;
    if(first == NULL || first->link == NULL)
    {
        printf("There must be atleast 2 elements to Sort\n");
        return first;
    }
    cur = first;
    while(cur->link!=NULL)
    {
        next = cur ->link;
        while(next != NULL)
        {
            if(cur -> info > next ->info)
            {
                temp = cur -> info;
                cur -> info = next ->info;
                next -> info = temp;
            }
            next = next->link;
        }
        cur = cur->link;
    }
    return first;
}
NODE descending_order(NODE first)
{
    if(first == NULL || first->link == NULL)
    {
        printf("There must be atleast 2 elements to Sort\n");
        return first;
    }
    first = sort(first);
    first = reverse(first);
    return first;
}
NODE union_of_lists(NODE first, NODE second)
{
    NODE a,third;
    int flag;
    a = first;
    third = NULL;
    while(a!=NULL)
    {
        third = insert_rear(third, a->info);
        a = a->link;
    }
    a = second;
    while(a!=NULL)
    {
        flag = search(third,a->info);
        if(flag == 0)
            third = insert_rear(third, a->info);
        a = a->link;
    }
    return third;
}
NODE intersection_of_lists(NODE first, NODE second)
{
    NODE a,b,third;
    int flag;
    a = first;
    b = second;
    third = NULL;
    while(a!=NULL)
    {
        flag = search(second,a->info);
        if(flag == 1)
            third = insert_rear(third, a->info);
        a = a->link;
    }
    return third;
}
NODE addition_of_lists(NODE first,NODE second)
{
    NODE cur1, cur2,third;
    cur1 = reverse(first);
    cur2 = reverse(second);
    third = NULL;
    int sum, carry = 0;
    while(cur1!=NULL || cur2!=NULL)
    {
        sum = 0;
        if(cur1!=NULL)
        {
            sum += cur1->info;
            cur1 = cur1 -> link;
        }
        if(cur2 != NULL)
        {
            sum += cur2->info;
            cur2 = cur2 ->link;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        third = insert_rear(third,sum);
    }
    if(carry != 0)
        third = insert_rear(third,carry);
    third = reverse(third);
    return third;
}


bool check_loop(NODE first)
{
    // Tortoise - Hare Algorithm or Floyd's Cycle Finding Algorithm.
    if(first == NULL || first->link == NULL)
        return false;
    NODE slow, fast;
    slow = fast = first;

    //Keep in mind the case where there is no loop because your pointers must not go out of bound.
    while (slow && fast && fast->link)
    {
        //We need to check fast->link != NULL because fast moves 2 steps at a time.
        slow = slow->link;
        fast = fast->link->link;

        if(slow == fast)
            return true;
    }
    return false;

    //Alternative Approach -> Store the node addresses in a hash table.Then if a certain address is already present in the table.Return true
}

int main()
{
    int choice, item, pos, n;
    NODE first = NULL, second = NULL,third = NULL;
    printf("Enter number of nodes in the List1 : ");
    scanf("%d",&n);
    printf("Enter the elements of List1: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &item);
        first = insert_rear(first,item);
    }
    printf("Enter number of nodes in the List2 : ");
    scanf("%d",&n);
    printf("Enter the elements of List2: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &item);
        second = insert_rear(second,item);
    }
    for(;;)
    {
        printf("\n-------Singly Linked List-------\n");
        printf("1.Insert Front\n2.Insert Rear\n3.Insert Left\n4.Insert Right\n5.Insert at Index\n6.Delete Front\n");
        printf("7.Delete Rear\n8.Display\n9.Reverse\n10.Anti-Clockwise Rotate\n11.Clockwise Rotation\n12.Sort\n13.Sort(Descending)");
        printf("\n14.Delete left\n15.Delete Right\n16.Delete Position\n17.Delete Info\n18.Search");
        printf("\n19.Union of 2 Lists\n20.Intersection of 2 Lists\n21.Addition of 2 Lists\n22.Check no. of nodes");
        printf("\n23.Reverse Specific\n24.Exit");
        printf("\nPlease Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter element to be inserted : ");
                scanf("%d",&item);
                first = insert_front(first, item);
                break;
            case 2: printf("Enter element to be inserted : ");
                scanf("%d",&item);
                first = insert_rear(first, item);
                break;
            case 3: printf("Enter element to be inserted : ");
                scanf("%d",&item);
                printf("Enter the Position : ");
                scanf("%d",&pos);
                first = insert_left(first, item, pos);
                break;
            case 4: printf("Enter element to be inserted: ");
                scanf("%d",&item);
                printf("Enter the Position : ");
                scanf("%d",&pos);
                first = insert_right(first, item, pos);
                break;
            case 5: printf("Enter element to be inserted: ");
                scanf("%d",&item);
                printf("Enter the Index : {Note:Index starts from 0}");
                scanf("%d",&pos);
                first = insert_at_index(first, item, pos);
                break;
            case 6: first = delete_front(first);
                break;
            case 7: first = delete_rear(first);
                break;
            case 8: first = display(first);
                break;
            case 9: first = reverse(first);
                break;
            case 10: printf("Enter the Position at which you want to rotate in anti-clockwise direction: ");
                scanf("%d",&pos);
                first = anti_clockwise_rotate(first, pos);
                break;
            case 11: printf("Enter the Position at which you want to rotate in Clockwise direction: ");
                scanf("%d",&pos);
                first = clockwise_rotate(first, pos);
                break;
            case 12: first = sort(first);
                display(first);
                break;
            case 13: first = descending_order(first);
                display(first);
                break;
            case 14: printf("Enter the Position: (Not Index)");
                scanf("%d",&pos);
                first = delete_left(first, pos);
                break;
            case 15: printf("Enter the Position: (Not Index)");
                scanf("%d",&pos);
                first = delete_right(first, pos);
                break;
            case 16: printf("Enter the Position: (Not Index)");
                scanf("%d",&pos);
                first = delete_pos(first, pos);
                break;
            case 17: printf("Enter the element to be Deleted: ");
                scanf("%d",&pos);
                first = delete_info(first, pos);
                break;
            case 18: printf("Enter the key Elelement: ");
                scanf("%d",&pos);
                pos = search(first, pos);
                break;
            case 19: third = NULL;
                third = union_of_lists(first, second);
                display(third);
                break;
            case 20: third = NULL;
                third = intersection_of_lists(first, second);
                display(third);
                break;
            case 21: third = NULL;
                third = addition_of_lists(first, second);
                display(third);
                break;
            case 22: item = no_of_items(first);
                printf("The List contains %d nodes\n",item);
                break;
            case 23: printf("Enter the element at which you want to reverse: ");
                scanf("%d",&pos);
                first = reverse_specific(first,pos);
                break;
            case 24: printf("Thank You!\n");
                exit(-1);
                break;
            default: printf("Please Enter the correct option\n");
        }
    }
    return 0;
}