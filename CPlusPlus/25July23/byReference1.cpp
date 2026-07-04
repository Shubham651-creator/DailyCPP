#include <iostream>

int c = 10;

int &fun()
{
    int a = 20;
    return c;

    //return a; // runtime error
    //because function returns refernce of variable, but if you return local variables
    //it won't exist after end of function, but for global its works.
}
int main()
{
    int b = fun();
    std::cout << "the value of b = " << b << "\n";
    return 0;
}