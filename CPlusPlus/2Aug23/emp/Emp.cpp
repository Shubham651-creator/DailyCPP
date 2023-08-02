#include <iostream>
#include "Emp.h"

void Emp::calculateAllowance()
{
    houseRentAllowence = basicSalary * 0.05;
    medicalAllowance = basicSalary * 0.05;
    professionalTax = 2500;
    providentFund = 1700;
}

Emp::Emp(int eid, std::string name, double bSalary, EmployeeType etype)
    : empid(eid), ename(name), basicSalary(bSalary), enumType(etype) // member initialzer list
{
    calculateAllowance();
}

Emp::Emp()
{
    empid = 101;
    ename = "Shubham";
    basicSalary = 25000;
    calculateAllowance();
    enumType = EmployeeType::INTERN;
}

void Emp::accept()
{
    std::cout<<"\nEnter Employee id, name, Basic salary respectively,\n";
    std::cin>>empid>>ename>>basicSalary;
    std::cout<<"\nselect emplyee category as 1.PERMANANT 2.TEMP 3.INTERN\n";
    int ecat;
    std::cin>>ecat;
    switch (ecat)
    {
    case 1:
        enumType = EmployeeType::PERMANANT;
        break;

    case 2:
        enumType = EmployeeType::TEMP;
        break;

    case 3:
        enumType = EmployeeType::INTERN;
        break; 
    }
}

std::string getEmpType(EmployeeType et){
    if(et == EmployeeType::PERMANANT) return "PERMANANT";
    if (et == EmployeeType::TEMP)return "temperory";
    else return "intern";
}

void Emp::display()
{
    std::cout<<"\nemp id = "<<empid
    <<"\nemp name = "<<ename
    <<"\nemployee basic salary = "<<basicSalary
    <<"\nemplyee type = "<<getEmpType(enumType)
    <<"\nIn hand salary = "<<calculateTotalSalary()<<"\n\n";
}

double Emp::calculateTotalSalary()
{
    return basicSalary - (providentFund+houseRentAllowence+medicalAllowance);
}