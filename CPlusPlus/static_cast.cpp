#include <iostream>

struct A
{
    const char *Display() const
    {
        return "A base class\n";
    }
};

struct B : A
{
    const char *Display() const
    {
        return "B child class\n";
    }
};

int main()
{
    B b;

    A &a = b; // upcasting

    std::cout << "Upcasting via implicity : " << a.Display() << '\n';

    B &b1 = static_cast<B &>(a); // downcasting using static-cast
    std::cout << "Downcasting using static cast : " << b1.Display() << '\n';

    B &b2 = (B &)a;
    std::cout << "Normal type cast : " << b2.Display() << '\n';
}