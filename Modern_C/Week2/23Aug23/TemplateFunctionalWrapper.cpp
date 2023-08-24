#include <iostream>
#include <functional>

template <class T>
std::function<T> fn;

int main()
{

    fn<int(int)> = [](int n) { return n * n; };
    fn<float(int)> = [](int n) { return (float)n * n; };

    std::cout << fn<int(int)>(10) << '\n';
}