#include <iostream>

// instance - object of a class
// private - data security

class employee
{

    // attribute/data member/ instance member
    int empid;
    int salary;
    std::string ename; // ename is object of string class

public:
    employee()
    { // implicit constructor
        empid = 218381;
        salary = 25000;
        ename = "shubham";
    }

    // void setValue(){ //explicit constructor
    //     empid = 218381;
    //     salary = 25000;
    //     ename = "shubham";
    // }

    // interface has to be accessible and public
    // in cpp interface is same as function
    void show()
    {

        std::cout << empid << " " << salary << " " << ename << std::endl;
        // this->salary, 'this' is hidden keyword
    }
};

// client code
int main()
{

    employee e1; // instance/object
    // e1.setValue();  //explicitly calling and its implicit call is 'Constructor'.
    e1.show();
    return 0;
}