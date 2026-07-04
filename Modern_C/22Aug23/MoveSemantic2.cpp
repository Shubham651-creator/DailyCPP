#include <iostream>

// by default struct is public
struct Employee
{
    int _id;

    Employee(int id) : _id(id) {}
};

void magic(const Employee &obj)
{

    std::cout << obj._id << "\n";
}

int main()
{
    Employee e1{20};      // crating a struct variable e1 with 20 as _id
    magic(e1);            // magic with lvalue e1 and e1 binds to obj inside magic by reference
    magic(Employee{101}); // temporary (rvalue)
}

/*
    1. lvalues can bind to lvalue reference.
    2. rvalue can bind to rvalue reference OR const lvalue refernce
*/