#include "Customer.h"

using Pointer = std::shared_ptr<Account>;
using RefType = std::reference_wrapper<Pointer>;

Customer::Customer(std::reference_wrapper<std::shared_ptr<Account>> account, std::string customerName, int age)
    : _customerName(customerName), _age(age), _account(account) {}

std::ostream &operator<<(std::ostream &os, const Customer &rhs)
{
    os << "_customerName: " << rhs._customerName
       << " _age: " << rhs._age
       << " _account: " << *(rhs._account).get();
    return os;
}
