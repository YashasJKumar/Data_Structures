#include "iostream"

using namespace std;

class Animal
{
public:
    void eat(){
        cout<<"Animal is eating."<<endl;
    }
};

class Dog : virtual public Animal
{
public:
    void eat(){
        cout<<"Dog is eating."<<endl;
    }
};

class Cat :virtual public Animal
{
public:
    void eat(){
        cout<<"Cat is eating."<<endl;
    }
};

class Mixed : public Dog, public Cat
{
public:
    void eat(){
        cout<<"Mixed Eating."<<endl;
    }
};

int main()
{
    Mixed m;
    m.eat();
    m.Cat::eat();  // Avoiding ambiguity through Scope Resolution.

//    m.eat();
}