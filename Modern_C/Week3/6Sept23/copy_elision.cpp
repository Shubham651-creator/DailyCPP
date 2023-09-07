#include <iostream>

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
    NoCopyMove& operator=(NoCopyMove&)= delete;
    NoCopyMove(NoCopyMove &&) = default;      // move disable
    ~NoCopyMove() = default;

    const void display()
    {
        std::cout << "The display function\n\n";
    }
};
/*
    @brief print
    @param NoCopyMove instance
*/
void magic(NoCopyMove object)
{
    std::cout << "you are in magic\n";
}

/*
    @brief return default object
*/
NoCopyMove returnObject()
{
    return NoCopyMove(); // prvalue(pure rvalue)
}

int main()
{
    magic(NoCopyMove());

    // temporary return value(prvalue): materializes
    NoCopyMove object{returnObject()};
    NoCopyMove objects = returnObject();

    std::cout << "\nobject callled display function = \n";
    object.display();
    objects.display();
}