#include "iostream"
#include "algorithm"
using namespace std;

int lomuto_partition(int arr[], int l, int r){
    //Last element is the pivot
    int pivot = arr[r];
    int i = l-1; //Before beginning

    for(int j = l;j <= r-1;j++)
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }

    swap(arr[i+1], arr[r]); //Placing pivot to its right position
    return i+1;
}

int hoares_partition(int arr[], int l, int r){
    int pivot = arr[l];

    int i = l-1, j = r+1;

    while(true){
        do{
            i++;
        } while (arr[i] < pivot);

        do{
            j--;
        } while (arr[j] > pivot);

        if(i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quick_sort_using_lomuto_partition(int arr[], int l, int r){
    if(l < r){
        int partition = lomuto_partition(arr, l, r);
        quick_sort_using_lomuto_partition(arr, l, partition-1);
        quick_sort_using_lomuto_partition(arr, partition+1, r);
    }
}

void quick_sort_using_hoares_partition(int arr[], int l, int r){
    if(l < r){
        int partition = hoares_partition(arr, l, r);
        quick_sort_using_hoares_partition(arr, l, partition);
        quick_sort_using_hoares_partition(arr, partition+1, r);
    }
}

void print_arr(int arr[], int n){
    cout<<"The Array contains: ";
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}


int main()
{
    int arr1[] = {34, 23, 5, 65, 1, 0, -3};
    int n = 7;
    print_arr(arr1, n);

    int arr2[n];
    copy(arr1, arr1+n, arr2);

    cout<<"Lomuto "<<endl;
    quick_sort_using_lomuto_partition(arr1, 0, n-1);
    print_arr(arr1,n);

    cout<<"Hoare's"<<endl;
    quick_sort_using_hoares_partition(arr2, 0, n-1);
    print_arr(arr2, n);
}
