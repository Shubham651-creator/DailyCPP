#include <iostream>
#include <array>
#include <unordered_map>

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

    /*

        > return Container{11,2,34}; // NO copy/move

        - Copy Elision for initialization form temporaries
        (prvalue - purely rvalue) is required since c++17.

        - Callable copy/move constructor no longer requried.
    */
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

    //-----------useCase 2---------------------------------------------

    std::unordered_map<int, std::string> m1{
        {1, "Shubham"}, // key,value
        {2, "Awale"},
        {3, "Rohan"}};

    // classic way of looping
    for (auto itr = m1.begin(); itr != m1.end(); ++itr)
    {
        std::cout << "The label is : " << itr->first << "\n"
                  << "The value is : " << itr->second << '\n';
    }

    // c++17 version structured binding
    for (auto [label, data] : m1)
    {
        std::cout << "The label is : " << label << "\t"
                  << "The value is : " << data << '\n';
    }
}