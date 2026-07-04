#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <list>
#include <array>
#include <optional>
#include <algorithm>
#include <numeric>
#include "Task.h"
#include "ProjectAllocatedResource.h"

// Pointer to Task class
using taskPointer = std::shared_ptr<Task>;

// list container of task
using taskContainer = std::list<taskPointer>;

// Pointer to ProjectAllocated class
using projectPointer = std::shared_ptr<ProjectAllocatedResource>;

// array container of 4 instacne
using projectContainer = std::array<projectPointer, 4>;

// Create object of 4 instances
void CreateObjects(projectContainer &projectObject);

// a Function print the count of instacne whose project
// has at least three task.
void ThreeAllocatedTask(projectContainer &projectObject);

// return project container, whose has highest expense cap
projectPointer
HighestExpenseCap(projectContainer &projectObject);

// return bool, whether all instacne has at least one task of bug fix.
bool AllInstanceBugFix(projectContainer &projectObject);

// return container of taskCategory enum class,
// whose store max bill amount of every project.
std::vector<TaskCategory>
MaxBillOfEveryProject(projectContainer &projectObject);

// return result container, whose is sorted.
projectContainer SortedContainer(projectContainer &projectObject);

#endif // FUNCTIONALITIES_H
