#include <algorithm>
#include <iostream>
#include <vector>

int main()
{

    std::vector<int> data{1, 2, 3, 4, 5};

    std::vector<int> result(data.size()); // result.size() = data.size()

    // do any of my input element satify the condition in the lambda
    // return boolean
    bool store = std::any_of(
        data.begin(),
        data.end(),
        [](int num)
        { return num % 10 == 0; });
    std::cout << "std::any_of, Is my condition satisfy: " << store << "\n";

    // std::all_of
    bool store2 = std::all_of(
        data.begin(),
        data.end(),
        [](int num)
        { return num % 10 == 0; });

    // std::none_of
    bool store3 = std::none_of(
        data.begin(),
        data.end(),
        [](int num)
        { return num % 10 == 0; });

   
}