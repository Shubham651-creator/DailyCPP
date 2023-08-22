#include <iostream>
#include <memory>
#include "Employee.h"

int main()
{

    std::unique_ptr<Employee> e1 = std::make_unique<Employee>(101,"shubham");

    std::unique_ptr<Employee> e2(std::move(e1));

    // INvalid because e1 is moved already !
    // e1.get();

    e1 = std::make_unique<Employee>(123,"harshit"); // new resource attached to e1

    return 0;
}