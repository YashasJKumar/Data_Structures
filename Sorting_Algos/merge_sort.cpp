#include "iostream"
using namespace std;

void merge(int arr[], int brr[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    int crr[m+n];
    while(i < m && j < n)
    {
        if(arr[i] <= brr[j])
            crr[k++] = arr[i++];
        else
            crr[k++] = brr[j++];
    }
    while (i < m)
        crr[k++] = arr[i++];
    while (j < n)
        crr[k++] = brr[j++];
    cout<<"The Array after merging: "<<endl;
    for(i = 0;i<(m+n);i++)
        cout<<crr[i]<<" ";

}

int main()
{
   int arr[] = {10, 15, 20};
   int brr[] = {5, 6, 6, 15};
   merge(arr, brr, 3, 4);
}