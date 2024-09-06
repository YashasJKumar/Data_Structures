#include "iostream"
#include "set"

using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(8);
    //Default -> Increasing Order

    for(int x : s)
        cout<<x<<" ";
    cout<<endl;

    //Decreasing Order Set
    set<int, greater<int> > d;

    d.insert(10);
    d.insert(25);
    d.insert(1);

    for(int x : d)
        cout<<x<<" ";
    cout<<endl;

    //Another way of traversing is using Iterators.
    for(auto it = s.begin();it != s.end();it++)
        cout<<*(it)<<" ";
    cout<<endl;

    // Reverse Iterators
    for(auto it = d.rbegin();it != d.rend();it++)
        cout<<*it<<" ";
    cout<<endl;

    //find() -> Returns an iterator either to the found element or to end.
    if(s.find(10) != s.end())
        cout<<"Element Found"<<endl;
    else
        cout<<"Element not found."<<endl;

    cout<<"Size of Set S = "<<s.size()<<endl;

    //lower_bound()
    auto it1 = s.lower_bound(9);
    if( it1 != s.end())
        cout<<*it1<<endl;
    else
        cout<<"Element is greater than the greatest."<<endl;

    //Upper bound is similar to lb but the only difference is that when the element is present in the set it returns the
    // next greater element than it.

    it1 = s.upper_bound(10);
    if( it1 != s.end())
        cout<<*it1<<endl;
    else
        cout<<"Element is greater than the greatest or equal to greatest."<<endl;

}