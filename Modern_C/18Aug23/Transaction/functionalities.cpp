#include "functionalities.h"
#include "Transaction.h"
#include "Account.h"

/*
createAccount()

    Transaction

    [ tr101 | 100.0f | CASH ]
    adress1

    [ tr102 | 100.0f | UPI ]
    adress2

    [ tr103 | 100.0f | CASH ]
    address3
---------------------------------------------------------
    Account

      ID         TRANSACTION VECTOR              AMOUNT
    [ac101 ] [ adress1 | adress2 | adress3 ] [1000.0f]

    adress4
*/

// vector takes collection of Transaction address as element
using Transactions = std::vector<Transaction *>;

void CreateAccounts(Container &data)
{

    Account *ac1 = new Account(
        "ac101",
        Transactions{
            new Transaction("tr101", 100.0f, TransactionType::CASH),
            new Transaction("tr102", 100.0f, TransactionType::UPI),
            new Transaction("tr103", 780.0f, TransactionType::CARD)},
        10000.0f);

    Account *ac2 = new Account(
        "ac102",
        Transactions{
            new Transaction("tr104", 200.0f, TransactionType::UPI),
            new Transaction("tr105", 300.0f, TransactionType::UPI),
            new Transaction("tr106", 640.0f, TransactionType::CARD)},
        40000.0f);

    //entered account in container
    data.push_back(ac1);
    data.push_back(ac2);
}

/*
    For every Account, do the following
        i) loop over transaction , for each transaction
            a) delete transaction
        ii)  delete the entire account object now
*/
void DeleteAccounts(Container &data)
{
    for (Account *account : data)
    {
        for (Transaction *transaction : account->getAccountTransactionSet())
        {
            delete transaction;
        }
        delete account;
    }
}

int CountTransactionOfGivenType(TransactionContainer &data, TransactionType type)
{
    int count = 0;
    for (Transaction *container : data)
    {
        if (container->getTransactionType() == type)
        {
            count++;
        }
    }

    return count;
}

float TotalTransactionAmount(Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data container empty\n");
    }

    float total = 0.0f;
    for (Account *account : data)
    {
        for (Transaction *transaction : account->getAccountTransactionSet())
        {
            total += transaction->getTransactionAmount();
        }
    }

    return total;
}

Container AccountAboveThreshold(Container &data, float threshold)
{
    if (data.empty())
    {
        throw std::runtime_error("Data container empty\n");
    }

    float total = 0.0f;
    Container store;
    for (Account *account : data)
    {
        total = 0.0f;
        for (Transaction *transaction : account->getAccountTransactionSet())
        {
            total += transaction->getTransactionAmount();
        }
        if (total > threshold)
        {
            store.emplace_back(account);
        }
    }
    return store;
}

std::string NthTransactionId(Container &data, int N, std::string accountId)
{
    if (data.empty())
    {
        throw std::runtime_error("Data container empty\n");
    }
    // invalid transaction
    if (N <= 0 || N > 3)
    {
        throw std::runtime_error("Invalid N\n");
    }

    for (Account *account : data)
    {
        if (account->getAccountId() == accountId)
        {
            return account->getAccountTransactionSet()[N]->getTransactionId();
        }
    }

    throw std::runtime_error("Account with matching ID not found\n");
}

std::string FindMaxAccountBalanceId(Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data container empty\n");
    }
    float highBalance = 0.0f;
    std::string id = " ";

    for (Account *account : data)
    {
        if (account->getAccountBalance() > highBalance)
        {
            highBalance = account->getAccountBalance();
            id = account->getAccountId();
        }
    }

    return id;
}

float AverageTransactionAmount(Container &data, std::string accountId)
{
    if (data.empty())
    {
        throw std::runtime_error("Data container empty\n");
    }
    float totalTransaction = 0.0f;
    int count = 0;
    for (Account *account : data)
    {
        if (account->getAccountId() == accountId)
        {
            for (Transaction *transaction : account->getAccountTransactionSet())
            {
                totalTransaction += transaction->getTransactionAmount();
                count++;
            }
        }
    }

    return totalTransaction / count;
}

// implementation of multi- threading
float BalanceInterestAmount(Container &data)
{
    if (data.empty())
    {
        throw std::runtime_error("Data container empty\n");
    }

    float balance = 0.0f;
    for (Account *account : data)
    {
        if (account->getAccountBalance() > 1000)
        {
            balance = account->getAccountBalance();
            balance +=  balance *0.04  ; 
        }
    }

    return balance;
}

bool IsAccountValid(Account *account)
{
    bool flag = true;
    /*
        flag will be updated based on transaction amount being over 500,
        if any transaction < 500, then our account is invalid.
    */
    for (Transaction *transaction : account->getAccountTransactionSet())
    {
        flag = transaction->getTransactionAmount() > 500;

        if(!flag) return false;
    }

    /*
        return check for account validty based on 3 conditions
    */
    return account->getAccountBalance() > 1000.0f 
        &&
    account->getAccountTransactionSet().size() >= 3 
        && 
    flag;
}
