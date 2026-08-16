#include <iostream>

class A
{
public:
    int value;

    A(int v = 0) : value(v)
    {
        std::cout << "A constructor\n";
    }
};

class B : virtual public A
{
public:
    B() : A(10)
    {
        std::cout << "B constructor\n";
    }
};

class C : virtual public A
{
public:
    C() : A(20)
    {
        std::cout << "C constructor\n";
    }
};

class D : public B, public C
{
public:
    D() : A(30)
    {
        std::cout << "D constructor\n";
    }
};

int main()
{
    D obj;

    std::cout << obj.value << '\n';
}