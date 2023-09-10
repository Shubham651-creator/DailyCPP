#include <functional>
#include <iostream>

/*
    std::cref(), (const reference)(immutable)

    or

    std::reference_wrapper<const int>(), (const reference)(immutable)
*/

void machine(int &var)
{
    ++var;
}

int main()
{

    int localVar = 0;

    // auto bound = std::bind(machine, localVar); // send copy of local var
    // auto bound = std::bind(machine, std::ref(localVar)); // send ref
    // auto bound = std::bind(machine, std::reference_wrapper<const int>(localVar)); // send const ref
    // auto bound = std::bind(machine, std::cref(localVar)); //error: cref is immutable.
    auto bound = std::bind(machine, std::reference_wrapper<int>(localVar)); // send ref

    bound();
    bound();

    std::cout << localVar << '\n';
}