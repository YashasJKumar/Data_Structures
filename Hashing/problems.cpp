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

int longest_subarray_with_01_efficient(int arr[], int n)
{
    int prefix_sum = 0, ans = 0;
    unordered_map<int , int> map;

    for(int i = 0; i < n;i++)
    {
        if(!arr[i])
            prefix_sum += -1;
        else
            prefix_sum += arr[i];

        if(prefix_sum == 0)
            ans = i + 1;

        if(map.find(prefix_sum) == map.end())
            map.insert(make_pair(prefix_sum, i));
        else
            ans = max(ans, i - map[prefix_sum]);
    }
    return ans;
}

int longest_subarray_with_sum(int arr[], int n, int sum)
{
    unordered_map<int, int> hash_map;
    int prefix_sum = 0, ans = 0;

    for(int i = 0; i < n;i++)
    {
        prefix_sum += arr[i];

        if(prefix_sum == sum)
            ans = i + 1; //This is to handle the special case => where prefix sum starting from index 0.

        if(hash_map.find(prefix_sum) == hash_map.end())
            hash_map.insert(make_pair(prefix_sum, i));

        if(hash_map.find(prefix_sum - sum) != hash_map.end())
            ans = max(ans, i - hash_map[prefix_sum - sum]);
    }
    return ans;
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

int lcs_of_array(int arr[], int n)
{
    int cur = 1, res = 1;
    unordered_set<int> hash_table(arr, arr + n);

    for(int i = 0; i < n;i++)
    {
        if(hash_table.find(arr[i] - 1) == hash_table.end()) {
            cur = 1;

            while(hash_table.find(arr[i] + cur) != hash_table.end())
                cur++;
            res = max(res, cur);
        }
    }
    return res;
}

void distinct_elements_in_every_window(int arr[], int n, int k)
{
    //k -> Size of the window & k < n.
    if(k > n)
        return;

    unordered_map<int, int> frequency_map(k);

    //Insert the elements of first window into the map.
    for(int i = 0; i < k;i++)
        frequency_map[arr[i]]++;

    cout<<frequency_map.size()<<" ";

    for(int i = k; i < n;i++)
    {
        frequency_map[arr[i-k]]--;

        if(!frequency_map[arr[i-k]])
            frequency_map.erase(arr[i-k]);
        if(frequency_map.find(arr[i]) != frequency_map.end())
            frequency_map[arr[i]]++;
        else
            frequency_map[arr[i]] = 1;

        cout<<frequency_map.size()<<" ";
    }

    cout<<endl;
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

    int bin_arr[] = {1, 0, 1,1,1,0,0};
    cout<<"Length of the Longest subarray with equal 0 & 1 => "<<longest_subarray_with_01_efficient(bin_arr, 7)<<endl;

    cout<<"LCS -> "<<lcs_of_array(arr, n)<<endl;

    int arr3[] = {10,20,20,10,30,40,10};
    distinct_elements_in_every_window(arr3, 7, 4);
}