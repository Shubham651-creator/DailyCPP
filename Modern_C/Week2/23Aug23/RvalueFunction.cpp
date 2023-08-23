#include <iostream>
#include <list>
#include <functional>

void operation(std::list<int> data, std::function<int(int)> fn)
{
    for (int i : data)
    {
        std::cout << fn(i) << '\n';
    }
}

/*
    In Lambda function :
    [] - capture clause
*/

int main()
{
    operation(
        std::list<int>{1, 23, 4},

        [](int number) //temporary function(rvalue)
        {
            std::cout << "Square():of " << number << "\t is ";
            return number * number;
        }
    );
}
