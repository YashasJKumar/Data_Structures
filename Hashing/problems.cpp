#include "iostream"
#include "unordered_set"
#include "unordered_map"

using namespace std;


int naive_distinct(int arr[], int n)
{
    int res = 0;
    for(int i = 0;i<n;i++)
    {
        bool flag = false;
        for(int j = 0;j<i;j++)
        {
            if(arr[i] == arr[j]){
                flag = true;
                break;
            }
        }
        if(!flag)
            res++;
    }
    return res;
}

int efficient_distinct(int arr[], int n)
{
    unordered_set<int> s;
    for(int i = 0;i<n;i++)
        s.insert(arr[i]);
    return s.size();
    /*
     * unordered_set<int> s(arr, arr + n);
     * return s.size();
     */
}

void frequency_distinct(int arr[], int n)
{
    for(int i = 0;i < n;i++)
    {
        bool flag = false;
        for(int j = 0;j < i;j++)
            if(arr[j] == arr[i])
            {
                flag = true;
                break;
            }
        if(flag)
            continue;
        int freq = 1;
        for(int j = i + 1;j<n;j++)
            if(arr[i] == arr[j])
                freq++;

        cout<<"The Frequency of "<<arr[i]<<" is: "<<freq<<endl;
    }
}

void efficient_frequency(int arr[], int n)
{
    unordered_map<int, int> freq;
    for(int i = 0;i < n;i++)
    {
        if(freq.count(arr[i]))
            freq[arr[i]]++;
        else
        {
            freq[arr[i]] = 1;
        }
    }
    for(auto itr : freq)
        cout<<"The Frequency of "<<itr.first<<" is: "<<itr.second<<endl;
    //Time Complexity -> theta(n)
}

void intersection_unsorted(int arr1[], int arr2[], int m, int n)
{
    unordered_set<int> hash;
    for(int i = 0;i<n;i++)
        hash.insert(arr2[i]);
    for(int i = 0; i < m; i++)
        if(hash.count(arr1[i]))
            cout<<arr1[i]<<" ";
    cout<<endl;
}

void union_unsorted(int arr1[], int arr2[], int m, int n)
{
    unordered_set<int> set;
    for(int i = 0;i<m;i++)
        set.insert(arr1[i]);
    for(int i = 0;i<n;i++)
        set.insert(arr2[i]);
    for(int x : set)
        cout<<x<<" ";
    cout<<endl;
}

bool pair_sum(int arr[], int n, int sum)
{
    unordered_set<int> hash;
    for(int i = 0;i < n;i++)
    {
        if(hash.find(sum - arr[i]) != hash.end())
            return true;
        else
            hash.insert(arr[i]);
    }
    return false;
}

bool subarray_with_sum_0(int arr[], int n)
{
    unordered_set<int> hash;
    int prefix_sum = 0;
    for(int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if((hash.find(prefix_sum) != hash.end()) || prefix_sum == 0)
            return true;  //prefix_sum == 0 if the arr = {-3, 2, 1, 4}
        else
            hash.insert(prefix_sum);
    }
    return false;
}

bool subarray_with_given_sum(const int arr[], int n, int sum)
{
    unordered_set<int> hash;
    int prefix_sum = 0;
    for(int i = 0;i < n;i++)
    {
        prefix_sum += arr[i];
        if(hash.find(prefix_sum - sum) != hash.end() || prefix_sum == sum)
            return true;
        else
            hash.insert(prefix_sum);
    }
    return false;
}

int longest_subarray_with_equal_01(int arr[], int n)
{
    int cur_largest = 0;
    int cnt_0 = 0, cnt_1 = 0;
    for(int i = 0;i<n-1;i++)
    {
        cnt_0 = 0, cnt_1 = 0;
        for(int j = i; j < n;j++)
        {
            if (arr[j])
                cnt_1++;
            else
                cnt_0++;
            if (cnt_0 == cnt_1 && (j - i) > cur_largest)
                cur_largest = j - i;
        }
    }
    return cur_largest + 1;
}

int longest_common_subarray(int arr1[], int arr2[], int n)
{
    unordered_map<int, int> map;
    int diff[n];
    for(int i = 0; i < n;i++)
        diff[i] = arr1[i] - arr2[i];
    int max_len = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        // Add current element to sum 
        sum += diff[i];

        // To handle sum=0 at last index 
        if (sum == 0)
            max_len = i + 1;

        // If this sum is seen before, 
        // then update max_len if required 
        if (map.find(sum) != map.end())
            max_len = max(max_len, i - map[sum]);

        else // Else put this sum in hash table 
            map[sum] = i;
    }
    return max_len;
}

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: "<<endl;
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<naive_distinct(arr, n)<<endl;
    frequency_distinct(arr, n);
    //efficient_frequency(arr, n);
    int arr2[] = {30, 5, 15};
    intersection_unsorted(arr,arr2,n,3);
    union_unsorted(arr, arr2,n, 3);
    pair_sum(arr, n, 6) ? cout<<"Pair Exists"<<endl : cout<<"Pair doesn't exist"<<endl;
    subarray_with_sum_0(arr, n) ? cout<<"Sub-Array Exists with Sum = 0"<<endl : cout<<"Sub-Array Doesn't Exist with Sum=0"<<endl;
    subarray_with_given_sum(arr, n, 22) ? cout<<"Sub-Array Exists with Sum = 22"<<endl : cout<<"Sub-Array Doesn't Exist with Sum=22"<<endl;
    cout<<"Largest sub-array with equal no. of 0's & 1's is: "<<longest_subarray_with_equal_01(arr, n)<<endl;
}