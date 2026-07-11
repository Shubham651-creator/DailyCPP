/*
    Display() :
        It should accept a container of vector
        of primitive data type or pointers
        to primitive data type and print all the items
        one by one
*/

#include <iostream>
#include <vector>

template <typename T>
void Display(std::vector<T> data) // vector of values template
{
    for (T &value : data)
    {
        std::cout << value << '\t';
    }
    std::cout << std::endl;
}

template <typename T>
void Display(std::vector<T *> data) // vector of pointer template
{
    for (T *&value : data)
    {
        std::cout << *value << '\t';
    }
    std::cout << std::endl;
}

int main()
{

    std::vector v1{1, 2, 4, 5, 6};
    int n1 = 10;

    int *p1 = &n1;
    int *p2 = &n1;
    int *p3 = &n1;
    int *p4 = &n1;

    std::vector v2{p1,p2,p3,p4}; // store address

    Display<int>(v1);
    Display<int*>(v2);
    
}