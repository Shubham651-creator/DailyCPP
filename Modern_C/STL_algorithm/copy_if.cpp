#include <algorithm>
#include <iostream>
#include <vector>

int main()
{

    std::vector<int> data{1, 2, 3, 4, 5};

    std::vector<int> result(data.size()); // result.size() = data.size()

    // copy the even number from data
    // itr hold the last true condition position element
    auto itr = std::copy_if(
        data.begin(),
        data.end(),
        result.begin(),

        [](int num)
        {
            return num % 2 == 0;
        });

    result.resize(std::distance(result.begin(), itr));

    // display the result
    std::cout << "The even elements :\n";
    for (int value : result)
    {
        std::cout << value << '\n';
    }
}