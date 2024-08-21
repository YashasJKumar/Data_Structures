#include "iostream"
#include "unordered_set"

using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(15);
    s.insert(5);
    s.insert(10);
    for(int x : s)
        cout<<x<<" ";
    cout<<endl;

    for(auto itr = s.begin(); itr != s.end();itr++)
        cout<<*itr<<" ";
    cout<<endl;
    cout<<s.size()<<endl;

    s.erase(15);

    cout<<s.size()<<endl;

    auto it = s.find(5);
    s.erase(it);
    cout<<s.size()<<endl;

    //You can also pass range of elements to erase.
    //s.erase(s.begin(), s.end());

    if(s.find(15) == s.end())
        cout<<"Not present"<<endl;
    else
        cout<<*(s.find(15))<<" is present."<<endl;

    if(s.count(15))
        cout<<"Present"<<endl;
    else
        cout<<"Not present."<<endl;
    // count() returns either 1 or 0. Since set cannot contain duplicates.



    s.clear();
    cout<<s.size()<<endl;
}