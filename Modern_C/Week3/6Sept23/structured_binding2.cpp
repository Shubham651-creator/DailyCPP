#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using Container = std::vector<std::function<int(int)>>;

Container magic()
{
    auto f1 = [](int n)
    { return n * n; };
    auto f2 = [](int n)
    { return n * 10; };
    auto f3 = [](int n)
    { return n * 30; };

    return Container{f1, f2, f3}; // rvalue
}

int main()
{

    Container ans = magic();

    for (auto &value : ans)
    {
        std::cout << value(3) << '\n';
    }

    // classic way to initized
    std::function<int(int)> a = ans[0];
    std::function<int(int)> b = ans[1];
    std::function<int(int)> c = ans[2];

    std::cout << "x : " << a(2)
              << " y : " << b(3)
              << " z : " << c(8) << '\n';

    // apply sturctured binding

    using namespace std::placeholders;

    // std::function<int(int)>[x, y, z] = ans; //error(why)
}