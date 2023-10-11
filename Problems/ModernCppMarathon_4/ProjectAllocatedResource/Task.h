#ifndef TASK_H
#define TASK_H

#include <iostream>
#include "TaskCategory.h"

class Task
{
private:
    std::string _task_description;
    int _allocated_days;
    int _allocated_resource;
    TaskCategory _category;

public:
    // disable default constructor
    Task() = delete;

    // disable copy constructor
    Task(const Task &) = delete;

    // disable copy assignment operator
    Task &operator=(Task &) = delete;

    // disable move constructor
    Task(Task &&) = delete;

    // disable move assignment operator
    Task &operator=(Task &&) = delete;

    // parameterized
    Task(std::string task, int days, int resource, TaskCategory category);

    // destructor
    ~Task() = default;

    std::string taskDescription() const { return _task_description; }

    int allocatedDays() const { return _allocated_days; }

    int allocatedResource() const { return _allocated_resource; }

    TaskCategory category() const { return _category; }

    friend std::ostream &operator<<(std::ostream &os, const Task &rhs);
};

std::string DisplayTask(TaskCategory type);

#endif // TASK_H
