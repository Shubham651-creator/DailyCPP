#include "Employee.h"
#include <memory>
#include <functional>
#include "Project.h"

using Pointer = std::unique_ptr<Employee>;
using RefType = std::reference_wrapper<std::unique_ptr<Project>>;

float CalculateTax(const Pointer &obj)
{
    return obj->getSalary() * 0.01f;
}

Employee::Employee(int id, float sal, RefType project)
    : _id(id), salary(sal), _active_project(project) {}

std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "_id: " << rhs._id
       << " salary: " << rhs.salary
       << " _active_project: " << *(rhs._active_project.get()); //get() gives anything inside the reference wrapper 
    return os;
}
