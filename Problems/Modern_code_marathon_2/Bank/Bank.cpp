#include "Bank.h"

std::ostream &operator<<(std::ostream &os, const Bank &rhs)
{
    os << "_name: " << rhs._name
       << " _accounts_data: ";

    os << *rhs._accounts_data;
    os << "\n";
    return os;
}
Bank::Bank(std::string name, accountContainer2 accounts)
    : _name(name), _accounts_data(accounts) {}