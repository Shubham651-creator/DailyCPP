#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    int _id;
    float _salary;
    std::string _name;

public:
    Employee() = delete;

    Employee(const Employee &) = delete;

    Employee &operator=(Employee &) = delete;

    Employee(Employee &) = delete;

    Employee &operator=(Employee &&) = delete;

    Employee(int id, float sal, std::string name)
        : _id(id), _salary(sal), _name(name) {}

    ~Employee() = default;

    float CalculateTax()
    {
        return _salary * 0.1f;
    }

    float salary() const { return _salary; }

    int id() const { return _id; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
        os << "_id: " << rhs._id
           << " _salary: " << rhs._salary
           << " _name: " << rhs._name;
        return os;
    }
};

#endif // EMPLOYEE_H
