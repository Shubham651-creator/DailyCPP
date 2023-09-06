#include <iostream>
#include <array>

/*
    rvalue :
    int{}
    std::string {}
*/

using Container = std::array<int, 3>;

Container magic()
{
    Container v1{11, 22, 55};
    return v1; // return by move(lvalue) since c++17
}

int main()
{
    Container ans = magic();

    for (auto &value : ans)
    {
        std::cout << value << '\n';
    }

    // classic way to do initalize
    int a = ans[0];
    int b = ans[1];
    int c = ans[2];

    // sturctured binding to do initalize
    auto [x, y, z] = magic();

    std::cout << "x : " << x
              << " y : " << y
              << " z : " << z << '\n';
}