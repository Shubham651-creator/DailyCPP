#include <iostream>
#include "SalesPerson.h"
#include"Manager.h"

int main()
{

    /*

        introduction of 'virtual' keyword to base class
        - The class which have Virtual function called POLYMORPHIC CLASS
        - It involves runtime polymorphism

    */
    Emp* eptr = new SalesPerson;
    eptr->display();
    delete eptr;

    Emp* eptr2 = new Manager;
    eptr2->display();

    // Manager m1(2023, "sanket", 340000, EmployeeType::INTERN, 3, 2000);
    // m1.display();
    // m1.calculateTotalSalary();

    // SalesPerson sp2(2023, "priya", 340000, EmployeeType::INTERN, 30000, 0.03);
    // sp2.display();
    // sp2.calculateTotalSalary();
    

    // SalesPerson* sp1 = new SalesPerson;
    // sp1->accept();
    // sp1->display();
    // delete sp1; //request to call destructor

    // Emp *e = new Emp();
    // e->accept();
    // e->display();
    // e->calculateTotalSalary();

    return 0;
}