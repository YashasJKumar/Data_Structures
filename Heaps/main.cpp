#include<iostream>
using namespace std;

class MinHeap
{
public:
    int *arr;
    int size;
    int capacity;

    MinHeap(int capacity)
    {
        arr = (int *)malloc(capacity*sizeof(int));
        this->capacity = capacity;
        size=0;
    }

    int parent(int node)
    {
        return floor((node - 1) / 2);
    }

    int leftchild(int node)
    {
        return 2*node + 1;
    }

    int rightchild(int node)
    {
        return 2 * node + 2;
    }
    
    void insert(int x)
    {
        if (size == capacity)
            return;
        size++;
        arr[size-1] = x;
        for (int i = size-1; i != 0 && arr[parent(i)] > arr[i];)
        {
            //Swap parent & child.
            int temp = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = temp;
            // Update i to check the next upper parent.
            i = parent(i);
        }
    }

    void min_heapify(int node)
    {
        //Assumes only root node is viuolating min_heap property
        int left = leftchild(node),right = rightchild(node);
        int smallest = node;
        if(left < size && arr[left] < arr[node])
            smallest = left;
        if(right < size && arr[right] < arr[node])
            smallest = right;
        if (smallest != node)
        {
            //Swap
            int temp = node;
            node = smallest;
            smallest = temp;
            min_heapify(smallest);
        }
    }

    void max_heapify(int brr[],int n, int i)
    {
        int largest = i;
        int left = leftchild(i), right = rightchild(i);
        if(left < n && brr[left] > brr[largest])
            largest = left;
        if(right < n && brr[right] > brr[largest])
            largest = right;

        if(largest != i)
        {
            //Then it's not a max heap
            swap(brr[largest],brr[i]);
            max_heapify(brr, n, largest);
        }
    }

    int extract_min()
    {
        if (size == 0)
            //Empty Heap
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
            //This case is handled explicitly bcoz we call heapify() at the end.
        }
        swap(arr[0],arr[size-1]);
        size--;
        min_heapify(0);
        return arr[size]; //size bcoz now size = size-1
    }

    void decrease_key(int index,int value)
    {
        if(size == 0)
            return;
        //Remove
        arr[index] = value;
        while(index != 0 && arr[parent(index)] > arr[index])
        {
            swap(arr[index], arr[parent(index)]);
            index = parent(index);
        }
    }

    void delete_node(int index)
    {
        if(index == 0)
            extract_min();
        else{
            decrease_key(index, INT_MIN);
            extract_min();
        }
    }

    void build_max_heap(int brr[], int n)
    {
        for(int i = (n - 2)/2;i >= 0;i--)
            max_heapify(brr,n,i);
    }

    void heap_sort(int brr[], int n)
    {
        build_max_heap(brr,n);
        for(int i = n - 1;i >= 1;i--)
        {
            swap(brr[0],brr[i]);
            max_heapify(brr,i,0);
        }
    }

    void display()
    {
        cout<<"The Heap represented in an array is: \n";
        for(int i = 0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

};

int main()
{
    MinHeap h = MinHeap(7);
    h.insert(10);
    h.insert(2);
    h.display();
    h.delete_node(1);
    h.display();
    cout<<"Heap Sort: ";
    cout<<"\nEnter array size: ";
    int n;
    cin>>n;
    int brr[n];
    cout<<"Enter array elements: "<<endl;
    for(int i = 0;i<n;i++)
        cin>>brr[i];
    h.heap_sort(brr,n);
    cout<<"The Elements after sorting is: "<<endl;
    for(int x: brr)
        cout<<x<<" ";
    cout<<endl;
}
