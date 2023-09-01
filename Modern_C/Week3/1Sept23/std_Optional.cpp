#include <iostream>
#include <vector>

std::vector<int> Magic(std::vector<int> &data, int threshold)
{
    std::vector<int> result;

    result.push_back(NULL);

    return result;
}

int main()
{
    std::vector<int> store;
    std::vector<int> data = Magic(store, 23);

    // getting return vector value is optional i.e. empty.
    if (data.empty())
    {
        std::cout << "No data found\n";
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