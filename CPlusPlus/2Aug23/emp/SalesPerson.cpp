#include <iostream>
#include "SalesPerson.h"

SalesPerson::SalesPerson()
{
    std::cout << "\ndefult constructor salesperson called\n";
    salesAmount = 120000;
    commisionRate = 0.05;
    basicSalary = 57740;
}

SalesPerson::SalesPerson(int eid, std::string name, double bSalary, EmployeeType etype, double salesamount, double rate)
    : Emp(eid, name, bSalary, etype), salesAmount(salesamount), commisionRate(rate) // entry level - member initialzer list
{
}

SalesPerson::~SalesPerson()
{
    std::cout << "\nsaleperson destructor called\n";
}

void SalesPerson::display()
{
    Emp::display(); // to display the employee class
    std::cout << "salesAmount = " << salesAmount
              << "\n Commision rate = " << commisionRate << "\n"
              << "Total salesperson salary= " << SalesPerson::calculateTotalSalary() << "\n";
}

void SalesPerson::accept()
{

    Emp::accept(); // to accept attribute of base employee class
    std::cout << "\nEnter Sales Amount = ";
    std::cin >> salesAmount;
    std::cout << "\n Enter Commsion Rate = ";
    std::cin >> commisionRate;
}

double SalesPerson::calculateTotalSalary()
{
    return Emp::calculateTotalSalary() + salesAmount * commisionRate;
}
