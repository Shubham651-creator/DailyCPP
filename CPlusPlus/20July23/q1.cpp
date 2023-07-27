/* create a class Employee with the following attribute

    -employeeId which  could be a alphanumeric value
    -employeeSalary which could be a float value
    -employeeLocation which could be a string
    -employeeCategory which could be either INTERN, FTE, CONTRACTED
        //categorical data means use 'enum'

    - a default constructor
    - a parameterized constructor
    - a function to calculate 10% of salary as tax  */

#include <iostream>
enum empCategory
    {
        INTERN = 0,
        FTE = 1,
        CONTRACTED = 2
    };


class Employee
{

public:
    std::string empId;
    float empSalary;
    std::string empLocation;
    enum empCategory e1;

    // default constructor
    Employee()
    {
        empId = "shubam@651";
        empSalary = 12000.00;
        empLocation = "Pune";
        e1=empCategory::INTERN;
    }

    // parameter constructor
    Employee(std::string id, float salary, std::string location)
    {
        empId = id;
        empSalary = salary;
        empLocation = location;
        enum empCategory e;
    
    }
};

int main()
{

    return 0;
}