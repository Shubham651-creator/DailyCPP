#include <algorithm>
#include <vector>
#include <iostream>

int main()
{

    std::vector<int> data{1, 2, 3, 4, 5};

    /*
        std::for_each(), applies gives logic on EVERY elment
        of input and give output in sequentally.
    */
    std::for_each(
        data.begin(),
        data.end(),
        [](int n)
        { std::cout << n * n; });
}