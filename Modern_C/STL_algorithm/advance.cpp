#include <iostream>
#include <iterator>
#include <vector>

/*
    std::advance( itr, n ),
    it increament the given iterator by n
*/
 
int main() 
{
    std::vector<int> v{3, 1, 4};
 
    auto vi = v.begin();
    std::advance(vi, -22);
    std::cout << *vi << ' ';

    std::advance(vi, 0);
    std::cout << *vi << ' ';
 
    vi = v.end();
    std::advance(vi, 2);
    std::cout << *vi << '\n';
}