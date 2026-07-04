#include <iostream>
#include <functional>
#include <list>

/*
    I want to create a list 3 functions

    a. a lambda function that take an integer, returns it square
    b. a global function (top-level function) that takes an integer,
    returns its factorial
    (return -1 if integer is negative or greater than 10)
    c. a temporary function to take an integer and return its cube.

*/

using FunctionType = std::function<int(int)>;

int factorial(int number)
{
    // return -1 if integer is negative or > 10
    if (number > 0 && number < 10)
    {
        if (number == 1)
            return 1;
        return number * factorial(number - 1);
    }

    return -1;
}

int main()
{
    std::list<FunctionType> data;
    FunctionType f1 = [](int number){return number*number;};

    //pass by direct function addr
    data.push_back(&factorial);

    //pass by storing function warpper into f1
    data.push_back(f1);

    //pass by direct temporary function by making
    //temporary cube function
    data.push_back([](int n){return n*n*n;});


    for(FunctionType& fn : data){
        std::cout<< fn(7)<<'\n';
    }
}

 