#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include<functional>
#include "Account.h"
#include "DebitCard.h"
#include "Bank.h"

// container which stores DebitCard instaneces
using debitCardContainer = std::list<std::shared_ptr<DebitCard>>;

// container which stores account instances
using accountContainer = std::vector<std::shared_ptr<Account>>;

// container which stores Bank instances
using bankContainer = std::list<std::shared_ptr<Bank>>;

//function pointer
using funcPointer = std::function<void(bankContainer&, int)>;

// creates a 3 objects of bank
void CreateObjects(bankContainer &dataBank, accountContainer &dataAccount, debitCardContainer &dataDebitCard);

//higher order function
void HigherOrderFunction(bankContainer& data, funcPointer& fns, int );

// 3. first n instance
void FirstNInstance(bankContainer& data, int N);

// 4. min balance at least 500
void MinBalanceAtLeast(bankContainer& data, int N);

//5. below threshold
void BelowThresholdBalance(bankContainer& data, int N);

#endif // FUNCTIONALITIES_H
