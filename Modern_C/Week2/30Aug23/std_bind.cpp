/*
    f(x,y)
    f of x,y

    Mathematician : function f is mapped to x & y
    Programmer : function f takes input of x & y

    g(f(x,y)) is  g(x) with y mapped or g(y) with x mapped
*/

#include <iostream>
#include <functional>

void formula(int x, int y, int z)
{
    std::cout << ((x + y) - z) << '\n';
}

struct Actor
{
    void DoSomething(int x, int y, int z)
    {
        std::cout << ((x + y) - z) << '\n';
    }
};

using namespace std::placeholders;

int main()
{
    // partial implmentation of formula where x is set to 100 already

    // x= 100,
    auto partial_formula_f1 = std::bind(&formula, 100, _2, _3);

    // 3 is discarded, 29 is _2(y) and 45 is _3(z)
    partial_formula_f1(3, 29, 45);

    ////////////////////////////////////////////////
    // x= 100
    auto partial_formula_f2 = std::bind(&formula, 100, _1, _2);
    // here , return of bind is dependent of implementation
    // i.e auto is changed according to compiler

    // x =100(already), 59 is _1(y) and 45 is _2(z)
    partial_formula_f2(59, 45);
    partial_formula_f2(59, 45, 243, 454, 234); // x =100(already)

    ////////////////////////////////////////////////

    auto partial_formula_f3 = std::bind(&formula, _1, 100, _3);
    partial_formula_f3(90, -1, 80);
    /*
        Rules : formula has 3 parameters
            _1 --> x -------> user decides
            100 --> y ------->fixed
            _3---> z -------> user decides
    */

    //===============================================================

    auto partial_formula_swap = std::bind(&formula, _3, _2, _1);
    std::cout << "partial_formula_swap:\t";
    partial_formula_f3(90, 30, 80);
    /*
        Rules : formula has 3 parameters

        _3---> x -------> user decides
            :pick the 3rd parameter and map to x

        _2 --> y ------->fixed
            :pick the 2rd parameter and map to y

        _1 --> z -------> user decides
            :pick the 1rd parameter and map to z

    */

    //=============================================================

    Actor a1;
    auto class_func_bind = std::bind(&Actor::DoSomething, &a1, _3, _2, _1);
    std::cout<<"Bind the class function:\t";
    class_func_bind(102,304,48);
}

/*
    bind does the following

    a. fixes the values of one or more parameters of a function, it partially
    implements by using concept of placeholder and dedicated values.

    b.It can be used to switch the order of values passed by mapping
    them in any sequence programmer desires.
*/