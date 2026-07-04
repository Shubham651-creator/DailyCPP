#include "ProjectAllocatedResource.h"

std::ostream &operator<<(std::ostream &os, const ProjectAllocatedResource &rhs)
{
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _tasks: ";

    for (auto &value : rhs._tasks)
    {
        os << *value << "\n";
    }

    os << " _billing_amount: " << rhs._billing_amount
       << " _expense_cap: " << rhs._expense_cap;
    return os;
}

ProjectAllocatedResource::ProjectAllocatedResource(
    std::string id, std::string name, taskContainer task,
    float bill, float expense)
    : _id(id), _name(name), _tasks(task), _billing_amount(bill), _expense_cap(expense)
{
}
