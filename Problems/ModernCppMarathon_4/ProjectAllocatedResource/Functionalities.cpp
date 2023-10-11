#include "Functionalities.h"
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

void CreateObjects(projectContainer &projectObject)
{
    projectObject[0] = std::make_shared<ProjectAllocatedResource>(
        "101a",
        "shubham",
        std::list<taskPointer>{
            std::make_shared<Task>("Referesh the functionalities of login",
                                   1, 1, TaskCategory::BUG_FIX),
            std::make_shared<Task>("Referesh the functionalities of front page",
                                   2, 2, TaskCategory::BUG_FIX),
        },
        2000.0f,
        10000.f);

    projectObject[1] = std::make_shared<ProjectAllocatedResource>(
        "102a",
        "Rasika",
        std::list<taskPointer>{
            std::make_shared<Task>("Modify the functionalities of login",
                                   2, 2, TaskCategory::REFACTOR),
            std::make_shared<Task>("Modify the functionalities of front page",
                                   3, 2, TaskCategory::REFACTOR),
        },
        3000.0f,
        20000.f);

    projectObject[2] = std::make_shared<ProjectAllocatedResource>(
        "103a",
        "Sanket",
        std::list<taskPointer>{
            std::make_shared<Task>("Altered the functionalities of login",
                                   3, 3, TaskCategory::FEATURE_ADDITION),
            std::make_shared<Task>("Alterd the functionalities of front page",
                                   4, 4, TaskCategory::FEATURE_ADDITION),
            std::make_shared<Task>("Alterd the functionalities of back page",
                                   7, 7, TaskCategory::FEATURE_ADDITION),
        },
        2000.0f,
        50000.f);

    projectObject[3] = std::make_shared<ProjectAllocatedResource>(
        "104a",
        "Anita",
        std::list<taskPointer>{
            std::make_shared<Task>("Discard the functionalities of login",
                                   5, 5, TaskCategory::REFACTOR),
            std::make_shared<Task>("Discard the functionalities of front page",
                                   6, 6, TaskCategory::REFACTOR),
        },
        6000.0f,
        30000.f);
}

void ThreeAllocatedTask(projectContainer &projectObject)
{
    // check whether container empty or not
    if (projectObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int count = std::count_if(
        projectObject.begin(),
        projectObject.end(),
        [&](projectPointer &obj)
        {
            return obj.get()->tasks().size() > 2;
        });

    std::cout << "The count of task intances whose at least have 3 task\n"
              << count << "\n\n";
}

projectPointer HighestExpenseCap(projectContainer &projectObject)
{
    // check whether container empty or not
    if (projectObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    auto maxItr = std::max_element(
        projectObject.begin(),
        projectObject.end(),
        [](projectPointer &obj1, projectPointer &obj2)
        {
            return obj1.get()->expenseCap() <
                   obj2.get()->expenseCap();
        });

    if (maxItr == projectObject.end())
    {
        std::cout << "not found\n";
    }

    return *maxItr;
}

bool AllInstanceBugFix(projectContainer &projectObject)
{
    // check whether container empty or not
    if (projectObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    return std::all_of(
        projectObject.begin(),
        projectObject.end(),
        [&](projectPointer &obj)
        {
            return std::any_of(
                obj.get()->tasks().begin(),
                obj.get()->tasks().end(),
                [](taskPointer &taskObj)
                {
                    taskObj.get()->category() == TaskCategory::BUG_FIX;
                });
        });
}

std::vector<TaskCategory> MaxBillOfEveryProject(projectContainer &projectObject)
{
    // check whether container empty or not
    if (projectObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    std::vector<TaskCategory> storeEnum;
    projectContainer store;

    auto maxItr = std::max_element(
        projectObject.begin(),
        projectObject.end(),
        [](projectPointer &obj1, projectPointer &obj2)
        {
            return obj1.get()->billingAmount() <
                   obj2.get()->billingAmount();
        });

    for (auto &itr : maxItr->get()->tasks())
    {
        storeEnum.push_back(itr.get()->category());
    }

    return storeEnum;
}

projectContainer SortedContainer(projectContainer &projectObject)
{
    // check whether container empty or not
    if (projectObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    projectContainer result;

    result = projectObject;

    std::sort(
        result.begin(),
        result.end(),
        [](projectPointer &obj1, projectPointer &obj)
        {
            return obj1.get()->expenseCap() <
                   obj.get()->expenseCap();
        });

    return result;
}
