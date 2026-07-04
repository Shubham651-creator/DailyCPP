#include "Employee.h"

std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _system: " << *(rhs._system.get())
       << " _age: " << rhs._age
       << " _department: " << DisplayDepartment(rhs._department)
       << " _experience_months: " << rhs._experience_months;
    return os;
}

std::string DisplayDepartment(DepartmentType type)
{
    if (type == DepartmentType::ACCOUNTS)
    {
        return "ACCOUNTS";
    }
    if (type == DepartmentType::ADMIN)
    {
        return "ADMIN";
    }
    if (type == DepartmentType::SECURITY)
    {
        return "SECURITY";
    }
    if (type == DepartmentType::HR)
    {
        return "HR";
    }
    return "IT";
}

Employee::Employee(int id, std::string name, float salary,
                   std::shared_ptr<System> sys, int age,
                   DepartmentType depart, int months)
    : _id(id), _name(name), _salary(salary), _system(sys), _age(age),
      _department(depart), _experience_months(months)
{
    if (id < 1 || id > 999)
    {
        throw std::runtime_error("id must be in between 1 to 999\n");
    }

    if (salary < 7000.0f || salary > 100000.0f)
    {
        throw std::runtime_error("Salary must be in between 7000 to 100000\n");
    }

    if (age < 18 || age > 60)
    {
        throw std::runtime_error("Age must be in between 18 to 60\n");
    }

    if (months > 10)
    {
        throw std::runtime_error("Experience months must be minimum of 10\n");
    }
}
