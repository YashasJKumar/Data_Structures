#include "iostream"
#include "unordered_map"

using namespace std;

int main()
{
   unordered_map<string, int> m;
   m["a"] = 20;
   m["b"] = 30;
   m["c"] = 40;

   cout<<m.size()<<endl;

   for(auto x : m)
       cout<<x.first<<" "<<x.second<<endl;

   for(auto it = m.begin(); it != m.end();it++)
       cout<<it->first<<" "<<it->second<<endl;

   if(m.find("b") != m.end())
       cout<<"Found "<<(m.find("b")->second)<<endl;
   else
       cout<<"Not Found"<<endl;

   //count() is a substitute to find()
   if(m.count("b") > 0)
       cout<<"Found"<<endl;
   else
       cout<<"Not Found"<<endl;

   m["d"] = 10;
   m.erase("d");
   //m.erase(m.begin()) => Deletes the first key stored
   //m.erase(m.begin(), m.end()) => Deletes all.

   //You can also use rbegin() also but there's no difference
    return 0;
}