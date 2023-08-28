#include "Employee.h"

float Employee::CalculateTax()
{
    return salary * 0.01f;
}
Employee::Employee(int id, float sal)
    : _id(id), salary(sal) {}