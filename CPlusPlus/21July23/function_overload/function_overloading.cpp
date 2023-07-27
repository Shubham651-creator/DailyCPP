#include <iostream>

// Poly-morphism : many forms of the same message(function Name)
//  function overloading
/*
    2 or more functions with same name, but different signature
    [ReturnType is not considered]

    signature - dataTypes, sequence , and number of parameter

*/
// complier do NAME MANGLING - decorate function name with extra characters

class A
{
public:
    static void add(int a, int b)
    {
        std::cout << a + b << "\n";
    }
    static void add(double a, double b)
    {
        std::cout << a + b << "\n";
    }
    static void add(float a, float b)
    {
        std::cout << a + b << "\n";
    }
};

int main()
{
    A::add(1, 2);       // integer
    A::add(1.1, 2.4);   // double
    A::add(2.3f, 3.5f); // float

    return 0;
}