/*
    create a container of 3 functions
    - One that takes a vector of floats, return average
    - one that take a vector of floats, returns max
    - One that take a vector of floats, return total of first 3 elements
*/

#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <iostream>

using Container = std::vector<float>;
using Ftype = std::function<float(Container)>;

// // f1 is too high for lambda function
// // so its not optimized
// auto f1 = [](Container &data)
// {
//     float total = 0.0f;
//     for (auto &val : data)
//     {
//         total += val;
//     }
//     return total / data.size();
// };

int main()
{

    std::vector<float> data{
        1.0f, 45.8f, 9.0f, 56.4f};

    float sum = std::accumulate(data.begin(), data.end(), 0.0f); // addition of all elements
    std::cout << "sum = " << sum << '\n';
    std::cout << "Averge of container elements = " << sum / data.size() << '\n';

    float product = std::accumulate(
        data.begin(),
        data.end(),
        1.0f,
        [](float ans, float value)
        { return ans * value; }
        /*

            This is decided by Accumlator itself.

            []('ans' which stores return val , 'value' which store containers values ){
                return ans * value;
            }

        */
    );
    std::cout << product << '\n';

    // find position of max element from the container
    // this give position of max element, if there are multiple
    // max elements, it will give position(address) of first max
    Container::iterator itr = std::max_element(data.begin(), data.end());
    std::cout << *itr << '\n';

    return 0;
}
