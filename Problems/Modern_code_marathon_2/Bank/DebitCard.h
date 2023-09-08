#ifndef DEBITCARD_H
#define DEBITCARD_H
#include <ostream>

class DebitCard
{
private:
    int _cvv;
    int _card_number;

public:
    // disable default constructor
    DebitCard() = delete;

    // disable copy constructor
    DebitCard(const DebitCard &) = delete;

    // disable copy operator
    DebitCard &operator=(DebitCard &) = delete;

    // disable move constructor
    DebitCard(DebitCard &&) = delete;

    // disable move operator
    DebitCard &operator=(DebitCard &&) = delete;

    // parameterized constructor
    DebitCard(int cvv, int cardNumber);

    // destructor
    ~DebitCard() = default;

    int cvv() const { return _cvv; }

    int cardNumber() const { return _card_number; }

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
