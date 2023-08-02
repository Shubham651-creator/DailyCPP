#ifndef SALESPERSON_H
#define SALESPERSON_H

#include <iostream>
#include "Emp.h"

// public: inherting Salesperson class from Employee class in public mode
// mode of inheritance
class SalesPerson : public Emp
{
    double salesAmount, commisionRate;

    public:
    SalesPerson();
    SalesPerson(int eid, std::string name, double bSalary, EmployeeType etype, double salesamount, double rate );
    ~SalesPerson();
    void display();
    void accept();
    double calculateTotalSalary();
};

 
#endif // SALESPERSON_H
