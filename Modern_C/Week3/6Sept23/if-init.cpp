#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{

    std::vector<int> data{1, 2, 3, 4, 5};

    // if itr is reached to end of the data,
    // it's We can't find given element
    // search in vector
    if (auto itr = std::find(data.begin(), data.end(), 4);
        data.end() == itr)
    {
        std::cout << "NOT found\n";
    }
    else
    {
        std::cout << "The element is = " << *itr << '\n';
    }

    std::cout << std::accumulate(data.begin(), data.end(), 0) << '\n';
}