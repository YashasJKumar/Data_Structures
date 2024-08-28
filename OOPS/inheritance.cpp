//
// Created by YASHAS J KUMAR on 28/08/24.
//
#include "iostream"

using namespace std;

/* Inheritance refers to the phenomenon of 1 class acquiring the properties(Member methods & data members) from another class
 * The class whose properties are inherited by other class is referred to as Base/Super Class & the other class is known as the Derived class.
 * */

class Base
{
public:
    int a;
    float f;

    static int st;


    Base(int a, float f) {
        this->a = a;
        this->f = f;
    };

    inline void display()
    {
        cout<<"This is Base class's display method"<<endl;
        cout<<"Static st in base class = "<<st<<endl;
    }
};

int Base :: st = 50;

class Derived : public Base
{
public:
    int c;

    /*
     * If the base class has a constructor that takes parameters, and the derived class does not explicitly call this constructor, the compiler will not be able to implicitly call the base class constructor because it doesn’t know which arguments to pass.
	•	Therefore, you must explicitly call the base class constructor from the derived class constructor, passing the appropriate arguments.
     */

    Derived(int a, float f, int c) : Base(a, f) {
        this->c = c;
    }

    void d1_display()
    {
        cout<<"a = "<<a<<" f = "<<f<<" c = "<<c<<endl;
        cout<<"Static st in Derived class = "<<st<<endl;

    }
};



class Derived2 : public Derived
{
public:
    char d;

    Derived2(int a, float f, int c, char d) : Derived(a, f, c) {
        this->d = d;
    }

    inline void d2_display()
    {
        cout<<"This is to demonstrate Multi Level Inheritance."<<endl;
        cout<<"Static st in Derived2 class = "<<st<<endl;
    }

    inline void change_st(int val)
    {
        st = val;
    }

    static void hai()
    {
        cout<<"Hello"<<endl;
    }
};

class Base2
{
public:
    int x;
    static int st;  // This is to crete Name Ambiguity.

    explicit Base2(int x)
    {
        this->x = x;
    }

    void base2_display()
    {
        cout<<"Display method of Base2 class"<<endl;
    }
};

int Base2 :: st = 500;

class Multi : public Base, public Base2
{
public:
    int z;

    Multi(int a, float f, int x, int z) : Base(a, f) , Base2(x) {
        this->z = z;
    }

    inline void multi_display()
    {
        cout<<"This is to exhibit Multiple Inheritance. "<<Base2::st<<endl;  // Name Ambiguity is resolved using Scope Resolution.
    }
};

class Derived3 : public Base
{
public:
    string name;

    Derived3(int a, float f, const string& name) : Base(a, f) {
        this->name = name;
    }

    inline void d3_display() const
    {
        cout<<"This is to show Hierarchical Inheritance. " + name<<endl;
    }
};

int main()
{
    Base b(17, 24.26);
    b.display();
    cout<<endl;

    Derived d(10, 3.14, 15);
    d.d1_display();
    cout<<endl;


    Derived2 d2(12, 23.25, 26, 'y');
    d2.d2_display();
    cout<<endl;


    d2.change_st(100);

    d.d1_display();

    Derived2::hai();  //Static Method can be accessed without any instance of that class.

    Multi m(35, 99.97, 150, 288);
    m.multi_display();
    cout<<endl;

    Derived3 d3(25, 100.23, "Toyota");
    d3.d3_display();

}
