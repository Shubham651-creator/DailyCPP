#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <vector>
#include <optional>
#include <variant>
#include "DebitCard.h"
#include "CreditCard.h"

// pointer to debit card
using PointerToDebit = std::shared_ptr<DebitCard>;
// vector container of debit card
using ContainerDebit = std::vector<PointerToDebit>;

// pointer to credit card
using PointerToCredit = std::shared_ptr<CreditCard>;
// vector container of credit card
using ContainerCredit = std::vector<PointerToCredit>;

// variant Pointer
using variantPointer = std::variant<PointerToCredit,
                                    PointerToDebit>;
// variant container
using variantContainer = std::vector<variantPointer>;

// create object of 5 instance
void CreateObject(variantContainer &variantObject);

// a. return float average of charge whose matched with type
float AverageOfCharge(variantContainer &variantObject, CardType type);

// b. return bool, whether all instance has same type
bool AllInstanceSameType(variantContainer &variantObject, CardType type);

// c. return copy of container of first N instances
variantContainer
FirstNisntance(variantContainer &variantObject, int N);

// d. return int cvv, whose match with second para
int CheckCVV(variantContainer &variantObject, int N);

// e. return count of instacnes, whose match type
int CountInstacneType(variantContainer &variantObject, CardType type);

#endif // FUNCTIONALITIES_H
