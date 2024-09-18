#include "iostream"

using namespace std;

int generate_average(int n, const int arr[]) noexcept(false)
{
    int sum = 0;
    if(n == 0)
        throw 0;
    for(int i = 0;i < n;i++)
        sum += arr[i];
    return sum/n;
}

int main()
{
    int arr[] = {3, 5, 7};
    try{
        //This block may generate an error.
        int res = generate_average(0,arr);
        cout<<res<<endl;
    }
    catch(int x)
    {
        cerr<<"Division by zero"<<endl;
    }
}