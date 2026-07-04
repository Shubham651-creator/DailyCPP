#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
#include <any>

int main()
{

    std::set<int> s;
    s.emplace(4);
    s.emplace(2);
    s.emplace(3);
    s.emplace(3);
    s.emplace(6);

    for (const int &value : s)
    {
        std::cout << value << "\n";
    }

    int c = std::count_if(s.begin(), s.end(),
                          [](int a)
                          {
                              return a % 2 == 0;
                          });

    int c2 = std::count(s.begin(), s.end(), 1);

    std::cout << "count of a%2==0 is "
              << c << "\n"
              << c2 << "\n\n";

    //============================================================================
    std::any any1;
    any1 = 12;
    std::cout << "int: " << std::any_cast<int>(any1) << "\n";

    any1.emplace<std::string>("shubam");
    std::cout << "string: " << std::any_cast<std::string>(any1) << "\n";
}