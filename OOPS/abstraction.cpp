//
// Created by YASHAS J KUMAR on 28/08/24.
//

#include "iostream"
using namespace std;

class Shape
{
protected:
    int length, height, width;

public:
    Shape(const int l, const int h, const int w) {
        length = l;
        height = h;
        width = w;
    }

    Shape(const int l, const int w) {
        length = l;
        width = w;
        height = l;
    }

    virtual ~Shape() = default;
    /*
     *A trivial destructor in C++ is a destructor that performs no operations and has a default
     *implementation provided by the compiler. It means the destructor neither has a body nor any
     *side effects, and it doesn't call the destructors for non-static data members or base classes.
     *Trivial destructors allow for certain optimizations, like skipping calls to destructors when
     *deallocating objects of trivially destructible types.
     */
    virtual int area() = 0;
    // Pure Virtual Functions.

    virtual void display() = 0;
};

// 'final' => This is the last class in the inheritance hierarchy. No other class can inherit from this class.
class Rectangle final : public Shape
{
public:
    Rectangle(const int length, const int width): Shape(length, width) {}

    int area() override
    {
        return length * width;
    }

    inline void display() override
    {
        cout<<"Drawing a Rectangle"<<endl;
    }
};

class Triangle final : public Shape
{
public:
    Triangle(int height, int width): Shape(height, width) {}

    int area() override
    {
        return static_cast<int>(0.5 * width * height);
    }

    void display() override
    {
        cout<<"Drawing a Triangle"<<endl;
    }
};

int main()
{
    Shape* shape1 = new Rectangle(3, 5);
    cout << "Area of Rectangle: " << shape1->area() << " units." << endl;
    shape1->display();

    Shape* shape2 = new Triangle(3, 2);
    cout << "Area of Triangle: " << shape2->area() << " units." << endl;
    shape2->display();

    delete shape1;
    delete shape2;

    return 0;

}
