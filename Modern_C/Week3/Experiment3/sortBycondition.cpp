#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>

int main()
{
    std::vector<int> v(10);

    std::iota(v.begin(), v.end(), 10);

    std::sort(
        v.begin(),
        v.end(),
        [](int a, int b)
        {
            return a > b;
        });

    for (int &value : v)
    {
        std::cout << value << "\n";
    }

    std::list<int> lst(10);
    std::iota(lst.begin(), lst.end(), 10);

    lst.sort([](int a, int b)
             { return a > b; });

    for (int &value : v)
    {
        std::cout << "list::" << value << "\n";
    }
}