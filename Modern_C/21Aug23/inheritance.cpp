#include <iostream>

class Parent
{
private:
public:
    Parent() {}
    ~Parent() {}

    virtual void display() = 0;
};

//final keyword is not allow to inherited from base class
class Child final: public Parent
{
private:
public:
    Child();
    ~Child();

    //'override' keyword is use for security purpose.
    //i.e. wrong naming of function 
    void Display() override
    {
        std::cout << "child display function called\n";
    }
};

class NewChild: public Child
{
private:
    /* data */
public:
    NewChild(/* args */) {}
    ~NewChild() {}
};