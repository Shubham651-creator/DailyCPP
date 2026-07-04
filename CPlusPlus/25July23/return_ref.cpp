#include <iostream>

// return by reference

// We cannot overload (.)dot opeartor, (::)scope resolution, sizeof,
// and ternery operator(? ::)

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

    Complex operator+(Complex &c)
    {
        Complex c3;
        c3.real = real + c.real;
        c3.img = img + c.img;

        // // return by ref [Complex&]
        // return *this; // value at that address or object

        // return by value [Complex]
        return c3;

        // //return by pointer [Complex*]
        // return this; //return address of this
    }

    Complex operator+(int c)
    {
        Complex c3;
        c3.real = real + c;
        c3.img = img + c;

        return c3;
    }

    // non-member function
    friend void operator<<(std::ostream &ob, const Complex &c);

    friend void operator>>(std::istream &in, Complex &c);

    friend Complex operator+(int a, Complex& c);
};

// global function and non-member function of above class
void operator<<(std::ostream &out, const Complex &c)
{
    out << "real = " << c.real << "  img = " << c.img << "\n";
}

void operator>>(std::istream &in, Complex &c)
{
    in >> c.real;
    in >> c.img;
}

Complex operator+(int a, Complex& c){
    Complex c3;
    c3.real = a + c.real;
    c3.img = a+ c.img;

    return c3;
}

int main()
{
    Complex c1(3, 4), c2(5, 6), c3, c4;

    c3 = c1 + c2; // c1.operator+(c2)
    // c3.display();

    // inseration operator already overloading in ostream for primitive data type
    // cout.operator<<(c3) by rule but.....
    // operator<<(cout, c3)
    std::cout << c3;

    // operator(cin, c4)
    std::cin >> c4;
    std::cout << c4;

    c3 = c1 + 10; // c1.operator+(10)

    //operator(10, c1)
    c3 = 10 + c1; // friend function

    /*
        << is operator and not work with object c3

        cout - object of ostream class
        c3 - object of complex class
    */

    return 0;
}