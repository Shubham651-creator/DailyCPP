#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <memory>
#include "Account.h"
#include "CustomerType.h"

class Customer
{
private:
    int customerId;
    std::string customerName;
    CustomerType customerType;
    std::vector<float> customerTransactionAmounts;
    float customerStoreCredits;
    std::unique_ptr<Account> customerAccount;

public:
    // enables default constructor
    Customer() = default;

    // parameterized constructor
    Customer(int id, std::string name, CustomerType type,
             std::vector<float> amounts, float credits, std::unique_ptr<Account> cAccount);

    // enables copy constructor
    Customer(const Customer &) = delete;

    // enable operator=
    Customer &operator=(Customer &) = delete;

    // disable move constructor
    Customer(Customer &&) = default;

    // enables move operator
    Customer &operator=(Customer &&) = delete;

    // override + operator
    Customer operator+(Customer &);

    // enables destructor
    ~Customer() = default;

    Account *getCustomerAccount() const { return customerAccount.get(); }

    int getCustomerId() const { return customerId; }

    std::string getCustomerName() const { return customerName; }

    CustomerType getCustomerType() const { return customerType; }

    std::vector<float> getCustomerTransactionAmounts() const { return customerTransactionAmounts; }

    float getCustomerStoreCredits() const { return customerStoreCredits; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
};

std::string DisplayCustomerType(CustomerType type);

#endif // CUSTOMER_H
