#include "iostream"
#include "list"
using namespace std;

struct HASH
{
    int bucket;
    list<int> *table;
    explicit HASH(int b)
    {
        bucket = b;
        table = new list<int> [b];
    }

    void insert(int key) const
    {
        int i = key % bucket;
        table[i].push_back(key);
        cout<<"Inserted "<<key<<endl;
    }

    void remove(int key) const
    {
        int i = key % bucket;
        table[i].remove(key);
        cout<<"Removed "<<key<<endl;

    }


    bool search(int key)
    {
        int i = key % bucket;
        for(auto x : table[i])
            if(x == key)
                return true;
        return false;
    }
};

int main()
{
    HASH *h = new HASH(7);
    h->insert(10);
    cout<<h->search(10)<<endl;
    h->remove(10);

}




