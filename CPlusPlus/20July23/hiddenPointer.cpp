#include <iostream>

//'this' pointer holds address of current object
//'this' pointer is passed to every non-static member function of a class

class employee
{

    int empid;
    int salary;
    std::string ename; // ename is object of string class

public:
    // default constructor
    employee()
    { // implicit constructor

        empid = 218381;
        salary = 25000;
        ename = "shubham";
    }

    // parametrized constructor
    employee(int empid, int salary, std::string ename)
    { // these three are local variable

        //'this' remove shadowing effect i.e. empid = empid
        this->empid = empid;
        this->salary = salary;
        this->ename = ename;
    };

    void show()
    {

        std::cout << empid << " " << salary << " " << ename << std::endl;
        // this->salary, 'this' is hidden keyword
    }
};

// client code
int main()
{

    employee e1;
    e1.show();
    employee e2(218382, 15000, "Shreya");
    e2.show();
    return 0;
}