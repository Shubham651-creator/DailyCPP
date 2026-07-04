#include <iostream>
#include <vector>
#include <optional>
#include<algorithm>

using container = std::vector<int>;
using opt = std::optional<container>;

opt Magic(container &data, int threshold)
{
    if (data.empty()) // case 1 : user's fault
    {
        throw std::runtime_error("Data is empty.\n");
    }

    container result(data.size()); //no size ---> no result.begin() ----> no result.end()

    // STL Algorithm to copy one container with another 
    // appling coping condition in lambda function.
    auto itr = std::copy_if(
        data.begin(), //input starting
        data.end(), // input end
        result.begin(), //output start
        [&](int val){return val > threshold;} //predicate lambda : return bool
    ); // result{4,5,6,0,0}
       //            |
       //           itr

    result.resize(std::distance(result.begin(), itr)); //STL algo 

    if(result.empty()) // case 2: code runs but nothing getting from above
    {
        return std::nullopt; // return nothing in std::optional
    }

    return result;
}

int main()
{
    container store{2,3,4,5,6};
    opt data = Magic(store, 3);

    // getting return vector value is optional i.e. empty.
    // if (data.empty())
    // {
    //     std::cout << "No data found\n";
    // }

    // If vector value container NULL values
    if (data.has_value())
    {
        // consume
        std::cout << "Data has value\n";
        for (int val : data.value())
        {
            std::cout <<" value = "<< val <<"\n";
        }
    }
    else
    {
        std::cout << "okay I understand nothing is above threshold.\n";
    }
}

/*
    Scenarios 1 :
    send N values as input.
    1 to N values are above thresold
    -> return vector 1 or more value

    Scenarios 2 :
    send N values as input.
    No value is above threahold
    -> return a empty vector

    Scenarios 3:
    send an empty vector as input.
    -> return a empty vector.

    a. consumer won't be using try-catch
    b. input data is empty and no values above threshold
        both are return empty result.
*/