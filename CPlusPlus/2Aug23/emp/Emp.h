#ifndef EMP_H
#define EMP_H

//if class has all pure virtual function, then class is called Pure virtual class

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

    // pure virtual function
    // i.e. employee class is abstract class
    //  we won't be able to create object, but we should make pointer and reference
    // we must have to implement the body in derived class
    //other than abstract class is concrete class
    virtual void fun() = 0;
};

#endif // EMP_H
