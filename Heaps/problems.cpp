#include "iostream"
#include "queue"
#include "vector"

using namespace std;

class Triplet
{
public:
    int value;
    int arr_pos;
    int val_pos;

    Triplet(int value, int arr_pos, int val_pos){
        this->value = value;
        this->arr_pos = arr_pos;
        this->val_pos = val_pos;
    }
};

class Comparator
{
public:
    bool operator() (Triplet &t1, Triplet &t2){
        return t1.value > t2.value;
    }
};

//Merge k sorted arrays.
void merge_k_sorted_arrays(vector<vector<int> > &arr){
    vector<int> res;

    //Create a min heap where each entry is an object of triplet class.
    priority_queue<Triplet, vector<Triplet>, Comparator> pq;

    //Insert 1st elements of all k arrays
    for(int i = 0;i < arr.size();i++){
        //Create an object of Triplet class
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }

    while(!pq.empty()){
        Triplet curr = pq.top();
        pq.pop();

        res.push_back(curr.value);

        // If there is a next element in the same array, push it to the heap
        if (curr.val_pos + 1 < arr[curr.arr_pos].size()) {
            Triplet next(arr[curr.arr_pos][curr.val_pos + 1], curr.arr_pos, curr.val_pos + 1);
            pq.push(next);
        }
    }
    // Output the merged array
    cout << "Merged Array: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

}

//1. 'k' sorted array.
void k_sorted_array(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    int index = 0;

    for(int i = 0; i <= k;i++)
        pq.push(arr[i]);

    for(int i = k + 1;i < n;i++){
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    //Add the remaining elements in the heap.
    while(!pq.empty()){
        arr[index++] = pq.top();
        pq.pop();
    }

    //Print the sorted Array.
    cout<<"Array after sorting is : ";
    for(int i = 0; i < n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

//k closest numbers to a number x
void k_closest_numbers(int arr[], int n, int x, int k)
{
    priority_queue<pair<int, int> > pq;

    for(int i = 0;i < k;i++)
        pq.push(make_pair(abs(arr[i]-x), i));

    for(int i = k;i < n;i++){
        if(pq.top().first > abs(arr[i]-x)){
            pq.pop();
            pq.push(make_pair(abs(arr[i]-x), i));
        }
    }

    cout<<"The "<<k<<" closest numbers to "<<x<<" in the array are: ";

    for(int i = 0;i < k;i++) {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
    cout<<endl;
}

void median_of_stream(int arr[], int n)
{
    //Maintaining 2 containers.
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int> > great;

    small.push(arr[0]);
    cout<<"Medians are: ";
    cout<<arr[0]<<" ";

    for(int i = 1;i < n;i++){
        int cur = arr[i];

        if(small.size() > great.size()) {
            if (cur > small.top())
                //Now peacefully insert te current element into the 2nd container.
                great.push(arr[i]);
            else{
                //The max element in the 1st container needs to be shifted
                great.push(small.top());
                small.pop();
                small.push(arr[i]);
            }

            cout<<(small.top() + great.top()) / 2.0<<" ";
        }
        else{
            if(cur < small.top())
                small.push(arr[i]);
            else{
                great.push(arr[i]);
                small.push(great.top());
                great.pop();
            }
            cout<<small.top()<<" ";
        }
    }
    cout<<endl;

}

int main()
{
    int arr[] = {9, 8, 7, 18, 19, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    k_sorted_array(arr, n, k);
    k_closest_numbers(arr, n, 12, 4);

//    vector<vector<int> > brr = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
//    merge_k_sorted_arrays(brr);

    int crr[] = {12, 15, 10, 5, 8, 7, 16};
    median_of_stream(crr, 7);

    return 0;
}