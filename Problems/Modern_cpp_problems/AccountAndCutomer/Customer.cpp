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
       << "\ncutomer Account details : " << *(rhs.getCustomerAccount())
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

Customer::Customer(int id, std::string name, CustomerType type,
                   std::vector<float> amounts, float credits, std::unique_ptr<Account> cAccount)
    : customerId(id), customerName(name), customerType(type),
      customerTransactionAmounts(amounts), customerStoreCredits(credits)
{
    customerAccount = std::move(cAccount);
}

Customer Customer::operator+(Customer &obj)
{
    Customer result;

    result.customerId = obj.customerId;
    result.customerName = obj.customerName;
    result.customerType = obj.customerType;
    result.customerStoreCredits =
        this->customerStoreCredits + obj.customerStoreCredits;

    for (int i = 0; i < 5; i++)
    {
        result.customerTransactionAmounts[i] =
            this->customerTransactionAmounts[i] + obj.customerTransactionAmounts[i];
    }

    result.customerAccount.get()->id() = obj.customerAccount.get()->id();

    return std::move(result);
}
