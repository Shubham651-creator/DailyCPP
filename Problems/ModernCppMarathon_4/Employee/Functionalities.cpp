#include "Functionalities.h"
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

void CreateObjects(Container &empObjects)
{
    empObjects[0] = std::make_shared<Employee>(
        101, "Shubham", 25000.0f,
        std::make_shared<System>(MemoryType::_8GB, 500.0f, "abc101"),
        21, DepartmentType::IT, 1);

    empObjects[1] = std::make_shared<Employee>(
        102, "Rasika", 26000.0f,
        std::make_shared<System>(MemoryType::_16GB, 600.0f, "abc102"),
        22, DepartmentType::IT, 2);

    empObjects[2] = std::make_shared<Employee>(
        103, "Shreya", 27000.0f,
        std::make_shared<System>(MemoryType::_8GB, 700.0f, "abc103"),
        23, DepartmentType::ACCOUNTS, 3);

    empObjects[3] = std::make_shared<Employee>(
        104, "Sanket", 45000.0f,
        std::make_shared<System>(MemoryType::_16GB, 800.0f, "abc104"),
        24, DepartmentType::ACCOUNTS, 4);

    empObjects[4] = std::make_shared<Employee>(
        105, "Harshu", 55000.0f,
        std::make_shared<System>(MemoryType::_32GB, 900.0f, "abc105"),
        25, DepartmentType::IT, 5);
}

float AverageSalaryOfIT(Container &empObjects)
{
    // check whether conatiner is empty or not.
    if (empObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int count = 0;
    float sum = std::accumulate(
        empObjects.begin(),
        empObjects.end(),
        0.0f,
        [&](float &ans, auto &obj)
        {
            if (DepartmentType::IT == obj.get()->department())
            {
                count++;
                return ans + obj.get()->salary();
            }

            return ans + 0.0f;
        });

    return sum / count;
}

// print full details not just salary
void HighestSalary(Container &empObjects)
{
    // check whether conatiner is empty or not.
    if (empObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    auto maxItr = std::max_element(
        empObjects.begin(),
        empObjects.end(),
        [](Pointer &obj1, Pointer &obj2)
        {
            return obj1.get()->salary() <
                   obj2.get()->salary();
        });

    std::cout << "Highest Salary is "
              << **maxItr
              << "\n\n";
}

bool AgeAbove25OrNot(Container &empObjects)
{
    // check whether conatiner is empty or not.
    if (empObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    return std::all_of(
        empObjects.begin(),
        empObjects.end(),
        [](Pointer &obj)
        {
            return obj.get()->age() > 25;
        });
}

std::optional<Container> MatchingAllConditions(Container &empObjects)
{
    // check whether conatiner is empty or not.
    if (empObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    Container result;

    std::copy_if(
        empObjects.begin(),
        empObjects.end(),
        result.begin(),
        [&](Pointer &obj)
        {
            auto store = obj.get()->system().get()->memory();
            return store == MemoryType::_16GB ||
                   obj.get()->department() == DepartmentType::IT ||
                   obj.get()->department() == DepartmentType::ACCOUNTS;
        });

    return std::make_optional(result);
}

float FindSalaryOfId(Container &empObjects, int passedId)
{
    // check whether conatiner is empty or not.
    if (empObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    auto itr = std::find_if(
        empObjects.begin(),
        empObjects.end(),
        [&](Pointer &obj)
        {
            return obj.get()->id() == passedId;
        });

    if (itr == empObjects.end())
    {
        std::cout << "Not found\n";
    }
    return itr->get()->salary();
}

int CountInstances(Container &empObjects)
{
    // check whether conatiner is empty or not.
    if (empObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    return std::count_if(
        empObjects.begin(),
        empObjects.end(),
        [](Pointer &obj)
        {
            return obj.get()->salary() > 8000.0f &&
                   obj.get()->age() < 30;
        });
}
