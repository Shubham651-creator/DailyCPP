#include <iostream>
#include <future>

template <typename... Args>
int addition(Args &...args)
{
    std::cout << "You are in vardic template\n";
    return (args + ...);
}

int main()
{

    int a = 90;
    int b = 2, c = 3, d = 4;

    // std::promise<int> pr;
    // std::future<int> varA = pr.get_future();

    // std::promise<int> pr2;
    // std::future<int> varB = pr2.get_future();

    std::future<int> sum = std::async(
        std::launch::async,
        addition<int, int>,
        std::ref(a),
        std::ref(b));

    std::cin >> a;
    std::cin >> b;

    // addition(a,b);

    // pr.set_value(a);
    // pr2.set_value(b);

    // std::cout<<"sum : "<<sum.get()  <<'\n';
}