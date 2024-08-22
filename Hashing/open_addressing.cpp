#include "iostream"
using namespace std;

struct MyHash
{
    int *arr;
    int cap, size;

    explicit MyHash(int c)
    {
        cap = c;
        size = 0;
        arr = (int *) malloc(c * sizeof(int));
        for(int i = 0;i<c;i++)
            arr[i] = -1;
    }

    int hash(int key) const
    {
        return key % cap;
    }

    bool search(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if(arr[i] == key)
                return true;
            i = (i + 1) % cap;
            if(i == h)
                return false;
        }
        return false;
    }

    bool insert(int key)
    {
        if(size == cap)
            return false;
        int h = hash(key);
        while(arr[h] != -1 && arr[h] != -2 && arr[h] != key)
            h = (h + 1) % cap;
        if(arr[h] == key)
            return false;
        else
        {
            arr[h] = key;
            size++;
            return true;
        }
    }

    bool erase(int key) const
    {
        int h = hash(key);
        int i = h;
        while(arr[i] != -1)
        {
            if(arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i = (i + 1) % cap;
            if(i == h)
                return false;
        }
        return false;
    }
};

int main()
{
    MyHash hash(7);
    cout<<hash.cap<<endl;
    hash.insert(10) ? cout<<"Inserted Successfully!"<<endl : cout<<"Insertion Failed!"<<endl;
}