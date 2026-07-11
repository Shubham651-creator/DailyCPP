#include <algorithm>
#include <vector>
#include<iostream>

int main()
{
    std::vector<int> data{1, 2, 3, 4, 5};
    std::vector<int> result(data.size());

    /*
        std::trasform , applies gives logic(opertion)
        on  EVERY element of input but NOT ALWAYS
        in perfect input order.
    */
    std::transform(
        data.begin(),
        data.end(),
        result.begin(),
        [](int n)
        { return n * n; });

    for (auto &vale : result)
    {
        std::cout << vale << "\t";
    }
}