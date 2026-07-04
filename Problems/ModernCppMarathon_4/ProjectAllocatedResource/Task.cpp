#include "Task.h"

std::ostream &operator<<(std::ostream &os, const Task &rhs)
{
    os << "_task_description: " << rhs._task_description
       << " _allocated_days: " << rhs._allocated_days
       << " _allocated_resource: " << rhs._allocated_resource
       << " _category: " << DisplayTask(rhs._category);
    return os;
}

std::string DisplayTask(TaskCategory type)
{
    if (type == TaskCategory::FEATURE_ADDITION)
    {
        return "FEATURE_ADDITION";
    }
    if (type == TaskCategory::BUG_FIX)
    {
        return "BUG_FIX";
    }
    return "REFACTOR";
}

Task::Task(std::string task, int days, int resource, TaskCategory category)
    : _task_description(task), _allocated_days(days),
      _allocated_resource(resource), _category(category)
{
    if (task.size() < 10)
    {
        throw std::runtime_error("Invalid string\n");
    }

    if (days > 10)
    {
        throw std::runtime_error("Days must be less than 10\n");
    }
}
