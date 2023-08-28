#include <iostream>
#include <functional>
#include <memory>
#include "Employee.h"
#include <vector>

using Pointer = std::unique_ptr<Employee>;

int main()
{
    std::vector<Pointer> data;
    auto e1 = std::make_unique<Employee>(102, 200000.0f);
    data.push_back(std::make_unique<Employee>(102, 200000.0f));
    data.push_back(std::make_unique<Employee>(103, 300000.0f));
    data.push_back(std::make_unique<Employee>(104, 400000.0f));
    data.push_back(std::make_unique<Employee>(105, 600000.0f));
    data.push_back(std::make_unique<Employee>(101, 100000.0f));

    data.push_back(std::move(e1));

    return 0;
}