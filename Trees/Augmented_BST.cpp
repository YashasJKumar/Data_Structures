#include <iostream>
#include "queue"

using namespace std;

class Node;
typedef Node* node;

class Node
{
public:
    int data, lcount;  // Changed to public for access from outside functions
    node left, right;

    explicit Node(int data)
    {
        this->data = data;
        lcount = 0;
        left = right = nullptr;
    }
};

// Function to insert a new node into the tree
void insert(node& root, int data)
{
    node new_node = new Node(data);
    if (root == nullptr)
    {
        root = new_node;
        return;
    }

    node cur = root, prev = nullptr;

    while (cur != nullptr)
    {
        prev = cur;

        // Check for duplicates
        if (cur->data == data)
        {
            cout << "Duplicates are not allowed." << endl;
            delete new_node;
            return;
        }
        else if (data < cur->data)
        {
            cur->lcount++;  // Increment left subtree count
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }

    // Insert the new node at the correct position
    if (data > prev->data)
    {
        prev->right = new_node;
    }
    else
        prev->left = new_node;
}

// Function to find the k-th smallest element in the tree
node kth_smallest_element(node root, int k)
{
    if (root == nullptr)
        return nullptr;

    // If the current node is the k-th smallest
    if (root->lcount + 1 == k)
        return root;

        // Recur on the left subtree if k-th smallest lies there
    else if (root->lcount + 1 > k)
        return kth_smallest_element(root->left, k);

        // Else recur on the right subtree, adjusting k
    else
        return kth_smallest_element(root->right, k - (root->lcount + 1));
}

// Wrapper function to return the k-th smallest element's data
int get_k_th_smallest(node root, int k)
{
    node result = kth_smallest_element(root, k);
    if (result == nullptr)
        return -1;  // Return -1 if not found or invalid k
    return result->data;
}

void level_order_traversal(node& root)
{
    if(root == nullptr)
    {
        cout<<"Tree is Empty!"<<endl;
        return;
    }
    queue<node> q;
    q.push(root);
    cout<<"The Tree contains: "<<endl;
    while(!q.empty())
    {
        node temp = q.front();
        if(temp->left != nullptr)
            q.push(temp->left);
        if(temp->right != nullptr)
            q.push(temp->right);
        q.pop();
        cout<<temp->data<<" ";
    }
    cout<<endl;
}

int main()
{
    node root = nullptr;

    int arr[] = {50, 20, 100, 10, 40, 70, 120, 4, 60, 80};
    for (int i : arr)
        insert(root, i);

    level_order_traversal(root);
    cout << "2nd smallest element: " << get_k_th_smallest(root, 2) << endl;
    cout<<root->lcount<<endl;

    return 0;
}