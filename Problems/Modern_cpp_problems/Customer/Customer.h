#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include "CustomerType.h"

// vector Container which store float
using container = std::vector<float>;

class Customer
{
private:
    int customerId;
    std::string customerName;
    CustomerType customerType;
    container customerTransactionAmounts;
    float customerStoreCredits;

public:
    // enables default constructor
    Customer() = default;

    // parameterized constructor
    Customer(int id, std::string name, CustomerType type, container amounts, float credits);

    // enables copy constructor
    Customer(const Customer &) = default;

    // enable operator=
    Customer &operator=(Customer &) = default;

    // disable move constructor
    Customer(Customer &&) = delete;

    // enables move operator
    Customer &operator=(Customer &&) = default;

    // override + operator
    Customer operator+(Customer &);

    // enables destructor
    ~Customer() = default;

    int getCustomerId() const { return customerId; }
    void setCustomerId(int customerId_) { customerId = customerId_; }

    std::string getCustomerName() const { return customerName; }
    void setCustomerName(const std::string &customerName_) { customerName = customerName_; }

    CustomerType getCustomerType() const { return customerType; }
    void setCustomerType(const CustomerType &customerType_) { customerType = customerType_; }

    container getCustomerTransactionAmounts() const { return customerTransactionAmounts; }
    void setCustomerTransactionAmounts(const container &customerTransactionAmounts_) { customerTransactionAmounts = customerTransactionAmounts_; }

    float getCustomerStoreCredits() const { return customerStoreCredits; }
    void setCustomerStoreCredits(float customerStoreCredits_) { customerStoreCredits = customerStoreCredits_; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
};

std::string DisplayCustomerType(CustomerType type);

#endif // CUSTOMER_H
