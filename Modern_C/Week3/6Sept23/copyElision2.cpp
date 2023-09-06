#include <iostream>
#include <memory>

/*
    Gurenteen copy-elision or RVO(Return Value Optimization)
*/

class NoCopyMove
{
private:
public:
    NoCopyMove()
    {
        std::cout << "Constructor called\n";
    };

    NoCopyMove(const NoCopyMove &) = delete; // copy disable
    NoCopyMove &operator=(NoCopyMove &) = delete;
    NoCopyMove(NoCopyMove &&) = delete; // move disable
    ~NoCopyMove() = default;

    const void display()
    {
        std::cout << "The display function\n\n";
    }
};

using Pointer = std::unique_ptr<NoCopyMove>;

/*
    @brief print
    @param NoCopyMove instance
*/
void magic(Pointer object)
{
    std::cout << "you are in magic\n";
}

/*
    @brief return default object
*/
Pointer returnObject()
{
    return Pointer(); // prvalue(pure rvalue)
}

int main()
{

    Pointer ptr1 = std::make_unique<NoCopyMove>();
    std::cout << "The unique ptr is ";
    ptr1->display();

    const Pointer object{returnObject()};
    object->display();
}