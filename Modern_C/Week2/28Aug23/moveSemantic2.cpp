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

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "_id: " << rhs._id
       << " _name: " << rhs._name;
    return os;
}

int main()
{

    Employee e1(Employee(101, "shubhan")); // move constructor called
    Employee e2(std::move(e1));            // set e1 to nullptr and data bind with e2

    std::cout << e1 << "\n"; // set e1 nullptr manually

    Employee e3(Employee(102, "awale"));
    e1 = std::move(e3); // called move operator constructor and set e3 to nullptr

    std::cout << e3 << "\n"; // set e3 nullptr manually

    return 0;
}
