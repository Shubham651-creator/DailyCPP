#include "CreditCard.h"

std::ostream &operator<<(std::ostream &os, const CreditCard &rhs)
{
    os << "_number: " << rhs._number
       << " _cvv: " << rhs._cvv
       << " _type: " << DisplayCreditType(rhs._type)
       << " _pin: " << rhs._pin
       << " _annual_charge: " << rhs._annual_charge;
    return os;
}

std::string DisplayCreditType(DebitCardType type)
{
    if (type == DebitCardType::PREMIUM)
    {
        return "PREMIUM";
    }
    if (type == DebitCardType::REWARDS)
    {
        return "REWARDS";
    }

    return "ELITE";
}

int DigitLength2(int number)
{

    int count = 0;
    while (number > 0)
    {
        count++;
        number /= 10;
    }

    return count;
}

CreditCard::CreditCard(int number, int cvv,
                       DebitCardType Type, int pin, float charge)
    : _number(number), _cvv(cvv), _type(Type), _pin(pin), _annual_charge(charge)
{
    if (DigitLength2(number) < 0 || DigitLength2(number) > 7)
    {
        std::runtime_error("number must be 6 digit\n");
    }
    if (DigitLength2(cvv) < 0 || DigitLength2(cvv) > 4)
    {
        std::runtime_error("CVV must be 3 digit\n");
    }
    if (DigitLength2(pin) < 0 || DigitLength2(pin) > 7)
    {
        std::runtime_error("PIN must be 4 to 6 digit\n");
    }
}
