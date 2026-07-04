#include <iostream>

class Complex
{

    int real;
    int img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }

    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void display()
    {
        std::cout << "The real = " << real << "\nimg = " << img << "\n";
    }
    Complex operator-(Complex &c) // c =c2
    {
        Complex c3;
        c3.real = this->real - c.real;
        c3.img = img - c.img;

        return c3;
    }
    Complex operator+(Complex &c)
    {
        Complex c3;
        c3.real = real + c.real;
        c3.img = img + c.img;

        return c3;
    }

    bool operator==(Complex &c)
    {
        if (real == c.real && img == c.img)
        {
            return true;
        }

        return false;
    }

    Complex operator--()
    {
        Complex c;
        c.real = real - 1;
        c.img = img - 1;

        return c;
    }

    void operator~()
    {
        this->real = -real;
        this->img = -img;
    }
};

int main()
{
    Complex c1(3, 4), c2(5, 6), c3;
    
    c3 = c1 + c2; // c1.operator+(c2)
    c3.display();

    // Complex c4 = c1 - c2; //c1.operator-(c2)
    // c4.display();

    // Complex c5 = --c1;
    // c5.display();

    // Complex c6(2, 3);
    // ~c6;                 //c6.operator~()
    // c6.display();

    return 0;
}