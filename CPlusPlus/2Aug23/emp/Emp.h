#ifndef EMP_H
#define EMP_H

#include <iostream>

enum class EmployeeType //defines employee enum
{
    PERMANANT,
    TEMP,
    INTERN,
};

class Emp
{
private:
    int empid;
    std::string ename;
    double basicSalary;
    double houseRentAllowence, medicalAllowance, professionalTax, providentFund;
    enum EmployeeType enumType;

    void calculateAllowance();

public:
    Emp(int, std::string, double, EmployeeType);
    Emp();

    void accept();
    void display();
    double calculateTotalSalary();
};

#endif // EMP_H
