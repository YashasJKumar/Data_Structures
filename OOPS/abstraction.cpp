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
    virtual ~Shape() {};
    virtual int area() = 0;
    // Pure Virtual Functions.

    virtual void display() = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(int length, int width)
    {
        this->length = length;
        this->width = width;
    }
    int area() override
    {
        return length * width;
    }

    inline void display() override
    {
        cout<<"Drawing a Rectangle"<<endl;
    }
};

class Triangle : public Shape
{
public:
    Triangle(int height, int width)
    {
        this->width = width;
        this->height = height;
    }

    int area() override
    {
        return (int)(0.5 * width * height);
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
