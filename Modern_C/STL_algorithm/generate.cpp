#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int f()
{
    static int i = 0;
    return (++i + 10) * 2;
}

int main()
{
    std::vector<int> data(10);

    std::generate(data.begin(), data.end(), &f);

    std::for_each(data.begin(), data.end(),
                  [](int num)
                  { std::cout << "number : " << num << "\n"; });
}