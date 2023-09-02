// VARIANT - finit Object Wrapper 
// Visitor pattern coding

/*
    > g++ -std=c++17 variant.cpp
*/

/*
    Inheritance mainly used to find and implement
    common behaviour with child class.

*/

#include <iostream>
#include <variant>
#include <memory>

struct Employee
{
    void CalculateTax()
    {
        std::cout << "Employee pay 15% tax \n";
    }
};

struct BusinessOwner
{
    void CalculateTax()
    {
        std::cout << "BusinessOwner pay 35% tax \n";
    }
};

using EmployeePointer = std::unique_ptr<Employee>;
using BusineesOwnerPointer = std::unique_ptr<BusinessOwner>;

int main()
{
    // stack object
    std::variant<Employee, BusinessOwner> v1 ;
    v1 = Employee();

    // access variant and call calculatetax for employee
    // here, auto&& is forwarded reference
    std::visit(   [](auto &&val) { val.CalculateTax(); },
               v1);

    v1 = BusinessOwner();

    // access variant and call calculatetax for BusinessOwner
    std::visit(   [](auto &&val) { val.CalculateTax(); },
               v1);

    //============================================================

    //smart pointer object
    std::variant<EmployeePointer, BusineesOwnerPointer> v2;

    v2 = std::make_unique<Employee>();
    std::visit(   [](auto &&val) { val.CalculateTax(); },
               v1);

    v2 = std::make_unique<BusinessOwner>();
    std::visit(   [](auto &&val) { val.CalculateTax(); },
               v1);

}

/*
    variant<   Employee    |    BusinessOwner   >
                [ v1 ]             [UNUSED]

    std::variant<Employee, BusinessOwner> v1 = Employee();    

*/