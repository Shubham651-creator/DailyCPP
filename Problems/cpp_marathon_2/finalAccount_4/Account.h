#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>

class Account
{
private:
    long accountNumber;
    float accountBalance;
    const float accountMinBalance = 500.0;

public:
    // default constructor
    Account();

    // parameterized constructor
    Account(long number, float balance);

    // copy constructor
    Account(Account &account);

    /// destructor
    ~Account();

    // copy into object
    void operator=(Account &account);

    // abstract function
    virtual int calculateInterestAmount();

    //void display
    virtual void display();

    //extraction overloading
    friend void operator<<(std::ostream& out, Account& account);

    long getAccountNumber() const { return accountNumber; }
    void setAccountNumber(long accountNumber_) { accountNumber = accountNumber_; }

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    float getAccountMinBalance() const { return accountMinBalance; }
};

#endif // ACCOUNT_H
