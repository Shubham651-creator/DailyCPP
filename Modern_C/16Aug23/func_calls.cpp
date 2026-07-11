#include <iostream>

/*
        say,
        stack is automatic storage/ variable

        STATICALLY TYPED LANGUAGE - CPP
            - You can't change data-type of redefine variable

        DYAMICALLY TYPED LANGUEAGE - PYTHON
            - You can change data-type of redefine variable
*/

// 1. call by value
/*
    magic() takes one integer by value and return void
*/

//  void magic(int number)
//  {
//      std::cout << "Address fo number : " << &number << "\n";
//      std::cout << "Value of number :" << number << "\n";
//  }

// 2. call by reference
/*
    magic() that takes one integer reference and  returns void

    anything which is you give a name is 'lvalue'.

    temperary value(int, float, string, double) and doesnt have value in
    ram is 'rvalue'
*/

// void magic(int &number)
// {
//     int a = 20;
//     number = a;
//     std::cout << "Address fo number : " << &number << "\n";
//     std::cout << "Value of number :" << number << "\n";
// }


/* 
    3. 
    magic takes 1 interger pointer and returns an integer pointer
    The function should read input parameter number.

    Calcalate its squree and store it in a different location than input

    data-type& variable-name; //create a reference
    &variable-name ; //a pointer
*/

int *magic(int *ptr)
{
    int number = (*ptr); // deference ptr and store in  number

    int ans = number * number;

    return &ans;
}

int main()
{

    int n1 = 10;

    // magic(n1);
    // std::cout << "Address of n1 in main ::" << &n1 << "\n";
    // std::cout << "Value of n1 is :" << n1 << "\n";

    // Here your returning address of ans which is local variable 
    //and will be destroyed after function call. So, it will give garbage value.
    std::cout<< magic(&n1); 
    std::cout << "Address of n1 in main ::" << &n1 << "\n";
    std::cout << "Value of n1 is :" << n1 << "\n";

    return 0;
}