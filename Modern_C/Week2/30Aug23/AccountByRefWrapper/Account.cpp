#include "Account.h"

std::string DisplayAcountType(AccountType type)
{
    if (type == AccountType::PREMIUM)
        return "PREMIUM";
    return "BASIC";
}

Account::Account(int id)
    : _id(id) {}

std::ostream &operator<<(std::ostream &os, const Account &rhs)
{
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _type: " << DisplayAcountType(rhs._type);
    return os;
}

Account::Account(int id, AccountType type)
    : _id(id), _type(type) {}

// This constructor acccpts 3 parameters int,string and type
// It transfers int and Acounttype to another constructor of the
// same class And Deals with the remaining parameter string
Account::Account(int id, std::string name, AccountType type)
    : Account(id, type)
{
    _name = name;
}