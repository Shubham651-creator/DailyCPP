#include <iostream>

//implementation of 'enum' without 'enum class'
//now what we get problems let's see

enum GEAR
{
    FIRST,
    SECOND,
    THIRD
};
enum RANK
{
    FIRST,
    SECOND,
    THIRD
};

void magic(enum GEAR gr)
{
    std::cout << gr << "\n";
}

void takeInteger(int number)
{
    std::cout << "You are in integer function \n "
              << "\n";
}

int main()
{
    // issue 1 : writing literals without enum name prefix
    enum RANK r1 = RANK::FIRST;
    enum GEAR g1 = GEAR::FIRST;

    // issue 2 : 2 enums of different categories are comparable if they
    // have same integer values

    if (r1 == g1)
        std::cout << "allowed \n";
    else
        std::cout << "NOt allowed \n";

    // issue 3 : implicit conversion of enum into integer
    takeInteger(g1);

    return 0;
}