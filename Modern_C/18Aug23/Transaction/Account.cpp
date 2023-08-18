
#include "Account.h"

Account::Account(std::string id, Transactions set, float balance)
    : accountId(id), accountTransactionSet(set), accountBalance(balance) {}

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "accountId: " << rhs.accountId
       << "\naccountTransactionSet: " ;
       
    for(Transaction* transaction : rhs.getAccountTransactionSet()){
        os << *transaction<<"";
    }
    
    os  << "\naccountBalance: " << rhs.accountBalance
    <<"\n------------------------------------------------------------------";
    return os;
}
 