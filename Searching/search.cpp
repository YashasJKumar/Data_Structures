#include "iostream"
using namespace std;

int *read_array(int *arr, int n)
{
    arr = (int *) malloc(n * sizeof(int));
    cout<<"Enter Array Elements: "<<endl;
    for(int i = 0; i < n;i++)
        cin>>*(arr+i);
    return arr;
}

bool linear_search(const int arr[], int n, int key)
{
    for(int i = 0; i < n;i++)
        if(arr[i] == key)
            return true;
    return false;
}

int binary_search(const int arr[], int n,int key)
{
    //This search assumes that the array is sorted.
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(key > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int recursive_bs(const int arr[], int n, int key, int low, int high)
{
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == key)
        return mid;
    else if(key < arr[mid])
        return recursive_bs(arr,n, key, low, mid - 1);
    else
        return recursive_bs(arr, n, key, mid + 1, high);

}

int first_occurrence(int arr[], int key, int low, int high)
{
    if(low > high)
        return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == key)
    {
        //Check whether it is first occurrence or not.
        if(mid == 0 || (arr[mid] != arr[mid-1]))  //Short Circuit Approach.
            return mid;
        else
            return first_occurrence(arr, key, low, mid-1);
    }
    else if(key > arr[mid])
        return first_occurrence(arr, key, mid + 1,high);
    else
        return first_occurrence(arr,key,low,mid - 1);
}

int last_occurence(const int arr[], int n, int key)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
        {
            if(mid == n-1 || (arr[mid] != arr[mid+1]))
                return mid;
            else
                low = mid + 1;
        } else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int count_no_of_occurrences(int arr[], int n, int key)
{
    //Sorted Array only!
    int first_index = first_occurrence(arr,key,0,n-1);
    if(first_index == -1)
        return 0;
    return last_occurence(arr,n,key) - first_index + 1;
}

int count_of_ones(int brr[], int n)
{
    int low = 0, high = n - 1, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(brr[mid] == 0)
            low = mid + 1;
        else{
            if(mid == 0 || brr[mid-1] != 1)
                break;
            else
                high = mid - 1;
        }
    }
    if(low > high)
        return 0;
    return n - mid;
}

int naive_square_root(int x)
{
    int i = 1;
    while(i*i < x)
        i++;
    return i - 1;
    //Return floor value for not exact square no's.
}

int eff_square_root(int x)
{
    int low = 1,high = x,ans = 0;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int mid_sqr = mid * mid;
        if(mid_sqr == x)
            return mid;
        else if(mid_sqr > x)
            high = mid - 1;
        else{
            low = mid + 1;  //To find even more better answer if present.
            ans = mid;
        }
    }
    return ans;
}

int search_sorted_rotated(int arr[], int n, int key)
{
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        // Check which part of the array is sorted.
        if(arr[mid] == key)
            return mid;
        if(arr[mid] > arr[0])
        {
            //Left Half ✅
            if(key >= arr[low] && key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            if(key > arr[mid] && key < arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int peak_element(int arr[], int n)
{
    //Return only 1 element if there are more answers.
    int low = 0, high = n - 1, ans = arr[0];
    if(n == 1)
        return ans;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(mid == 0)
        {
            if(arr[mid] > arr[mid + 1])
                return arr[mid];
            return arr[mid + 1];
        }
        else if(mid == n - 1)
        {
            if(arr[mid] > arr[mid - 1])
                return arr[mid];
            return arr[mid - 1];
        }
        if(max(arr[mid-1], max(arr[mid], arr[mid + 1])) == arr[mid])
            return arr[mid];
        else if(arr[mid + 1] <= arr[mid - 1])
            //This means that the left sub-array contains the peak element. Every independent array has atleast 1 peak element.
            high = mid - 1;
        else
            low = mid + 1;
    }
    // Never reaches.
    return ans;
}

bool two_pointer(int arr[], int n, int x)
{
    int i = 0, j = n-1;
    while(i < j)
    {
        if(arr[i] + arr[j] == x)
            return true;
        else if(arr[i] + arr[j] > x)
            j--;
        else
            i++;
    }
    return false;
}

bool triplet_sum(int arr[], int n, int x)
{
    int i = 0;
    while (i < n-2)
    {
        int cur_sum = x - arr[i];
        int j = i + 1, k = n - 1;
        while(j < k)
        {
            if(arr[j] + arr[k] == x)
                return true;
            else if(arr[j] + arr[k] > x)
                k--;
            else
                j++;
        }
        i++;
    }
    return false;
}

double get_median(int a1[], int a2[], int n1, int n2)
{
    int begin = 0, end = n1;
    while (begin <= end)
    {
        //Splitting phase
        int i1 = (begin + end) / 2;
        int i2 = floor((n1 + n2 + 1) / 2) - i1;

        //Calculating the required 4 variables.
        int min1 = (i1 == n1) ? INT_MAX : a1[i1];
        int min2 = (i2 == n2) ? INT_MAX : a2[i2];
        int max1 = (i1 == 0) ? INT_MIN : a1[i1-1];
        int max2 = (i2 == 0) ? INT_MIN : a2[i2-1];


        if(max1 <= min2 && max2 <= min1)
        {
            if((n1 + n2) % 2 == 0)
                return (double)(max(max1,max2) + min(min1,min2)) / 2;
            else
                return (double) max(max1,max2);
        } else if(max1 >min2)
            end = i1 - 1;
        else
            begin = i1 + 1;
    }
    return 0.0;
}

int main()
{
    int n, key;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int *arr = NULL;
    arr = read_array(arr,n);
    cout<<"The Peak element in the array is: "<<peak_element(arr,n)<<endl;
    cout<<"Enter key: ";
    cin>>key;
    linear_search(arr, n, key) ? cout<<"True"<<endl : cout<<"False"<<endl;
    cout<<binary_search(arr, n, key)<<endl;
    cout<<recursive_bs(arr, n, key, 0, n-1)<<endl;
    cout<<"First Occurrence of "<<key<<" is : "<<first_occurrence(arr, key, 0, n-1)<<endl;
    cout<<"Last Occurrence of "<<key<<" is : "<<last_occurence(arr,n,key)<<endl;
    cout<<"Count of "<<key<<" is: "<<count_no_of_occurrences(arr,n,key)<<endl;
    cout<<"\nBinary Array "<<endl;

    int *brr = NULL;
    brr = read_array(brr, n);
    cout<<"No. of 1's = "<<count_of_ones(brr,n)<<endl;

    cout<<"Square Root of 15 is: "<<eff_square_root(15)<<endl;

    int *srr = NULL;
    srr = read_array(srr,n);
    cout<<search_sorted_rotated(srr,n,key)<<endl;

    int n1,n2;
    cout<<"Enter sizes of the 2 arrays: "<<endl;
    cin>>n1>>n2;

    int *a1 = NULL,*a2 = NULL;
    a1 = read_array(a1,n1);
    a2 = read_array(a2,n2);
    cout<<"The Median of the 2 sorted arrays is : "<<get_median(a1,a2,n1,n2)<<endl;
}