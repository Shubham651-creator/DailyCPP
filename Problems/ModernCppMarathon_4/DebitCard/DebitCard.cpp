#include "DebitCard.h"
std::ostream &operator<<(std::ostream &os, const DebitCard &rhs)
{
    os << "_number: " << rhs._number
       << " _cvv: " << rhs._cvv
       << " _type: " << DisplayDebitType(rhs._type)
       << " _pin: " << rhs._pin
       << " _annual_charge: " << rhs._annual_charge;
    return os;
}

std::string DisplayDebitType(DebitCardType type)
{
    if (type == DebitCardType::INTERNATIONL)
    {
        return "INTERNATIONL";
    }
    return "DOMASTIC";
}

int DigitLength(int number)
{

    int count = 0;
    while (number > 0)
    {
        count++;
        number /= 10;
    }

    return count;
}

DebitCard::DebitCard(int number, int cvv,
                     DebitCardType Type, int pin, float charge)
    : _number(number), _cvv(cvv), _type(Type), _pin(pin), _annual_charge(charge)
{
    if (DigitLength(number) < 0 || DigitLength(number) > 7)
    {
        std::runtime_error("number must be 6 digit\n");
    }
    if (DigitLength(cvv) < 0 || DigitLength(cvv) > 4)
    {
        std::runtime_error("CVV must be 3 digit\n");
    }
    if (DigitLength(pin) < 0 || DigitLength(pin) > 7)
    {
        std::runtime_error("PIN must be 4 to 6 digit\n");
    }
}
