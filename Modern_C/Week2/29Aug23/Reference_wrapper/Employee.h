#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <memory>
#include<functional>
#include"Project.h"

using RefType = std::reference_wrapper<std::unique_ptr<Project>> ;

class Employee
{
private:
    int _id;
    float salary;
    RefType _active_project;

public:
    Employee() = delete;
    Employee(const Employee &) = delete;
    Employee(const Employee &&) = delete;
    Employee operator=(Employee &) = delete;
    Employee operator=(Employee &&) = delete;
    Employee(int id, float sal, RefType project);
    ~Employee() = default;

    float getSalary() const { return salary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

};

using Pointer = std::unique_ptr<Employee>;

float CalculateTax(const Pointer &obj);

#endif // EMPLOYEE_H
