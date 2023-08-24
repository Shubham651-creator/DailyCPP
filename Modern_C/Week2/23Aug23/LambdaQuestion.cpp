#include <iostream>
#include <vector>
#include <list>
#include <functional>

/*
    create 2 lambda functions
    a. f1 : which is a function to take int, return square
    b. f2 : which is a function to take int, return cube

    create a vector of 5 integer [10,20,30,40,50]

    Now, run the code to produce the following output
    squre cube

    100  1000
    400  8000
    9000 270000 ...
*/

using FunctionType = std::function<int(int)>;

int main()
{

    std::vector<int> data{10, 20, 30, 40, 50};

    FunctionType f1 = [](int n) { return n * n; };
    FunctionType f2 = [](int n) { return n * n * n; };

    std::list<FunctionType> fns{f1, f2};

    std::cout<<"method 1:\n";
    for (int value : data)
    {
        for (FunctionType &fn : fns)
        {
            std::cout << fn(value) << "\t";
        }
        std::cout << "\n";
    }

    std::cout<<"\nmethod 2:\n";
    for(int value : data){
        std::cout<<[](int n) { return n * n; }(value)
        <<"\t"
        <<[](int n) { return n * n * n; }(value)
        <<"\n";
    }
}