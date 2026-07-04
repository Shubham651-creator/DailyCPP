#include <iostream>
#include "Manager.h"

Manager::Manager()
{
    std::cout << "\nmanager default constructor called\n";
    numberOfSubordinates = 4;
    incentive = 5000;
}
Manager::Manager(int eid, std::string name, double bSalary, EmployeeType etype, int subordinate, double incentive)
    : Emp(eid, name, bSalary, etype), numberOfSubordinates(subordinate), incentive(incentive)
{
    std::cout << "\nmanager(....) constructor called\n";
}

Manager::~Manager()
{
    std::cout << "\nmanager ~destrutor called\n";
}

void Manager::accept()
{
    Emp::accept();
    std::cout << "\nEnter number of subordinate = ";
    std::cin >> numberOfSubordinates;
    std::cout << "\n Enter incentive =";
    std::cin >> incentive;
}

void Manager::display()
{
    Emp::display();
    std::cout << "Number of subordinate = " << numberOfSubordinates
              << "\n incentive = " << incentive
              << "\n total salary of manager = " << Manager::calculateTotalSalary() << "\n";
}

double Manager::calculateTotalSalary()
{
    return Emp::calculateTotalSalary() + numberOfSubordinates * incentive;
}
void Manager::calculateIncentive() // child special function
{
    std::cout << "\nManager total incentive= " << numberOfSubordinates * incentive << "\n";
}