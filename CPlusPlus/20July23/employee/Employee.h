// ctrl+shift+P and type C-mantic-add header guard
// which applicable only in header file.

// motive to add header gurad is to we have multiple file with same name
// which lead to 'rename define error'.

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{

    int empid;
    int salary;
    std::string ename; // ename is object of string class

public:
    Employee();
    Employee(int empid, int salary, std::string ename);
    void show()const;

    int getEmpid() const { return empid; }
    void setEmpid(int empid_) { empid = empid_; }

    int getSalary() const { return salary; }
    void setSalary(int salary_) { salary = salary_; }

    std::string getEname() const { return ename; }
    void setEname(const std::string &ename_) { ename = ename_; }
};

#endif // EMPLOYEE_H
