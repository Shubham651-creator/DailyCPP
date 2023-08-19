#include "Customer.h"

std::ostream &operator<<(std::ostream &os, const Customer &rhs)
{
    os << "customerId: " << rhs.customerId
       << "\ncustomerName: " << rhs.customerName
       << "\ncustomerType: " << DisplayCustomerType(rhs.customerType)
       << " \ncustomerTransactionAmounts: "
       << "\n";

    // display all transaction in the vector container
    for (float amounts : rhs.customerTransactionAmounts)
    {
        os << amounts << "\t";
    }

    os << "\ncustomerStoreCredits: " << rhs.customerStoreCredits
       << "\n-------------------------------------------------------------";
    return os;
}

std::string DisplayCustomerType(CustomerType type)
{
    if (type == CustomerType::PREMIUM)
        return "PREMIUM";
    if (type == CustomerType::REGULAR)
        return "REGULAR";
    return "VIP";
}

Customer::Customer(int id, std::string name, CustomerType type, container amounts, float credits)
    : customerId(id), customerName(name), customerType(type), customerTransactionAmounts(amounts), customerStoreCredits(credits) {}
