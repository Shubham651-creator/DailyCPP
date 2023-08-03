#include <iostream>
#include "SalesPerson.h"
#include "Manager.h"

void showMeun(Emp *ep)
{
    ep->display();
    std::cout << "\nTotal salary = " << ep->calculateTotalSalary() << "\n";

    // RTTI - Run Time Type Identification
    if (typeid(*ep) == typeid(SalesPerson))
    {
        SalesPerson *s = dynamic_cast<SalesPerson *>(ep);
        if (s != 0) // or (s!=nullptr)
            s->calculateCommision();
        else
            std::cout << "\n Type cast failed\n";
    }
    else if (typeid(*ep) == typeid(Manager))
    {
        Manager *mg = dynamic_cast<Manager *>(ep);
        mg->calculateIncentive();
    }

    delete ep;
}

int main()
{

    // showMeun(new Emp);
    // showMeun(new SalesPerson);
    // showMeun(new Manager);

    /*

        introduction of 'virtual' keyword to base class
        - The class which have Virtual function called POLYMORPHIC CLASS
        - It involves runtime polymorphism

    */

    Emp *eptr = new SalesPerson;

    SalesPerson *sp = dynamic_cast<SalesPerson *>(eptr); // dynamic typecast
    eptr->display();
    sp->calculateCommision(); // access child special function

    Emp *eptr2 = new Manager;
    Manager *mg = dynamic_cast<Manager *>(eptr2);
    mg->display();
    mg->calculateIncentive();
    delete eptr;
    delete eptr2;

    //----------------------------------------------------------------------------------------

    // Emp* eptr2 = new Manager;
    // eptr2->display();

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