#include <iostream>
#include <functional>
#include <vector>

int main()
{
    int n1 = 10;

    std::reference_wrapper<int> r1 = n1; // int& r1 = n1;

    std::reference_wrapper<int> arr[1]{r1};

    std::vector<std::reference_wrapper<int>> data{r1};

    std::reference_wrapper<std::reference_wrapper<int>> ref_ref{r1};
}