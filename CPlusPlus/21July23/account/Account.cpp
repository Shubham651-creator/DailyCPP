#include <iostream>
#include "Account.h"

// getter method / accessor method- to access valure of particular attribute
int Account::getAccNum() { return accNumber; }
std::string Account::getCname() { return cname; }
float Account::getBalance() { return balance; }

// setter method/ mutator method - to change value of particular attribute
void Account::setAccNum(int a) { accNumber = a; }
void Account::setCname(std::string c) { cname = c; }
void Account::setBalance(float b) { balance = b; }

Account::Account()
{
    accNumber = cnt;
    cname = "shubham";
    balance = 30100;
    cnt++;
    x++;
}

Account::Account(std::string cnm, float bal)
{
    accNumber = cnt;
    cname = cnm;
    balance = bal;
    cnt++;
    x++;
}

void Account::show() const
{
    std::cout << accNumber << " " << cname << " " << balance << "\n";
}

void Account::accept()
{
    do
    {
        std::cout << "Customer Name = ";
        std::cin >> cname;
        std::cout << "Customer Balance = ";
        std::cin >> balance;
    } while (!checkInitial(balance));
}

void Account::deposit(float amount)
{
    balance += amount;
}

void Account::withdraw(float amount)
{
    if (balance - amount < 500)
    {
        std::cout << "Insufficient Balance\n";
    }
    else
    {
        balance -= amount;
    }
}

bool Account::checkInitial(float amount)
{
    if (amount < 500)
    {
        std::cout<<"++++++++Deposite first more than Rs.500, then Your account will be activate+++++\n";
        return false;
    }
    return true;
}

// defination for static variable
int Account::cnt = 2129;

int Account::x = 0;