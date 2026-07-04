#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>
#include <memory>

/*
    a. std::priority_queue is a container adaptor that provides
        constant time "O(1)" lookup of the largest OR Smallest element.

    b. By default std::vector [tree like heap] is the cotainer used inside.

    c. Cost of insertion and extraction is logarithmic.

    d. It is implemented using std::make_heap, std::push_heap,
        std::pop_heap functions.
*/

class priorityQueue
{
private:
    int id;

public:
    priorityQueue(int i) : id(i) {}
    ~priorityQueue() = default;

    int getId() const { return id; }

    friend std::ostream &operator<<(std::ostream &os, const priorityQueue &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const priorityQueue &rhs)
{
    os << "id: " << rhs.id;
    return os;
}

int main()
{
    // auto cmp = [](priorityQueue &a, priorityQueue &b)
    // {
    //     return a.getId() > b.getId();
    // };

    auto cmp = [](std::unique_ptr<priorityQueue> &a,
                  std::unique_ptr<priorityQueue> &b)
    {
        return a.get()->getId() >
               b.get()->getId();
    };

    std::priority_queue<std::unique_ptr<priorityQueue>,
                        std::vector<std::unique_ptr<priorityQueue>>,
                        decltype(cmp)>
        obj3(cmp);

    priorityQueue p1(1); // object on stack

    std::unique_ptr<priorityQueue> u1 =
        std::make_unique<priorityQueue>(22);
    std::unique_ptr<priorityQueue> u2 =
        std::make_unique<priorityQueue>(2);
    std::unique_ptr<priorityQueue> u3 =
        std::make_unique<priorityQueue>(4);
    std::unique_ptr<priorityQueue> u4 =
        std::make_unique<priorityQueue>(8);

    obj3.push(std::move(u2)); // std::push_heap
    obj3.push(std::move(u1));
    obj3.push(std::move(u3));
    obj3.push(std::move(u4));

    while (!obj3.empty())
    {
        std::cout << *(obj3.top().get()) << "\n";
        obj3.pop();
    }

    std::cout << "======================================================================";

    std::priority_queue<int> p;
    std::priority_queue<int> pCopy;

    p.push(1); // std::push_heap
    p.push(11);
    p.push(4);
    p.push(8);
    p.push(3);

    pCopy = p; // enable copy assignment operator

    while (!pCopy.empty())
    {
        std::cout << pCopy.top() << "\n";
        pCopy.pop();
    }

    int max = 0;
    max = p.top();
    std::cout << "max : " << max << "\n\n";
}
