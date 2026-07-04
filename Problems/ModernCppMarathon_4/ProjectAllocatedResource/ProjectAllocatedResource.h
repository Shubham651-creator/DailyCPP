#ifndef PROJECTALLOCATEDRESOURCE_H
#define PROJECTALLOCATEDRESOURCE_H

#include <iostream>
#include <memory>
#include <list>
#include "Task.h"

// Pointer to Task class
using taskPointer = std::shared_ptr<Task>;

// list container of task
using taskContainer = std::list<taskPointer>;

class ProjectAllocatedResource
{
private:
    std::string _id;
    std::string _name;
    taskContainer _tasks;
    float _billing_amount;
    float _expense_cap;

public:
    // disable default constructor
    ProjectAllocatedResource() = delete;

    // disable copy constructor
    ProjectAllocatedResource(const ProjectAllocatedResource &) = delete;

    // disable copy assignment operator
    ProjectAllocatedResource &operator=(ProjectAllocatedResource &) = delete;

    // disable move constructor
    ProjectAllocatedResource(ProjectAllocatedResource &&) = delete;

    // disable move assignment operator
    ProjectAllocatedResource &operator=(ProjectAllocatedResource &&) = delete;

    // parameterized constructor
    ProjectAllocatedResource(std::string id, std::string name,
                             taskContainer task, float bill, float expense);

    // destructor
    ~ProjectAllocatedResource() = default;

    // getter of all attributes

    std::string id() const { return _id; }

    std::string name() const { return _name; }

    taskContainer tasks() const { return _tasks; }

    float billingAmount() const { return _billing_amount; }

    float expenseCap() const { return _expense_cap; }

    friend std::ostream &operator<<(std::ostream &os, const ProjectAllocatedResource &rhs);
};

#endif // PROJECTALLOCATEDRESOURCE_H
