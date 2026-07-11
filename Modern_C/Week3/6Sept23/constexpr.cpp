#include <iostream>

// constexpr - give ability to execute function in complier-time.
constexpr int add(int a, int b)
{
    return a + b;
}

int main()
{

    int ans = add(2, 4);
}