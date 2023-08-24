#include <iostream>
#include <list>
#include <functional>

void operation(std::list<int> data, std::function<int(int)> fn)
{
    for (int i : data)
    {
        std::cout << fn(i) << '\n';
    }
    std::cout << "print second position of list : " << fn(2) << '\n';
}

/*
    In Lambda function :
    [] : capture clause - it is used to access variable declared
    or made local to the enclosing function
*/

int main()
{
    int n1 = 12;

    operation(
        std::list<int>{1, 23, 4},

        [&n1](int number) // temporary function(rvalue)
        {
            std::cout << "Square():of " << number << "\t is ";
            std::cout << "\nCapture clause : " << n1 << "\n";
            return number * number;
        });
}
