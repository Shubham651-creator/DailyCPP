#include <iostream>
#include <any>

int main()
{

    std::any a = 1;

    std::cout << a.type().name() << " : "
              << std::any_cast<int>(a)
              << "\n";

    a = 3.23;

    std::cout << a.type().name() << " : "
              << std::any_cast<double>(a)
              << "\n";

    std::string b = "shuam";
    a.emplace<std::string>(b); // changed the contained object

    std::cout << a.type().name() << " : "
              << std::any_cast<std::string>(a)
              << "\n";
}