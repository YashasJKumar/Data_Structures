//
// Created by YASHAS J KUMAR on 30/08/24.
//

/*
 * References -> Improve performance, enhances security & safety, avoid unnecessary copying.
 */

#include "iostream"
#include "vector"
using namespace std;

void modify(int& x)
{
    x = 20;
    //This fun is operating on original value of x.
}

void multiple_fun(int& a, int& b, int& sum, int& product)
{
    sum = a + b;
    product = a * b;
}

void display_vector(vector<int>& v)
{
    cout<<"The Vector contains : "<<endl;
    for(int& i : v)
        cout<<i<<" ";
    cout<<endl;
}

void normal_del(vector<int> v)
{
    v.pop_back();
}

void ref_delete(vector<int>& v)
{
    v.pop_back();
}

int main()
{
    int x = 10;
    int& ref = x;
    cout<<ref<<endl;

    modify(ref);  // Even if u call modify(x) => Same answer.

    cout<<"x = "<<x<<endl;

    int arr[] = {10, 20, 30};

    for(int&i : arr)
        cout<<i<<" ";  //Avoids copying of arr elements each time.

    int a, b;

    modify(a);
    b = 30;

    int sum, product;

    multiple_fun(a, b, sum, product);

    cout<<"\nSum = "<<sum<<" Product = "<<product<<endl;

    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    normal_del(v);
    display_vector(v);

    ref_delete(v);
    display_vector(v);

    return 0;
}
