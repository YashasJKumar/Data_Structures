#include "iostream"
#include "unordered_set"
#include "map"
#include "queue"

using namespace std;

class Node;
typedef Node* node;

class Node
{
private:
    int data;
    Node* left, *right;

    node prev = nullptr, first = nullptr, second = nullptr;

public:

    explicit Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }

    void insert(node &root, int data)
    {
        node temp = new Node(data);
        if(root == nullptr)
        {
            root = temp;
            return;
        }
        node cur = root, prev = nullptr;
        while( cur != nullptr)
        {
            prev = cur;
            if(data == cur->data)
            {
                cout<<"Duplicate Elements are not allowed."<<endl;
                delete temp;
            }
            if(data < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if(data < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }

    node insert_recursive(node root, int data)
    {
        if(root == nullptr)
            return new Node(data);
        else if(data < root->data)
            root->left = insert_recursive(root->left, data);
        else if(data > root->data)
            root->right = insert_recursive(root->right, data);
        return root;
    }

    bool search(node &root, int key)
    {
        if(root == nullptr)
            return false;
        node cur = root;
        while(cur != nullptr)
        {
            if(cur->data == key)
                return true;
            else if(key < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return false;
    }

    bool search_recursive(node root, int key)
    {
        // This takes O(h) auxiliary space.
        if(root == nullptr)
            return false;
        else if(key == root->data)
            return true;
        else if(key < root->data)
            return search_recursive(root->left, key);
        else
            return search_recursive(root->right, key);
    }

    node get_successor(node &root)
    {
        if(root == nullptr)
            return nullptr;
        node cur = root->right;
        // Note : This function doesn't provide the inorder successor all the time.
        // Works only when right sub-tree is not empty.
        while(cur != nullptr && cur->left != nullptr)
            cur = cur->left;
        return cur;
    }

    node delete_node(node &root, int key)
    {
        if(root == nullptr)
            return nullptr;
        else if(key < root->data)
            root->left = delete_node(root->left, key);
        else if(key > root->data)
            root->right = delete_node(root->right, key);
        else{
            if(root->left == nullptr)
            {
                node temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr)
            {
                node temp = root->left;
                delete root;
                return temp;
            }
            else{
                node temp = get_successor(root);
                root->data = temp->data;
                root->right = delete_node(root->right, temp->data);
            }
        }
        return root;
    }

    int floor_value(node &root, int key)
    {
        if(root == nullptr)
            return -1;
        node result = nullptr;
        node cur = root;
        while(cur != nullptr)
        {
            if(cur->data == key)
                return cur->data;
            else if(key < cur->data)
                cur = cur->left;
            else{
                result = cur;
                cur = cur->right;
            }
        }
        return result->data;
    }

    int ceil_value(node &root, int key)
    {
        if(root == nullptr)
            return -1;
        node cur = root, result = nullptr;
        while(cur != nullptr)
        {
            if(cur->data == key)
                return key;
            else if(key > cur->data)
                cur = cur->right;
            else{
                result = cur;
                cur = cur->left;
            }
        }
        return result->data;
    }

    void preorder(node &root)
    {
        if(root == nullptr)
            return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(node &root)
    {
        if(root == nullptr)
            return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void postorder(node &root)
    {
        if(root == nullptr)
            return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    int prev_node_value;

    inline void prev_resetter()
    {
        prev_node_value = INT_MIN;
    }

    bool isBST2(node &root, int min, int max)
    {
        if(root == nullptr)
            return true;
        return (
                root->data > min && root->data < max && isBST2(root->left, min, root->data)
                && isBST2(root->right, root->data, max)
                );
    }

    bool isBST(node &root)
    {
        if(root == nullptr)
            return true;  //Empty tree is always a BST.
        if(!isBST(root->left))
            return false;
        if(root->data < prev_node_value)
            return false;
        prev_node_value = root->data;
        return isBST(root->right);
    }

    void fix_BST(node &root)
    {
        if(root == nullptr)
            return;
        fix_BST(root->left); // To do inorder traversal.

        if(prev != nullptr && root->data < prev->data){
            if(first == nullptr)
                first = prev;
            second = root;
        }
        prev = root;
        fix_BST(root->right);
        //After this function executes completely -> your first & second will be exactly pointing to the nodes violating.
    }

    bool pair_sum(node &root, int sum, unordered_set<int> &s)
    {
        if(root == nullptr)
            return false;
        if(pair_sum(root->left, sum, s))
            return true;
        if(s.find(sum - root->data) != s.end())
            return true;
        else
            s.insert(root->data);
        return pair_sum(root->right, sum, s);
    }

    void vSum(node &root, map<int, int> &m, int horizontal_dist)
    {
        if(root == nullptr)
            return;
        //Can use any traversals.
        vSum(root->left, m, horizontal_dist-1);
        m[horizontal_dist] += root->data;
        vSum(root->right, m, horizontal_dist+1);
    }

    void vertical_sum(node &root)
    {
        map<int,int> m;
        vSum(root, m, 0);

        cout<<"The Vertical Sum of the Tree: "<<endl;
        for(auto it : m)
            cout<<it.second<<" ";

        cout<<endl;
    }

    void vertical_traversal(node &root)
    {
        map<int, vector<int> > m;
        queue<pair<node, int> > q;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<node, int> temp = q.front();
            q.pop();

            int hd = temp.second;
            node cur = temp.first;
            m[hd].push_back(cur->data);

            if(cur->left != nullptr)
                q.push(make_pair(cur->left, hd-1));
            if(cur->right != nullptr)
                q.push(make_pair(cur->right, hd+1));
        }

        //Traverse the Map & print
        cout<<"The Vertical Traversal of Tree is : "<<endl;
        for(auto x : m) {
            for (int y : x.second)
                cout << y << " ";
            cout << endl;
        }

    }

    void top_view_of_tree(node &root)
    {
        // Same for Binary Tree & BST.
        if(root == nullptr)
            return;

        map<int, int> m;
        queue<pair<node, int> > q;
        q.push(make_pair(root, 0));

        while(!q.empty())
        {
            pair<node, int> temp = q.front();
            q.pop();

            int hd = temp.second;
            node cur = temp.first;

            if(m.find(hd) == m.end())
                m[hd] = cur->data;

            if(cur->left != nullptr)
                q.push(make_pair(cur->left, hd-1));
            if(cur->right != nullptr)
                q.push(make_pair(cur->right, hd+1));
        }

        cout<<"The Top View of the Tree : "<<endl;
        for(auto x : m)
                cout<<x.second<<" ";

        cout<<endl;
    }

    void bottom_view_of_tree(node &root)
    {
        // Same for Binary Tree & BST.
        if(root == nullptr)
            return;

        map<int, int> m;
        queue<pair<node, int> > q;
        q.push(make_pair(root, 0));

        while(!q.empty())
        {
            pair<node, int> temp = q.front();
            q.pop();

            int hd = temp.second;
            node cur = temp.first;

            m[hd] = cur->data;  //Override if key already exists else insert it

            if(cur->left != nullptr)
                q.push(make_pair(cur->left, hd-1));
            if(cur->right != nullptr)
                q.push(make_pair(cur->right, hd+1));
        }

        cout<<"The Bottom View of the Tree : "<<endl;
        for(auto x : m)
            cout<<x.second<<" ";

        cout<<endl;
    }


};

int main()
{
    node root = nullptr;
    int item,ch1,ch2;
    cout<<"--------- Binary Search Tree --------"<<endl;
    cout<<boolalpha;  //Inverts the default behaviour of bool
    while(true)
    {
        cout<<"\n---------Menu--------\n1.Insert\n2.Delete\n3.Display\n4.Extra\n5.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch1;
        switch (ch1)
        {
            case 1: cout<<"\n1.Insert Iterative\n2.Insert Recursive"<<endl;
                cin>>ch2;
                switch(ch2)
                {
                    case 1: cout<<"Enter item to be inserted: ";
                        cin>>item;
                        root->insert(root, item);
                        break;
                    case 2: cout<<"Enter item to be inserted: ";
                        cin>>item;
                        root->insert_recursive(root, item);
                        break;
                    default: cout<<"Invalid choice\n";
                        break;
                }
                break;
            case 2: cout<<"Enter the item to be deleted : "<<endl;
                    cin>>item;
                    root = root->delete_node(root, item);
                    cout<<item<<" deleted successfully!"<<endl;
                    break;
            case 3: cout<<"\n1.Inorder Traversal\n2.Preorder Traversal\n3.Postorder Traversal"<<endl;
                cin>>ch2;
                switch(ch2)
                {
                    case 1: root->inorder(root);
                        break;
                    case 2: root->preorder(root);
                        break;
                    case 3: root->postorder(root);
                        break;
                    default: cout<<"Invalid choice\n";
                        break;
                }
                break;

            case 4: cout<<"\n1.Search(Recursive)\n2.Search(Iterative)\n3.Floor Value\n4.Ceil Value\n5.Check for BST\n6.Vertical Sum"<<endl;
                cin>>ch2;
                if(ch2 != 5 && ch2 != 6) {
                    cout << "Enter key element: ";
                    cin >> item;
                }
                switch(ch2)
                {
                    case 1: cout<<item<<" is present in the Tree. -> "<<root->search_recursive(root, item)<<endl;
                        break;
                    case 2: cout<<item<<" is present in the Tree. -> "<<root->search(root, item)<<endl;
                        break;
                    case 3: item = root->floor_value(root, item);
                            item == -1 ? cout<<"Floor value does'nt exist"<<endl : cout<<"Floor value = "<<item<<endl;
                        break;
                    case 4: item = root->ceil_value(root, item);
                        item == -1 ? cout<<"Ceil value does'nt exist"<<endl : cout<<"Ceil value = "<<item<<endl;
                        break;
                    case 5: root->prev_resetter();
                        root->isBST(root) ? cout<<"The Tree is a BST."<<endl : cout<<"Not a BST."<<endl;
                        break;
                    case 6: root->vertical_sum(root);
                        break;
                    default: cout<<"Invalid choice\n";
                        break;
                }
                break;
            case 5: cout<<"\n------Thank You!------"<<endl;
                exit(0);
            default: cout<<"Invalid choice\n";
                break;
        }
    }
    return 0;
}
