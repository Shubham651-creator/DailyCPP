#ifndef BANK_H
#define BANK_H

#include <iostream>

class Account
{

    int accNumber;
    std::string cname;
    float balance;

    static int cnt;
    static int x; //count of customer

public:
    int getAccNum();
    std::string getCname();
    float getBalance();

    void setAccNum(int a);
    void setCname(std::string c);
    void setBalance(float b);

    //constructor overloading
    Account();
    Account(std::string cnm, float bal);

    void show() const;
    void accept();
    void deposit(float amount);
    void withdraw(float amount);
    bool checkInitial(float amount);

    //static function only access static members??
    //because we are not created object and 'this' pointer is missing
    static int getX(){return x;}
};

#endif // BANK_H
