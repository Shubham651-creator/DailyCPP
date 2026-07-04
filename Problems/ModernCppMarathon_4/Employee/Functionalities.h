#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <array>
#include <optional>
#include "Employee.h"
#include "System.h"

// Pointer of Employee
using Pointer = std::shared_ptr<Employee>;

// container has ability to access random position
// and no option to resize.
using Container = std::array<Pointer, 5>;

// create a object of 5 employee class
void CreateObjects(Container &empObjects);

// a fucntion to return average salary of Depart IT
float AverageSalaryOfIT(Container &empObjects);

// print object whose salary is highest.
// If ther are multiple then print first found.
void HighestSalary(Container &empObjects);

// return bool, whether all instance in container
// have age above 25 or not.
bool AgeAbove25OrNot(Container &empObjects);

// return pointer of instance in result container,
// if memory = 16GB, diskSpace is 10%, and IT or accounts.
std::optional<Container>
MatchingAllConditions(Container &empObjects);

// return float salary, whose match with id passed.
float FindSalaryOfId(Container &empObjects, int passedId);

// return int count, whose salary > 8000 and age < 30.
int CountInstances(Container &empObjects);

#endif // FUNCTIONALITIES_H
