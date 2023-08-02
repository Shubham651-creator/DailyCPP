#ifndef EMP_H
#define EMP_H

#include <iostream>

enum class EmployeeType // defines employee enum
{
    PERMANANT,
    TEMP,
    INTERN,
};

class Emp
{

protected:
    double basicSalary;

private:
    int empid;
    std::string ename;
    double houseRentAllowence, medicalAllowance, professionalTax, providentFund;
    enum EmployeeType enumType;

    void calculateAllowance();

public:
    Emp(int, std::string, double, EmployeeType);
    Emp();
    virtual ~Emp();

    virtual void accept();
    virtual void display();
    virtual double calculateTotalSalary();
};

#endif // EMP_H
