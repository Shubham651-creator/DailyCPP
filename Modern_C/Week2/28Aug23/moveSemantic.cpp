#include <iostream>
#include <functional>
#include <memory>
#include "Employee.h"
#include <vector>

using Pointer = std::unique_ptr<Employee>;

/*
    Const Correctness Rule :
*/

void MappingFunction(std::vector<Pointer> &data,
                     const std::function<float(const Pointer &)> &fn)
{
    for (Pointer &val : data)
    {
        std::cout << fn(val) << '\t'; // map fn ON TO val
    }
    std::cout << '\n';
}

int main()
{
    std::vector<Pointer> data;
    Pointer e1 = std::make_unique<Employee>(102, 200000.0f);

    data.push_back(std::make_unique<Employee>(102, 200000.0f));
    data.push_back(std::make_unique<Employee>(103, 300000.0f));
    data.push_back(std::make_unique<Employee>(104, 400000.0f));
    data.push_back(std::make_unique<Employee>(105, 600000.0f));
    data.push_back(std::make_unique<Employee>(101, 100000.0f));

    data.push_back(std::move(e1));

    // e1 = nullptr;
    // std::cout << *e1 << '\n'; // segmentation fault

    MappingFunction(data, &CalculateTax);

    MappingFunction(data, [](const Pointer &obj)
                    { return obj->getSalary() * 0.25f; });

    MappingFunction(data, [](const Pointer &obj)
                    { return obj->getSalary() * 0.5f; });

    return 0;
}