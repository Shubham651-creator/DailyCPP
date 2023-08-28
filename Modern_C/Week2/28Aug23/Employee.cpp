#include "Employee.h"
#include<memory>

using Pointer = std::unique_ptr<Employee>;

float CalculateTax(const Pointer &obj)
{
    return obj->getSalary() * 0.01f;
}

Employee::Employee(int id, float sal)
    : _id(id), salary(sal) {}