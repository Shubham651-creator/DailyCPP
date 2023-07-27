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
};

//SmartClass handles allocation and dellocation of other class
//It is a wrapper class
class smartClass
{
private:
    Complex* complexObject;

public:
    smartClass()
    {
        complexObject = new Complex;
    }
    ~smartClass()
    {
        delete complexObject;
    }
    
    //arrow operator overloading
    Complex* operator->(){
        return complexObject;     //returns address of complex class complexObjectect
    }
    //* operator overloading
    Complex operator*(){
        return *complexObject;    //returns complexObjectect of complex class
    }
};

int main()
{
    smartClass sm1[5];
    sm1[0]->display();         //sm1.operator->()

    (*sm1[0]).display();        //complexObject.display()

    return 0;
}