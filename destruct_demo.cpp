#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor: Object created" << endl;
    }

    ~MyClass() {
        cout << "Destructor: Object destroyed" << endl;
    }
};

int main() {
    MyClass obj;  // Constructor is called
    cout << "In main function" << endl;
    // Destructor is automatically called at the end of scope
    return 0;
}