#include "Account.h"

std::ostream &operator<<(std::ostream &os, const Account &rhs)
{
    os << "_id: " << rhs._id
       << " _balance: " << rhs._balance;
    return os;
}

Account::Account(std::string id, float balance)
    : _id(id), _balance(balance)
{
}
