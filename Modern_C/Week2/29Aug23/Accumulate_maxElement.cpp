#include <vector>
#include <functional>
#include <memory>
#include <algorithm>
#include <numeric>
#include "../28Aug23/Employee.h"

using Pointer = std::unique_ptr<Employee>;
using SmartContainer = std::vector<Pointer>;
using RegularContainer = std::vector<Employee *>;

int main()
{
    RegularContainer regularData{
        new Employee(101, 340000.9f),
        new Employee(102, 55000.8f)};

    SmartContainer smartData;

    // push back use only we already made objects
    //  emplace back use we want to create object
    smartData.push_back(std::make_unique<Employee>(103, 68485.0f));
    smartData.push_back(std::make_unique<Employee>(104, 58485.0f));
    smartData.push_back(std::make_unique<Employee>(105, 78485.0f));

    // total salary of employee RegularContainer
    float totalSalary = std::accumulate(
        regularData.begin(),
        regularData.end(),
        0.0f,
        [](float ans, Employee *emp){ return ans = ans + emp->getSalary(); }
    );
    std::cout << "Total salary is " << totalSalary << '\n';

    // total salary of employee RegularContainer
    float totalSalaryBySmart = std::accumulate(
        smartData.begin(),
        smartData.end(),
        0.0f,
        [](float ans, Pointer &emp) { return ans + emp->getSalary(); }
    );
    std::cout << "Total salary by smart pointer is " << totalSalaryBySmart << '\n';

    // find employee with max salary by RAW POINTER 
    RegularContainer::iterator e5 = std::max_element(
        regularData.begin(),
        regularData.end(),
        // comparetor function , return bool 
        [](Employee *e1, Employee *e2) { return e1->getSalary() < e2->getSalary(); }
    );
    std::cout<<**e5<<'\n';

    // find employee with max salary by SMART POINTER 
    SmartContainer::iterator position_itr = std::max_element(
        smartData.begin(),
        smartData.end(),
        // comparetor function , return bool 
        [](Pointer& e1, Pointer& e2) { return e1->getSalary() < e2->getSalary(); }
    );
    std::cout<<**position_itr<<'\n';

    return 0;
}