#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    int _id;
    float salary;

public:
    Employee() = delete;
    Employee(const Employee &) = delete;
    Employee(const Employee &&) = delete;
    Employee operator=(Employee &) = delete;
    Employee operator=(Employee &&) = delete;
    Employee(int id, float sal) ;
    ~Employee() = default;

    float CalculateTax(); // decleration
};

#endif // EMPLOYEE_H
