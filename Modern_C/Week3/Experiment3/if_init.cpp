#include <iostream>

/*
    "if-init" concept:

        (since c++17) We can declare and initialize if-else
        variable with conditions itself.
*/

int main()
{

    if (int i = 12; i < 10)
    {
        std::cout << "i is less than 10\n";
    }
    else
    {
        std::cout << "i is MORE than 10\n";
    }
}