#include <iostream>

class Unary
{
    int a, b;

public:
    Unary(int x = 0, int y = 0)
    {
        a = x;
        b = y;
    }

    void display()
    {
        std::cout << "The value a = " << a << "\tb = " << b << "\n";
    }

    Unary operator++(int) // u++ and int is dumpy argument
    {
        Unary u1 = *this;   //*this is give value at that address/object
        a++;
        b++;
        // Unary u1;
        // u1.a = a++;
        // u1.b = b++;
        return u1;
    }

    Unary& operator++() //++u
    {
        ++this->a;
        ++this->b;
        return *this;
    }
};

int main()
{
    Unary u(3, 10), u1,u2;
    u.display();

    u1 = u++;
    std::cout << "The after post-increment u1= u++ : ";   
    u1.display();
    std::cout << "The after post-increment u : "; 
    u.display();
    std::cout<<"\n";

    u2 = ++u;
    std::cout << "The after pre-increment u2 = ++u : ";
    u2.display();
    std::cout << "The after pre-increment u : ";
    u.display();

    return 0;
}