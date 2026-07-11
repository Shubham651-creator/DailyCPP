#include <functional>
#include <iostream>
#include <optional>

struct optional1
{
    optional1() = default;
    optional1(const optional1 &) = delete;
    optional1(optional1 &&) = delete;
};

int main()
{

    std::optional<double> var;

    std::cout << var.has_value() << '\n';
    std::cout << sizeof(var) << '\n';
    std::cout << var.value_or(90) << '\n';

    std::optional<std::string> str;
    str = std::string("shubh");
    std::cout << str.value().size() << '\n';

    std::optional<optional1> obj;
    // obj = optional1();
    obj.emplace();
}