#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <list>
#include<memory>
#include "Transaction.h"
#include "Account.h"

//using Container = std::list<Account *>;
using Container = std::list<std::shared_ptr<Account>>;
// vector takes collection of Transaction address as element
//using TransactionContainer = std::vector<Transaction *>;
using Transactions = std::vector<std::shared_ptr<Transaction>>;

// function to create account object
void CreateAccounts(Container &data);

// function to delete account object
// void DeleteAccounts(Container &data);

// it function takes container of transaction object pointer and
// returns count of transaction instance(object)
int CountTransactionOfGivenType(Transactions &data, TransactionType type);

// function to find toatal transaction amount (total for all objects)
float TotalTransactionAmount(Container &data);

// function find acount above throshold
Container AccountAboveThreshold(Container &data, float threshold);

// function to find ID of nth transaction of an account
//(0 < n <=3)
std::string NthTransactionId(Container &data, int N, std::string accountId);

// function to find accountId of the account with maximum accountBalance
//(assuming all acoount have different balance amounts)
std::string FindMaxAccountBalanceId(Container &data);

// function to find average transaction amount of all transaction
//  of ONE GIVEN ACCOUNT
float AverageTransactionAmount(Container &data, std::string accountId);

// function to find cumlative account interest (using all
// intances of account ) as per given condition
float BalanceInterestAmount(Container &data);

// function to check if account is valid or not
bool IsAccountValid(Account *);

#endif // FUNCTIONALITIES_H
