#include "iostream"
#include "vector"

using namespace std;

bool is_pow_of_2(int n)
{
    if(n & (n - 1))
        return false;
    return true;
    // return !(n & (n - 1));
}

string int_to_bin(int n)
{
    if(n == 0)
        return "0";

    string binary;

    while (n > 0)
    {
        binary = to_string(n % 2) + binary;
        // binary.append(to_string(n % 2)); This generates in reverse order
        n >>= 1;
    }
    return binary;
}

/*
 * 1.Subset Sum Problem: Use bit manipulation to find all subsets of a set and check if any subset sums to a target
 * value. Each subset can be represented as a bitmask.
*/
bool isSubsetSum(const int nums[],int n, int target) {
    int totalSubsets = 1 << n; // 2^n possible subsets

    // Iterate over all possible subsets
    for (int subset = 0; subset < totalSubsets; ++subset) {
        int sum = 0;

        // Check every bit in the subset mask
        for (int i = 0; i < n; ++i) {
            // If the ith bit is set in the subset mask, include nums[i] in the sum
            if (subset & (1 << i)) {
                sum += nums[i];
            }
        }

        // Check if the current subset sum matches the target
        if (sum == target) {
            return true;
        }
    }
    return false;
}

/* Problem 2 :
 * Given an integer, efficiently count the number of 1’s (set bits) in its binary representation.
 */

int count_set_bits(int n)
{
    int count = 0;
    while(n > 0)
    {
        count += n & 1;
        n >>= 1; // n /= 2
    }
    return count;
}

/* Problem 3
 * Given an array of integers where every element appears twice except for one, find that single
 * element that appears only once. You must solve this problem in linear time (O(n)) and constant space (O(1)).
 */

void unique_single_element()
{
    int nums[] = {1, 2, 4, 3, 2, 4, 1};

    // XOR of two identical numbers is 0, all pairs of duplicate elements will cancel out, leaving only the
    // single non-duplicate element.
    int unique_ele = 0;

    for(int num : nums)
        unique_ele ^= num;

    cout<<"The Single Unique Element in the Array is: "<<unique_ele<<endl;
}

/* Problem 4 :
 * Given two signed integers, determine whether they have opposite signs.
 */

bool is_opposite_sign(int n1, int n2)
{
    return (n1 ^ n2) < 0;
    //In a signed integer, the most significant bit (MSB) indicates the sign of the number:
    //	•	0 for positive numbers.
    //	•	1 for negative numbers.
    //XORing two numbers with different MSBs will result in a number with an MSB of 1 (a negative number).
    //XORing two numbers with the same MSB will result in a number with an MSB of 0 (a positive number).
}

/* Problem 5 :
 * Given an integer, check if the binary representation of that integer is a palindrome.
 */

bool isBitwisePalindrome(unsigned int n) {
    // Find the position of the most significant bit that is set to 1
    int highestBitPosition = 0;
    unsigned int temp = n;

    while (temp > 0) {
        highestBitPosition++;
        temp >>= 1;
    }

    // Check if the number is a palindrome by comparing corresponding bits
    for (int i = 0; i < highestBitPosition / 2; ++i) {
        if (((n >> i) & 1) != ((n >> (highestBitPosition - 1 - i)) & 1)) {
            return false;
        }
    }

    return true;
}

/* Problem 6
 * Swapping Numbers without Temporary Variable: Swap two integers without using a temporary variable by utilizing XOR.
 */

void naive_sol(int& n1, int& n2)
{
    cout<<"Before Swapping: n1 & n2 = "<<n1<<" "<<n2<<endl;

    n1 = n1 + n2;
    n2 = n1 - n2;
    n1 = n1 - n2;

    cout<<"After Swapping: n1 & n2 = "<<n1<<" "<<n2<<endl;
}

void swap_xor(int &a, int &b) {
    a = a ^ b;  // Step 1: a now holds the value of a XOR b
    b = a ^ b;  // Step 2: b now holds the original value of a
    a = a ^ b;  // Step 3: a now holds the original value of b
}

/*Problem 7: Gray Code Generation

Problem Statement:
Given a non-negative integer n representing the number of bits, generate the sequence of Gray codes.
A Gray code is a binary numeral system where two successive values differ in only one bit.

Approach:

The i-th Gray code can be generated from the binary representation of i using the formula:
 Gray(i) = i ^ (i >> 1)

 	•	For n = 3:
	•	The binary Gray code sequence is [000, 001, 011, 010, 110, 111, 101, 100].
	•	The corresponding decimal values are [0, 1, 3, 2, 6, 7, 5, 4].

 */

void generateGrayCode(int n)
{
    vector<int> grayCodes;
    int totalCodes = 1 << n;  // Total number of Gray codes for n bits is 2^n

    for (int i = 0; i < totalCodes; i++) {
        int grayCode = i ^ (i >> 1);
        grayCodes.push_back(grayCode);
    }
    cout<<"The GrayCodes are: \n";
    for(int x : grayCodes)
        cout<<x<<" ";
    cout<<endl;
}

/*
 * Problem 8: Finding the Missing Number

Problem Statement:
    Given an array of integers from 1 to n where one number is missing, find the missing number using XOR.
 */

int missing_number(const int arr[], int n, int N)
{
    int Full_xor = 0, cur_xor = 0;

    for(int i = 0; i < n;i++)
        cur_xor ^= arr[i];

    for(int i = 1; i <= N;i++)
        Full_xor ^= i;

    return Full_xor ^ cur_xor;
}

/*Problem 8: Counting Bit Differences

Problem Statement:
Given two integers a and b, count the number of bits that are different between them.

Approach:

To count the number of differing bits between two integers a and b, we can use the XOR operation. XOR between two bits results in:

	•	0 if the bits are the same.
	•	1 if the bits are different.
 */

int count_different_bits(int n1, int n2)
{
    int res = n1 ^ n2; //First perform X-OR operation on the 2 numbers
    int count = 0;

    while(res > 0)
    {
        count += (res & 1);
        res >>= 1;
    }
    return count;
}

int main()
{
    cout<<boolalpha;
    cout<<16<<" is Power of 2."<<is_pow_of_2(16)<<endl;

    cout<<"The Binary representation of 9 is -> "<<int_to_bin(9)<<endl;

    int arr[] = {3, 34, 12, 4, 2, 5}, n = 6;

    //To generate 2 ^ n using Bit Magic.
    cout<<"2 ^ 3 = "<<(1 << 3)<<endl;

    // Problem 1 :
    if (isSubsetSum(arr,n, 9))
        cout << "Found a subset with the given sum."<<endl;
    else
        cout << "No subset with the given sum.\n";

    // Problem 2
    cout<<"The No. of set-bits in the binary rep of 8 is: "<<count_set_bits(8)<<endl;

    //Problem 3
    unique_single_element();

    //Problem 4
    cout<<"7 & -8 are having different sign's - "<<is_opposite_sign(7, -8)<<endl;

    //Problem 5
    unsigned int bin = 9;
    cout<<"9 is a Bitwise Palindrome. - "<<isBitwisePalindrome(bin)<<endl;

    // Problem 6
    int n1 = 3, n2 = 5;
    naive_sol(n1, n2);

    //Problem 7
    generateGrayCode(3);  // For 3 bits

    //Problem 8
    int brr[] = {3,7,9,2,4,6,1,5};
    cout<<"The Missing Number is : "<<missing_number(brr, 8, 9)<<endl;

    //Problem 9
    cout<<"The No. of different bits between the numbers 29 & 15 is: "<<count_different_bits(29, 15)<<endl;

    return 0;
}