#include "Account.h"

std::ostream &operator<<(std::ostream &os, const Account &rhs)
{
    os << "_number: " << rhs._number
       << " _min_balance_amount: " << rhs._min_balance_amount
       << " _current_balance: " << rhs._current_balance
       << " _card: " << *rhs._card;
    return os;
}
Account::Account(std::string number, float min_balance, float current, std::shared_ptr<DebitCard> card)
    : _number(number), _min_balance_amount(min_balance), _current_balance(current), _card(card) {}

void Account::CalculateTotalInterest()
{
    float totalInterest = _current_balance * 0.06;
    std::cout << "The total interest amount is " << totalInterest << '\n';
}
