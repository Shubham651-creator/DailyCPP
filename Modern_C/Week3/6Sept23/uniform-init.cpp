#include <iostream>

using namespace std::literals;

/*
    @brief client code
    @param command-line arguments
*/

int main()
{

    int a = (3, 4, 8); // uniform init - don't use this

    /*
        AAA(Almost Always auto)
    */
    auto b{47};
    auto b1{"shubham"};

    auto c = int{97};
    auto c1 = "Awale"s; // from std::literals
    // std::initializer_list<int> c = {89};

    std::cout << a << '\n'
              << b << '\n'
              << b1 << '\n';

    std::cout << c << '\n';
    std::cout << c1 << '\n';
}