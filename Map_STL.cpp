#include "iostream"
#include "map"

using namespace std;

int main()
{
    map<int, int> m;

    m.insert(make_pair(10, 20));
    m.clear();

    //Another way => m[10] = 20;
    m[15] = 25;

    //If you add another pair with key same as 10.Then that is ignored
    for(auto &p : m)
        cout<<p.first<<" "<<p.second<<endl;

    cout<<m[20]<<endl;  //This is valid & creates a key valued 20 & assigned a default value

    m.at(15) = 300;

    //Iterator Traversal
    for(auto it = m.begin(); it != m.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;

    m[2] = 4;
    m[100] = 55;

    cout<<"Size of Map = "<<m.size()<<endl;

    // We can find only the keys not values.
    if(m.find(100) == m.end())
        cout<<"Element not present."<<endl;
    else
        cout<<"Element present."<<endl;

    auto it1 = m.find(15);

    //Printing the remaining elements after 15
    for(auto it = it1; it != m.end();it++)
        cout<<it->first<<" "<<it->second<<endl;

    if(m.count(2))
        cout<<"2 is present in the Map."<<endl;
    else
        cout<<"2 is not present in the Map."<<endl;

    it1 = m.lower_bound(95);
    if(it1 == m.end())
        cout<<"95 is greater than the greatest."<<endl;
    else
        cout<<it1->first<<" "<<it1->second<<endl;

    cout<<"Size before deletion = "<<m.size()<<endl;
    m.erase(m.find(2));  // Can give just 2
    cout<<"Size after deletion = "<<m.size()<<endl;

    return 0;
}