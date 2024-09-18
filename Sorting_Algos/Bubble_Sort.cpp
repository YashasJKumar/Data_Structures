#include "iostream"
using namespace std;

void printarr(int arr[], int n)
{
    for(int i = 0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void bubble_sort(int arr[],int n)
{
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0;j < n - 1 - i;j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    }
}

void optimized_bubble_sort(int arr[], int n)
{
    // This utilizes some extra power i.e. when the array is already sorted, or it becomes sorted in btw => STOP
    bool swapped = false;
    for(int i = 0;i < n-1;i++)
    {
        for(int j = 0;j<n-1-i;j++)
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        if(!swapped)
            break;
    }
}

void selection_sort(int arr[], int n)
{
    for(int i = 0; i < n - 1;i++)
    {
        // i -> Exact location where the min element should be placed
        int min = i;
        for(int j = i + 1;j<n;j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}

void insertion_sort(int arr[], int n)
{
    for(int i = 1;i < n;i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}




int main()
{
    int n;
    cout<<"Enter array size : ";
    cin>>n;

    int arr[n];
    cout<<"Enter array Elements: ";
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    //optimized_bubble_sort(arr, n);
    //selection_sort(arr,n);
    insertion_sort(arr, n);
    printarr(arr,n);

}