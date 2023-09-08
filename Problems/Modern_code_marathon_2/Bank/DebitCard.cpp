#include "DebitCard.h"

DebitCard::DebitCard(int cvv, int cardNumber)
    : _cvv(cvv), _card_number(cardNumber) {}

std::ostream &operator<<(std::ostream &os, const DebitCard &rhs)
{
    if (rhs.cvv() > 99)
    {
        os << "_cvv: " << rhs._cvv;
    }
    else
    {
        os << "invalid cvv\n";
    }

    if (rhs.cardNumber() > 99999)
    {
        os << " _card_number: " << rhs._card_number;
    }
    else
    {
        os << "Invalid card Number\n";
    }
    return os;
}
