#include <iostream>
#include <functional>
#include <vector>
#include <memory>

using vect = std::vector<int>;

void display(vect &&n)
{
    for (int value : n)
    {
        std::cout << value << '\n';
    }
}
template <typename T>
void display(const T &n)
{
    std::cout << n << '\n';
    std::cout << std::is_integral_v<T> << "\n\n"; // return bool
}
int main()
{

    int a = 19; // primitive data type
    float f = 90.0f;
    vect v{1, 2, 3, 4};
    display(vect{2984, 535, 6});
    display(std::move(f));

    // the magic of move seen only on heap allocted data type
    int b = std::move(a);
    std::cout << "b: " << b << '\n';

    int c = std::move(a);
    std::cout << "c: " << c << '\n';
    std::cout << "a: " << a << '\n';

    std::shared_ptr<int> aptr = std::make_shared<int>(a);
}