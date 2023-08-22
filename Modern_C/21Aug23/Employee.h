#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    int _eid;
    std::string _ename;

public:
    Employee() = default;
    Employee(const Employee &) = default;
    Employee(Employee &&) = default;
    Employee &operator=(const Employee &) = default;
    Employee &operator=(Employee &&) = default;
    ~Employee() = default;

    explicit Employee(int id, std::string name) : _eid(id) ,_ename(name) {}

    void demo()
    {
        std::cout << "object with ID: " << _eid << " called demo\n";
    }
};

#endif // EMPLOYEE_H
