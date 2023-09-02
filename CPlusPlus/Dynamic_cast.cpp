#include <iostream>
/*
    1. If the cast is successful, dynamic_cast returns a value of type "target-type". 

    2. If the cast fails and target-type is a pointer type, 
    it returns a "null pointer" of that type. 

    3. If the cast fails and target-type is a reference type, 
    it throws an exception that matches a handler of type std::bad_cast. 
*/

struct V
{
    const char *Display() const
    {
        return "X child class of A\n";
    }
};

struct A : V
{
    virtual const char *Display() const
    {
        return "A base class of B and C\n";
    }
};

struct X :V
{
    const char *Display() const
    {
        return "X child class of A\n";
    }
};

struct B : A, X
{
    const char *Display() const
    {
        return "B child class of A\n";
    }
};

 

int main()
{
    //By Dynamic_cast, We do downcasting as well as side-casting
    //only in virtual run-time overriding 
    B b;
    A a1;
    X x1;
    V v;

    A &a = b; // upcasting

    std::cout << "Upcasting via implicity : " << a.Display() << '\n';

    B &b1 = dynamic_cast<B &>(a); // downcasting using type-cast
    std::cout << "Downcasting using dynamic_cast : " << b1.Display() << '\n';

    X &x = dynamic_cast<X&>(b); // side-casting using dynamic-cast
    std::cout<<"Side-casting using dynamic cast : "<<x.Display()<<'\n';

    B &b2 = (B &)a1;
    std::cout << "Normal type cast : " << b2.Display() << '\n';
}