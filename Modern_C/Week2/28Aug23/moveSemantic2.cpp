#include <iostream>
#include <memory>

class Employee
{
private:
    int _id;
    std::string _name;

public:
    Employee(Employee &&) = default;
    Employee &operator=(Employee &&) = default;
    Employee(int id, std::string name) : _id(id), _name(name) {}
    ~Employee() = default;
};

int main()
{

    Employee e1(Employee(101, "shubhan")); // move constructor called
    Employee e2(std::move(e1));            // set e1 to nullptr and data bind with e2

    Employee e3(Employee(102, "awale"));
    e1 = std::move(e3); // called move operator constructor and set e3 to nullptr
    return 0;
}
