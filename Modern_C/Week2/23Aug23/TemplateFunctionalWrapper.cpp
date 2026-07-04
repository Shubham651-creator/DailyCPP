#include <iostream>
#include <functional>

// template functional wrapper 
template <class T>
std::function<T> fn;

int main()
{

    fn<int(int)> = [](int n) { return n * n; };
    fn<float(int)> = [](int n) { return (float)n * n; };
    fn<float(float)> = [](float n) { return n * n; };

    std::cout << fn<float(float)>(10.3f) << '\n';
    std::cout << fn<float(int)>(10.3f) << '\n';
}