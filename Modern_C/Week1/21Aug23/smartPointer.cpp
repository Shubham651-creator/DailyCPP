#include <iostream>
#include "Employee.h"

/*
        [100]
        0x234H

        int * ptr = new int(100);

        employee object ePtr
        [Shubhbam | 22 | male ]
        0x487H ......

        Employee* ePtr = new Employee(Shubhbam , 22 , male);
*/

// RAII = Resource Acqusition Is Intialization
//  or
// SBRM = Scope Based Resource Managment
/*
    1. I still want to heap memory
    2. I want complier to take control of memory and release it
    when "it is no longer required".
          ------------------------
    3. I would still appreciate ability to manually relase MEMORY.
    4. My resource access may be unique or shared access or STALKER(weak pointerz) access!!
*/

#include <memory>
#include<list>

using Container = std::list<std::unique_ptr<Employee>>;

void CreateObjects(Container& data){

    //temporary push back!
    data.push_back(std::make_unique<Employee>(101));
}

int main()
{
    Employee *raw = new Employee(101,"shubam");                              // raw pointer
    std::unique_ptr<Employee> e1 = std::make_unique<Employee>(101); // unique smart pointer
    std::shared_ptr<Employee> share2 = std::make_shared<Employee>(202); // shared smart pointer

    Employee *ptr = e1.release(); // store address of pointer into ptr
    e1.reset(raw);  // now we managed raw pointer and e1 pointer is deleted.
    //e1.reset(nullptr); //delete the e1 pointer

    return 0;
}

/*
    std::unique_ptr<Employee> ---------> a template class
    e1 : object of template class!!

    std::make_unique<Employee> ----------> maker function or relay function
                                            (sends value to constructor)


    RAII (smart pointer ): Resource(memeory, file, database) Acquisition is Initialization
*/