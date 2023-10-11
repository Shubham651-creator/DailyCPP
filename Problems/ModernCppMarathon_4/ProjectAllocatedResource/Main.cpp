#include <iostream>
#include <memory>
#include <list>
#include <array>
#include <optional>
#include <algorithm>
#include <numeric>
#include "Task.h"
#include "ProjectAllocatedResource.h"
#include "Functionalities.h"

// Pointer to Task class
using taskPointer = std::shared_ptr<Task>;

// list container of task
using taskContainer = std::list<taskPointer>;

// Pointer to ProjectAllocated class
using projectPointer = std::shared_ptr<ProjectAllocatedResource>;

// array container of 4 instacne
using projectContainer = std::array<projectPointer, 4>;

int main()
{

    projectContainer projectObject;

    try
    {
        CreateObjects(projectObject);

        for (auto &value : projectObject)
        {

            std::cout << *value << "\n\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << *HighestExpenseCap(projectObject)
                  << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\n\nWhether all instance has one bug fix\n"
                  << AllInstanceBugFix(projectObject) << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "max instance of all enum class\n";

        for (auto &value : MaxBillOfEveryProject(projectObject))
        {
            std::cout << DisplayTask(value) << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "\n\nsort according to expense cap:\n";
        for (auto &value : SortedContainer(projectObject))
        {
            std::cout << *value << '\n';
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}