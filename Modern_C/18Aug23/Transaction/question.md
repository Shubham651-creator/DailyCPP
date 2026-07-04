# Pre Incubation Coding Marathon 3 Problem Statement 3

# Create a class Transaction with the following attributes
    ● transactionId that could be string or float.
    ● transactionAmount that could be float.
    ● transactionType that could be CARD, CASH or UPI

# Create a class Account with the following attributes
    ● accountId which could be string or int.
    ● accountTransactionSet which could be a collection of Transactions (of type array or
    vector).
    ● accountBalance which could be a float value.

# Create a functionalities.cpp file for the following
● A function [countTransactionOfGivenType] that takes a container of Transaction object pointers and returns a count of Transaction instances whose transactionType matches with the argument given as the second parameter.

● A function [totalTransactionAmount] that takes a container of Account instances and returns a total of transactionAmount for all instances.

● A function [findMaxAccountBalanceID] that takes a data container of Account instances and a transactionType and finds the ID of the account that has the highest balance amongst all Accounts whose transactionType matches with the type passed as argument.

● A function [accountsAboveThreshold] that takes a threshold amount and returns a data container of all Account instances whose cumulative transactionAmount is above the threshold passed.

● A function [nthTrasactionId] that returns the Id of the Nth transaction of an account instance from a data container of Account instances. The value of N and accountId to be searched will be provided as a parameter.

● A function [averageTransactionAmount] that returns the average of transactionAmount for all Account instances whose ID values are passed in a data container as parameter.

● A function [balanceInterestAmount] that runs in a thread and returns the cumulative interest for all accounts whose instances are passed in a data container.
    ○ The interest rate is 4% of the balance amount if the balance amount is above 10000 else interest is 0.
    ○ The thread must return a value rather than printing the final answer. So choose the thread mechanism accordingly.
    ○ For every account instance, a new thread should be launched to compute the
    interest.

● A function [isAccountValid] that returns true or false based on the following conditions
    ○ accountBalance should be over 10000.
    ○ At least 3 transactions should have been made by the account.
    ○ Transaction amount for any transaction made by the account should be over 500.

# Demonstrate all functionalities using a Main.cpp file.