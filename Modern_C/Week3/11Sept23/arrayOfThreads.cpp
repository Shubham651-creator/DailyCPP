/*
    Array of threads
*/

/*
    Thread has no return type. Threads discard the return type.

    ONLY Asyn thread has return type.
*/

#include <array>
#include <iostream>
#include <thread>

int main()
{
    std::array<int, 5> data{1, 2, 3, 4, 5};
    std::array<int, 5> result{0};

    std::thread arr[5]; // it called 5 times default thread constructor

    auto f1 = [&](int n, int i)
    { result[i] = n * n; };

    for (int i = 0; i < 5; i++)
    {
        arr[i] = std::move(std::thread(f1, data[i], i));
    }

    for (int i = 0; i < 5; i++)
    {
        arr[i].join();
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << result[i] << '\t';
        std::cout << sizeof(arr[i])<< '\n';
    }
}