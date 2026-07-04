/*
    I want to perform an operation that
    can work for potentially infinte types.
*/

/*
    Meta programming - something that work with all data type

    STL - std Template libraries
*/
#include <iostream>
#include <memory>

// template <typename T>
template <class T>
void display(T a)
{
    std::cout << a << '\n';
}

template <class A, class B>
void addition(A n1, B n2)
{
    std::cout << n1 + n2 << '\n';
}

int main()
{

    int n1 = 70;

    display<int>(n1);

    display<float>(20.3f);

    addition<int, float>(10, 20.20f);
}