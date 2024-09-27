#include "iostream"
using namespace std;

void custom_merge(int arr[],int low, int mid, int high)
{
    int i = low, j = mid+1,k = 0;
    int new_arr[high-low+1];

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
            new_arr[k++] = arr[i++];
        else
            new_arr[k++] = arr[j++];
    }

    //Copy the remaining elements if left-over.
    while(i <= mid)
        new_arr[k++] = arr[i++];

    while(j <= high)
        new_arr[k++] = arr[j++];

    for(i = low,k=0;i <= high;i++,k++)
        arr[i] = new_arr[k];
}

void merge_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        custom_merge(arr,low,mid,high);
    }
}

void print_arr(int arr[], int n)
{
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {34, 7, 17, 96, 24, 1, 12};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Before Sorting: ";
    print_arr(arr, n);

    merge_sort(arr,0,n-1);
    cout<<"After Sorting: ";
    print_arr(arr, n);
}