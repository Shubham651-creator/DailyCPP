#include <iostream>
#include "CarNew.h"
#include "CarCategoryNew.h"
#include <vector>
#include <array>

// equivalent to typedef
// using newName = oldName
using category = CarCategoryNew;
 
void magic(CarNew obj){
    obj.display();
}

int main()
{
    CarNew c1(2) ;
    // c1.display();

    magic(c1);
    // magic(100);

    int *ptr = NULL;    //#define NULL 0
    int *p = nullptr;
    //std::cout<<"pointer: "<<*ptr <<"\n"; //undefined behaviour - UB

    auto n1 = 10;

    // vector of array
    std::vector<std::array<int, 5>> data;

    return 0;
}
 