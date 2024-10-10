#include "iostream"
#include "queue"

using namespace std;

int main()
{
    priority_queue<int> pq;

    pq.push(10);
    pq.push(15);
    pq.push(5);

    cout<<pq.size()<<endl;
    cout<<"Top element -> "<<pq.top()<<endl;
    cout<<"Is Empty? -> "<<pq.empty()<<endl;

    // Removing the top most element ->pop()
    pq.pop();
    cout<<"Removed the top element : "<<endl;

    // Min Heap Priority Queue.
    priority_queue<int, vector<int>, greater<int>> pq2;
    //Priority Queue is built upon Vector.

    pq2.push(10);
    pq2.push(15);
    pq2.push(5);

    cout<<"Min element: "<<pq2.top()<<endl;
    cout<<"Size : "<<pq2.size()<<endl;

    // Creating a priority queue using an array.
    int arr[] = {5, 10, 15};

    priority_queue<int> pq3(arr, arr + 3);

    while (!pq3.empty()){
        cout<<pq3.top()<<" ";
        pq3.pop();
    }
}

/*
 * A Priority Queue is always implemented using Heap data structure.In C++ default priority queue is always a Max Heap.
 * We can also create a priority_queue using Min Heap.
 * Priority queue for pairs -> It will be based on the first element.
 * Applications => Dijkstra's Algorithm, Prims, Huffman, Heap Sort
 */