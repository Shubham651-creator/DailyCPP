#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include<memory>
#include<functional>
#include"Customer.h"

using CustomerContainer = std::vector<std::shared_ptr<Customer>>;
using AccountContainer = std::vector<std::shared_ptr<Account>>;

void Operation(CustomerContainer& data, std::function<void(CustomerContainer&)> fn);

void CreateObjects(CustomerContainer& data, AccountContainer& accountData);

#endif // FUNCTIONALITIES_H
