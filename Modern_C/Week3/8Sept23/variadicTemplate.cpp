
#include <iostream>

template <typename T>
T add(T args)
{
    return args;
}

// since C++14
template <typename X, typename... T>
X add(X val, T... args) //... parameter pack
{
    return val + add(args...);
}

// from C++17
template <typename... T>
auto substraction(T... args)
{
    /*
        ... decided direction of assoication
        since code is (args + ...), operation would be right association.
    */

    // param pack right to left(unary right fold) ,(10-(20-(30-40))) = -20
    return (args - ...);

    // // param pack left to right(unary left fold), (((10-20)-30)-40) = -80
    // return (... - args);
}

int main()
{
    std::cout << add<int>(10) << '\n';
    std::cout << add<int, int>(10, 2, 3, 4, 5, 6) << '\n';

    // std::cout<< add<std::string>( ) <<'\n'; //won't work

    std::cout << "Substraction :\t " << substraction<int>(-10, 20, -30, 40)
              << '\n';
}