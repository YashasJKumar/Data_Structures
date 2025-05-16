#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function that will be overridden in derived classes
    virtual void sound() const {
        cout << "Some generic animal sound\n";
    }

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Animal() {
        cout << "Animal destructor\n";
    }
};

// Derived class 1
class Dog : public Animal {
public:
    // Overriding the virtual function
    void sound() const override {
        cout << "Woof Woof\n";
    }

    ~Dog() override {
        cout << "Dog destructor\n";
    }
};

// Derived class 2
class Cat : public Animal {
public:
    // Overriding the virtual function
    void sound() const override {
        cout << "Meow Meow\n";
    }

    ~Cat() override {
        cout << "Cat destructor\n";
    }
};

// Derived class 3
class Cow : public Animal {
public:
    // Overriding the virtual function
    void sound() const override {
        cout << "Moo Moo\n";
    }

    ~Cow() override {
        cout << "Cow destructor\n";
    }
};

int main() {
    // Pointers to the base class
    Animal* animal1 = new Dog(); //Up-casting from Dog -> Animal
    Animal* animal2 = new Cat();
    Animal* animal3 = new Cow();

    Animal* a;
    Dog* d = new Dog();

    Cow* c = new Cow();

    a = c;
    a->sound();

    a = d;
    a->sound();

    // Runtime polymorphism - calling the overridden function
    animal1->sound();  // Outputs: Woof Woof
    animal2->sound();  // Outputs: Meow Meow
    animal3->sound();  // Outputs: Moo Moo

    // Deleting the objects - proper destructor calls due to virtual destructor
    delete animal1;  // Calls Dog destructor, then Animal destructor
    delete animal2;  // Calls Cat destructor, then Animal destructor
    delete animal3;  // Calls Cow destructor, then Animal destructor

    delete c;
    delete d;

    return 0;
}
