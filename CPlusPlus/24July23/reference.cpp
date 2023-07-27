#include <iostream>
// By default implementation
// 1. default constructor
// 2.Destructor
// 3.default copy constructor (shallow copy)

//implicit copy constructor does shallow copy - direct memberwise copy

// changes made in formal arg will not reflect in actual arg

void swap(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

// void swap(int x, int y) //pass by value
// {
//     int t;
//     t = x;
//     x = y;
//     y = t;
// }

class Demo
{
    int p;

public:
    Demo()
    {
        p = 100;
    }

    void show()
    {
        std::cout << p << "\n";
    }
};

void print(Demo &d2) // global function and pass by ref
{
}

int main()
{

    Demo d1;
    print(d1);

    int a = 10;
    int b = 20;

    swap(a, b);
    std::cout << "Swap element: a= " << a << "\tb = " << b << "\n";

    //'r' is reference to 'a'
    //'r' is allcate zero byte
    //'r' is allias or nickname for 'a'
    int &r = a; // reference operator

    ++r; // same as ++a

    std::cout << "a = " << a << "\nr = " << r << "\n";
    return 0;
}