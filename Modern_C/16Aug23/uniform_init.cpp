#include <iostream>
#include <vector>
#include <list>

struct Demo
{
    int value;
};

class uniform_init
{
private:
    int _eid{-1}; // in class initize

public:
    uniform_init(int id) : _eid(id) {}
    uniform_init(const uniform_init &) = delete;
    uniform_init() = default;
    ~uniform_init() {}
};

int main()
{
    // uniform initilzer concept

    // int arr[5] = {1, 2, 3, 4, 5};
    int arr[5]{1, 2, 3, 4, 5};

    // int n1 = 10;
    int n1(10);

    struct Demo d1
    {
        10
    };
    // d1.value = 10;

    // int *ptr = nullptr;
    int *ptr{nullptr};

    // uniform_init e1;
    uniform_init e1{};
    // uniform_init *e2 = new uniform_init();

    // std::list<int> data = {1, 2, 3};
    std::list<int> data{1, 2, 3};

    // for loop in modern cpp ---------------------------------------------------------
    // iterative apporch to programming
    std::list<int> list1{1, 2, 3, 4, 5};

    // range based - for every integer called 'val' , inside list called 'list1'
    for (int val : list1)
    {
        std::cout << val << "\t";
    }

    return 0;
}