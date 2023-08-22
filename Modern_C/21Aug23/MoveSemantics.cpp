#include <iostream>
#include <memory>
#include "Employee.h"

/*
    resource 1 (memory of 4 bytes)
    [101]
    Employee object
    0x549F

*/

// accepts a unique ptr to Employee and print its value
void magic(std::unique_ptr<Employee> &ptr)
{
}

void demo(std::unique_ptr<Employee> &&ptr)
{
}
int main()
{
    std::unique_ptr<Employee> e1 = std::make_unique<Employee>(202);
    magic(e1); // by reference(lvalue)

    /*
        to convert anything into a temporary(rvalue), std::move
    */
    demo(std::move(e1)); // by reference (rvalue i.e. temporary)
    demo(std::make_unique<Employee>(21)); //by ref (rvalue i.e. temporary)
    /*
        after move operation(or converting  into temporary), 
        do not access it because it's give undefined behaviour.
    */

    return 0;
}

/*

    step 1: main()
    step 2: we create e1 (uniaque pointer to Employee)[Resource acquired 4 bytes memeory]
    step 3: call to magic[ Function accepts UNIQUE ptr to Employee]
        - This works because we never copied original unique ptr e1
        - Ownerships never change because original variable still controls resource.

    step 4:
*/

 