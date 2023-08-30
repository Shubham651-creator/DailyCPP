#include <iostream>
#include<functional>

/*
    primitive(int, float)
    > int n1 = 10;

    reference (raw ref: lvalue and rvalue)
    pointer(raw pointer) : addressing of something

    smartPointer (unique and shared ptr) : pointer into boxes
    reference_wrapper (box to store references ) : bend the rules, goto original data
*/

void magic(int &data)
{
    std::cout << "Data address is " << &data << '\n';
    std::cout << "Data value is " << data << '\n';
}

int main()
{

    int n1 = 10;

    magic(n1);                       // valid
    // magic(&n1);                      // invalid : &n1 is a pointer
    // magic(10);                       // ivalid : 10 is rvalue, we need lvalue
    // magic(std::unique_ptr<int>(n1)); // invalid : we are passing a rvalue(smart pointer)
    magic(std::ref(n1));             // redundant use of ref
}