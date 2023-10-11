#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <iostream>
#include "CardType.h"

class CreditCard
{
private:
    int _number;
    int _cvv;
    CardType _type;
    int _pin;
    float _annual_charge;

public:
    // disable default constructor
    CreditCard() = delete;

    // disable copy constructor
    CreditCard(const CreditCard &) = delete;

    // disable copy assignment operator
    CreditCard &operator=(CreditCard &) = delete;

    // disable move constructor
    CreditCard(CreditCard &&) = delete;

    // disable move assignment operator
    CreditCard &operator=(CreditCard &&) = delete;

    // parameterized
    CreditCard(int number, int cvv, CardType Type, int pin, float charge);

    // destructor
    ~CreditCard() = default;

    // getter of all attributes
    int number() const { return _number; }

    int cvv() const { return _cvv; }

    CardType type() const { return _type; }

    int pin() const { return _pin; }

    float annualCharge() const { return _annual_charge; }

    friend std::ostream &operator<<(std::ostream &os, const CreditCard &rhs);
};

std::string DisplayCreditType(CardType type);

#endif // CREDITCARD_H
