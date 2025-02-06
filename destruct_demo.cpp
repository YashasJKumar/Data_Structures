#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; } // Not virtual
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; } // Will not be called
};

int main() {
    Base* obj = new Derived(); // Base class pointer to derived object
    delete obj; // Only Base destructor is called!
    return 0;
}