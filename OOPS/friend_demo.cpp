//
// Created by YASHAS J KUMAR on 30/01/25.
//
#include "iostream"
using namespace std;

class A {
private:
    int secret;

    static void hello() {
        cout << "Hello World!" << endl;
    }
public:
    explicit A(const int s) : secret(s) {}
    friend void display_secret(const A& a);
    friend class B;
};

void display_secret(const A &a) {
    // cout<<"Secret is: "<<a.secret<<endl; Inaccessible
    cout<<"Secret is: "<<a.secret<<endl;
}

class B {
public:
    static void hai(A &obj) {
        cout<<"I am his friend."<<endl;
        cout<<obj.secret<<endl;
        A::hello();
    }
};

int main() {
    A a(5);
    display_secret(a);

    B :: hai(a);
}
