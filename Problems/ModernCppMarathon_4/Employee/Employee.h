#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <memory>
#include "DepartmentType.h"
#include "System.h"

class Employee
{
private:
    int _id;
    std::string _name;
    float _salary;
    std::shared_ptr<System> _system;
    int _age;
    DepartmentType _department;
    int _experience_months;

public:
    // disable default constructor
    Employee() = delete;

    // disable copy constructor
    Employee(const Employee &) = delete;

    // disable copy assignment operator
    Employee &operator=(Employee &) = delete;

    // disable move constructor
    Employee(Employee &&) = delete;

    // disable move assignment operator
    Employee &operator=(Employee &&) = delete;

    // parameterized constructor
    Employee(int id, std::string name, float salary, std::shared_ptr<System> sys,
             int age, DepartmentType depart, int months);

    // destructor
    ~Employee() = default;

    // getter of all attributes

    int id() const { return _id; }

    std::string name() const { return _name; }

    float salary() const { return _salary; }

    std::shared_ptr<System> system() const { return _system; }

    int age() const { return _age; }

    DepartmentType department() const { return _department; }

    int experienceMonths() const { return _experience_months; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

std::string DisplayDepartment(DepartmentType type);

#endif // EMPLOYEE_H
