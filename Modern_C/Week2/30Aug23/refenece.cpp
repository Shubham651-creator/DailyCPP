#include <iostream>
#include <functional>

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

void old_function_without_ref(int data)
{
    std::cout << "Data address = " << &data << '\n';
    std::cout << "Data value = " << data << '\n';
}

int main()
{

    int n1 = 10;

    std::cout << "\nFirst time \n";

    old_function_without_ref(n1); // call by value
    std::cout << "n1 address is " << &n1 << '\n';
    std::cout << "n1 value is " << n1 << '\n';

    ////////////////////////////////////////////////

    /*
        std::ref says (whatever is being passed inside std::ref MUST BE
        ACCEPTED AS A REFERENCE REFARDLESS OF WHAT THE CODE SAYS )

        std::ref , it gernerally use when your code is build by call by value
        but now you have to build by call by ref
    */

    std::cout << "\nSecond time \n";

    old_function_without_ref(std::ref(n1)); // call by ref
    std::cout << "n1 address = " << &n1 << '\n';
    std::cout << "n1 value = " << n1 << '\n';
}

/*
    magic(n1);                       // valid
    magic(&n1);                      // invalid : &n1 is a pointer
    magic(10);                       // ivalid : 10 is rvalue, we need lvalue
    magic(std::unique_ptr<int>(n1)); // invalid : we are passing a rvalue(smart pointer)
    magic(std::ref(n1));             // redundant use of ref
*/