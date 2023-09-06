#include <iostream>

struct S
{
    mutable int x : 2;
    volatile float y;
};

S f() { return S{1, 2.3f}; }

int main()
{

    const auto [x, y] = f();

    std::cout << "x:\t" << x << "\ny:\t" << y << "\n";
}