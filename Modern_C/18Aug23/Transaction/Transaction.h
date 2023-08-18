#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "TransactionType.h"

class Transaction
{
private:
    std::string transactionId;
    float transactionAmount;
    TransactionType transactionType;

public:
    // disable default constructor
    Transaction() = delete;

    // enable the parameterized constructor
    Transaction(std::string id, float amount, TransactionType type);

    // disable copy constructor
    Transaction(const Transaction &) = delete;

    // disable operator overloading constructor
    Transaction &operator=(Transaction &) = delete;

    // disable move constructor
    Transaction(Transaction &&) = delete;

    // disable move operator constructor
    Transaction operator=(Transaction &&) = delete;

    // enable the destractor
    ~Transaction() = default;

    // getter and setter of transaction attribute

    std::string getTransactionId() const { return transactionId; }
    void setTransactionId(const std::string &transactionId_) { transactionId = transactionId_; }

    float getTransactionAmount() const { return transactionAmount; }
    void setTransactionAmount(float transactionAmount_) { transactionAmount = transactionAmount_; }

    TransactionType getTransactionType() const { return transactionType; }
    void setTransactionType(const TransactionType &transactionType_) { transactionType = transactionType_; }

    friend std::ostream &operator<<(std::ostream &os, const Transaction &rhs);

};

// display the enum function
std::string displayTransactionType(TransactionType type);
#endif // TRANSACTION_H
