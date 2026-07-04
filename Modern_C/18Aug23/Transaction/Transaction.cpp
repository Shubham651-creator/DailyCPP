#include "Transaction.h"

Transaction::Transaction(std::string id, float amount, TransactionType type)
    : transactionId(id), transactionAmount(amount), transactionType(type) {}

std::ostream &operator<<(std::ostream &os, const Transaction &rhs)
{
    os << "\n[ transactionId: " << rhs.transactionId
       << " transactionAmount: " << rhs.transactionAmount
       << " transactionType: " << displayTransactionType(rhs.getTransactionType())
       << " ]\n";
    return os;
}

// display the enum value
std::string displayTransactionType(TransactionType type)
{
    if (type == TransactionType::CARD)
        return "CARD";
    if (type == TransactionType::CASH)
        return "CASH";

    return "UPI";
}