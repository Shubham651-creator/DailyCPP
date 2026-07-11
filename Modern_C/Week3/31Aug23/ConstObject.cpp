#include <iostream>

class Employee
{
private:
    const int data; // once initize can't be change further

public:
    Employee(int val)
        : data(val) {}
    ~Employee() {}

    int getData() const
    {
        return data;
    }

    void Display(){
        std::cout<<data<<'\n';
    }
};

int main()
{
    Employee e1(8);
    e1.getData();
    e1.Display();

    // on const object we can call or invoke only const functions
    Employee const e2(34);
    e2.getData();
    // e2.Display(); //error : Constant object can't access non-const functions
}