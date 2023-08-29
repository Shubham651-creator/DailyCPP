#include "Employee.h"
#include<memory>

using Pointer = std::unique_ptr<Employee>;

float CalculateTax(const Pointer &obj)
{
    return obj->getSalary() * 0.01f;
}

Employee::Employee(int id, float sal)
    : _id(id), salary(sal) {}
    
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " salary: " << rhs.salary;
    return os;
}
