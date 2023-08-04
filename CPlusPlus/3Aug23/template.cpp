#include <iostream>

// templates are intentiated by compiler

template <class T>
// T is work like type holder
void exchange(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// //concept of modern c++17
// void exchange(auto &a, auto &b)
// {
//     std::cout << "a = " << a << "\nb = " << b << "\n\n";
// }

int main()
{
    int x = 2, y = 3;
    exchange(x, y);
    std::cout << x << " " << y << "\n";

    float f1 = 2.2, f2 = 3.3;
    exchange(f1, f2);
    std::cout << f1 << " " << f2 << "\n";

    // exchange("shub", "awale");
    return 0;
}