#include <iostream>
/*
    Use of const keyword:

    1. It is applied to whatever is on its immedite left.
       If there is nothing to the left of const, 
       apply const to the TOKEN on the immediate right.

    2. * is also a TOKEN
*/

int main()
{

    int n1 = 10;
    int n2 = 99;

    // case 1:

    const int *ptr = &n1;  // ptr is pointer to a CONSTANT INTEGER.
    int const *ptr2 = &n1; // ptr is pointer to a CONSTANT INTEGER.

    // *ptr = 11; //error : can not assign value to const integer.
    ptr = &n2;

    //=================================================================

    // case 2:

    int *const ptr3 = &n1; // ptr3 is CONSTANT POINTER to an integer
    // ptr3 = &n2; //error : can not assign address to const pointer
    *ptr3 = 77; // assign value to pointer value

    //=================================================================

    // case 3:

    const int *const ptr4 = &n1; // ptr4 is CONSTANT POINTER to CONSTANT INTEGER.
    // *ptr4 = 11; //error : can not assign value to const integer.
    // ptr4 = &n2; //error : can not assign address to const pointer

    return 0;
}