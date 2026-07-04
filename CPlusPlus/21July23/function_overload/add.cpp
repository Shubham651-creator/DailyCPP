#include <iostream>

// Default value argument towards functions
// always goes from right(traling argument) to left

int add(int a, int b, int c, int d)
{
    return a + b + c + d;
}
int add(int a, int b, int c)
{
    return a + b + c;
}
int add(int a, int b =0)
{
    return a + b;
}

int main()
{

    std::cout << "add(10,20,30,40): " << add(10, 20, 30, 40) << "\n";
    std::cout << "add(10, 20, 30): " << add(10, 20, 30) << "\n";
    std::cout << "add(10, 20): " << add(10, 20) << "\n";
    std::cout << "add(10): " << add(10) << "\n";

    return 0;
}