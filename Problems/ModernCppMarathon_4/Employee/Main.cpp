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

int main()
{

    Container empObjects;

    try
    {
        CreateObjects(empObjects);

        // display all objects
        for (auto &value : empObjects)
        {
            std::cout << *value << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "The averge of IT instance = "
                  << AverageSalaryOfIT(empObjects)
                  << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        HighestSalary(empObjects);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Whether all instance abbove 25 or not. = "
                  << AgeAbove25OrNot(empObjects)
                  << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << " check all condition function \n";

        auto result = MatchingAllConditions(empObjects);

        if (result.has_value())
        {
            auto store = result.value();
            for (auto &value : store)
            {
                std::cout << *value << "\n\n";
            }
        }
        else
        {
            std::cout << "result no matching this condition\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Find salry whose id is passed\n"
                  << FindSalaryOfId(empObjects, 103)
                  << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "count the instance \n"
                  << CountInstances(empObjects)
                  << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}