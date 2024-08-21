#include "iostream"
#include "algorithm"

using namespace std;

typedef struct Demo{
    int a,b;
}demo;

bool my_own_comparator(demo a1, demo a2)
{
    return a1.a < a2.a;
}

int main()
{
    int arr[] = {10,5,6,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n);  // Intra Sort
    for(int x : arr)
        cout<<x<<" ";
    sort(arr, arr+n, greater<int>());
    // greater() => General purpose comparative function which generally reverses the array.
    cout<<endl;
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
    demo brr[] = {{2,5}, {3,7}, {1,0}};
    int n2 = sizeof(brr)/sizeof(brr[0]);
    sort(brr, brr+n2, my_own_comparator);
    for(auto itr : brr)
        cout<<itr.a<<" "<<itr.b<<endl;
}