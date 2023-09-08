#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <stack>

// diplay takes data of type T, loops over data and prints its elements
template <typename T>
void Display(T data)
{
    for (auto val : data)
    {
        std::cout << val << '\t';
    }
    std::cout << '\n';
}

// special template
template <>
void Display(std::stack<int> data)
{
    std::stack<int> copy_data(data);
    std::cout << "Your in stack\t:";
    int size = copy_data.size();

    for (int i = 0; i < size; i++)
    {
        std::cout << copy_data.top() << '\t';
        copy_data.pop();
    }

    std::cout << '\n';
}

int main()
{
    std::vector v1{1, 2, 3, 4, 5};
    std::list list1{1, 2, 3, 4, 5};
    std::array<int, 5> a1{1, 2, 3, 4, 5};
    std::stack<int> s1;

    for (int i = 0; i < 5; i++)
    {
        s1.push(i + 1);
    }

    // Display(std::stack<int>(s1));
    Display(s1);

    Display(v1);
    Display(list1);
    Display(a1);
}