#ifndef MANAGER_H
#define MANAGER_H

#include<iostream>
#include"Emp.h"

class Manager : public Emp
{
private:
    int numberOfSubordinates;
    double incentive;
public:
Manager();
    Manager(int eid, std::string name, double bSalary, EmployeeType etype, int subordinate, double incentive);
    ~Manager();
    void accept();
    void display();
    double calculateTotalSalary();
};

#endif // MANAGER_H
