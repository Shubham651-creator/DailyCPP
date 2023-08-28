#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <memory>

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
    Employee(int id, float sal);
    ~Employee() = default;

    float getSalary() const { return salary; }
};

using Pointer = std::unique_ptr<Employee>;

float CalculateTax(const Pointer &obj);

#endif // EMPLOYEE_H
