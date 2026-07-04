#include <iostream>
#include <functional>

// first-class function !

/*
    let there is one person.
    Person is given data constainer and is given an operation.
    Person tries to apply operation on data.

    e.g: data is [1,2,3,,4,5] opertion :square
    e.g: data is [1,2,3,,4,5] opertion :factorial

*/

int square(int number)
{
    std::cout << "Square():of " << number << "\t is ";
    return number * number;
}
int cube(int number)
{
    std::cout << "Cube(): of " << number << "\t is ";
    return number * number * number;
}
int factorial(int number)
{
    if (number == 1)
        return 1;
    return number * factorial(number - 1);
}

void operation(int *ptr, int N, std::function<int(int)> fn)
{
    /*
        for 0 to 4, do the follwing :
            find element at ith offset from ptr address
            pass it to fn
    */
    for (int i = 0; i < N; i++)
    {
        std::cout << fn(ptr[i]) << '\n';
    }
}

int main()
{

    int arr[5]{
        1,
        2,
        3,
        4,
        5,
    };

    // functional pointer
    std::function<int(int)> ptr1 = &square;
    std::function<int(int)> ptr2 = cube;
    std::function<int(int)> ptr3 = factorial;

    operation(arr, 5, ptr1); // addr of first location of arr, addr of square()
    operation(arr, 5, &cube);
    operation(arr, 5, ptr3);
}