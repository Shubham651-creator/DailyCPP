#include <iostream>

// meta programming
/*
    We can implement Template with 'constexpr'
    because template and constexpr both
    execute in compile-time.
*/
template <typename T>
constexpr T add(T n1, T n2)
{
    return n1 + n2;
}

int main()
{

    std::cout << add<int>(10, 20) << '\n';
    std::cout << add<std::string>("Shubam", "awale") << "\n";
}