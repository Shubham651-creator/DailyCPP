#include <iostream>
#include <functional>

template <typename T>
void display(T &&)
{
    /*
        T&& :
        pass rvalue ----> T&&
        pass lvalue -----> T& &&--> T&
    */
    using noReference = std::remove_reference_t<T>; // to remove the existing reference
    if constexpr (std::is_integral_v<noReference>)
    {
        // noReference var = 's';
        // std::cout<<var<<'\n';
        std::cout << "it is intergral part\n";
    }
    else
    {
        std::cout << "it is NOT intergral part\n";
    }
}

template <typename T>
void funct(T &&b)
{
    b = 20;

    // it remove power of ref, and it normal
    using noref = std::remove_reference_t<T>;

    noref c; // int c

    b = (noref)21;

}

int main()
{
    int a = 10;
    display(a);

    int b = 19;
    funct(b);

    std::cout << "b: " << b << "\n";
}