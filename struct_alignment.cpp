#include "iostream"
using namespace std;

struct A
{
    char c;
    double d;
    char e;
};

struct B
{
    char c;
    char d;
    double e;
};

struct C
{
    char c;
    double d;
    char e;
}__attribute((packed));  //Telling the compiler to do compact representation

int main()
{
    cout<< sizeof(A)<<endl;
    cout<< sizeof(B)<<endl;
    cout<< sizeof(C)<<endl;
}