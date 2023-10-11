#ifndef DEBITCARD_H
#define DEBITCARD_H

#include <iostream>
#include "DebitCardType.h"

class DebitCard
{
private:
    int _number;
    int _cvv;
    DebitCardType _type;
    int _pin;
    float _annual_charge;

public:
    // disable default constructor
    DebitCard() = delete;

    // disable copy constructor
    DebitCard(const DebitCard &) = delete;

    // disable copy assignment operator
    DebitCard &operator=(DebitCard &) = delete;

    // disable move constructor
    DebitCard(DebitCard &&) = delete;

    // disable move assignment operator
    DebitCard &operator=(DebitCard &&) = delete;

    // parameterized
    DebitCard(int number, int cvv, DebitCardType Type, int pin, float charge);

    // destructor
    ~DebitCard() = default;

    // getter of all attributes
    int number() const { return _number; }

    int cvv() const { return _cvv; }

    DebitCardType type() const { return _type; }

    int pin() const { return _pin; }

    float annualCharge() const { return _annual_charge; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

std::string DisplayDebitType(DebitCardType type);

#endif // DEBITCARD_H
