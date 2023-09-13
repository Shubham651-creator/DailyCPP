#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data{1, 2, 3, 4, 5};

    std::vector<int> result(data.size()); // result.size() = data.size()

    std::find(
        data.begin(),
        data.end(),
        4
    );
    
    // std::find, returns where result position
    auto find_store = std::find_if(
        data.begin(),
        data.end(),
        [](int num)
        { return num % 2 == 0; });
    std::cout << *find_store << '\n';
}