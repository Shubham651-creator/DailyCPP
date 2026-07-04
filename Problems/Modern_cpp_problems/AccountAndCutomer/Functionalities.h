#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <list>
#include <optional>
#include "Account.h"
#include "Customer.h"

// container hold customer pointer
using customerContaier = std::list<std::unique_ptr<Customer>>;
// container hold customer raw pointer
using RAWcustomerContainer = std::list<Customer*>;

// containe hold Account pointer
using accoutContainer = std::list<std::unique_ptr<Account>>;

// create object of 3 customer
void CreateObjectCutomer(customerContaier &customerObject,
                         accoutContainer &accountObject);

/*
    A function returns customer id whose combined
    trnasaction amount is higher.
*/
std::string
HigherTransactionAmount(customerContaier &customerObject);

/*
    return all customer instance whose match with second
    argument as cutomertype
*/
std::optional<RAWcustomerContainer>
MatchedCustomerType(customerContaier &customerObject, CustomerType type);

/*
   return all customer instance whose credits[100,200]
   and balance over 500
*/
std::optional<RAWcustomerContainer>
BalanceOver5000(customerContaier &customerObject);

/*
   print highest and lowest customer instance based on
   store credits.
*/
void HighestLowestCredits(customerContaier &customerObject);

/*
   return averge of all credits whose matches with customer
   type as second argument.
*/
float AvergeOfStoreCredits(customerContaier &customerObject, CustomerType type);

/*
   return a count of all instance whose has
   customer type as regular.
*/
int CountCustomerTypeRegular(customerContaier &customerObject);

#endif // FUNCTIONALITIES_H
