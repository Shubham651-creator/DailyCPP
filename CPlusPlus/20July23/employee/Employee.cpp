#include <iostream>
#include "Employee.h"

/*
    returnType  classname :: functionName(para)
    {

    }
*/

Employee ::Employee()
{
    empid = 101;
    salary = 20000;
    ename = "shubam";
}

Employee ::Employee(int eid, int salary, std::string enm)
{
    empid = eid;
    ename = "awale";
    this->salary = salary;
}

void Employee::show() const
{
    std::cout << empid << " " << salary << " " << ename << std::endl;
}