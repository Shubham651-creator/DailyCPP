#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include "/home/kpit/Desktop/coding/DailyCPP/Modern_C/Week4/20Sept23/Employee.h"

template <typename T>
void operation(std::vector<T> first, std::vector<T> second)
{
    // operation on primitive datatype
    auto itr = std::find_first_of(
        first.begin(),
        first.end(),
        second.begin(),
        second.end());

    if (itr == first.end())
    {
        std::cout << "Nothing common found\n";
    }
    else
    {
        std::cout << "Element founds are: at position : "
                  << std::distance(first.begin(), itr)
                  << "\tand item : " << *itr << "\n\n";
    }
}

template <typename T, typename F>
void operation(std::vector<T> first, std::vector<T> second, std::function<F> &fn)
{
    // operation on primitive datatype
    auto itr = std::find_first_of(
        first.begin(),
        first.end(),
        second.begin(),
        second.end(),
        fn);

    if (itr == first.end())
    {
        std::cout << "Nothing common found\n";
    }
    else
    {

        std::cout << "Element founds are: at position : "
                  << std::distance(first.begin(), itr)
                  << "\tand item : " << **itr << "\n\n";
    }
}

int main()
{

    std::vector<int> data1(5);
    std::vector<int> data2(5);

    std::iota(data1.begin(), data1.end(), 3);
    std::iota(data2.begin(), data2.end(), 2);

    std::vector<Employee *> Edata1{
        new Employee(101, 230000.0f, "shubham"),
        new Employee(102, 230000.0f, "awale"),
        new Employee(103, 230000.0f, "omkar")};

    std::vector<Employee *> Edata2{
        new Employee(105, 230000.0f, "shubham"),
        new Employee(108, 230000.0f, "awale"),
        new Employee(101, 230000.0f, "omkar")};

    std::function<bool(Employee *, Employee *)> fn = [](Employee *obj1, Employee *obj2) -> bool
    {
        return obj1->id() == obj2->id();
    };

    operation<int>(data1, data2);
    // call operation
    operation<Employee *, bool(Employee *, Employee *)>(Edata1, Edata2, fn);
}