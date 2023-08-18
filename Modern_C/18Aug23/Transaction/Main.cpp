#include <iostream>
#include "Transaction.h"
#include "Account.h"
#include "functionalities.h"

// vector takes collection of Transaction address as element
using Transactions = std::vector<Transaction *>;
using Container = std::list<Account *>;

int main()
{
    Container account;
    CreateAccounts(account);

    Container store = AccountAboveThreshold(account, 100);
    std::cout << "AccountAboveThreshold is "
              << " \n";

    for (Account *object : store)
    {
        std::cout << *object << "\n";
    }

    // itreate the in account and store the transactions in
    // transaction container
    Transactions temp;
    for (Account *object : account)
    {
        temp = object->getAccountTransactionSet();
    }
    std::cout << "CountTransactionOfGivenType(temp, TransactionType::UPI): "
              << CountTransactionOfGivenType(temp, TransactionType::UPI) << "\n";

    std::cout << "\nTotalTransactionAmount(): "
              << TotalTransactionAmount(account) << "\n";

    std::cout << "NthTransactionId():"
              << NthTransactionId(account, 1, "ac102") << "\n";

    std::cout << "FindMaxAccountBalanceId():"
              << FindMaxAccountBalanceId(account)
              << "\n";

    std::cout << "AverageTransactionAmount();"
              << AverageTransactionAmount(account, "ac101")
              << "\n";

    std::cout << "BalanceInterestAmount():"
              << BalanceInterestAmount(account)
              << "\n";

    std::cout << "IsAccountValid():"
              << IsAccountValid(account.front())
              << "\n";

    DeleteAccounts(account);

    return 0;
}