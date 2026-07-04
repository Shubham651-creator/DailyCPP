#include <iostream>
#include <cstring>

/*
    Exception Handling - run time error

    Why we should do exception handling ?
    -> to execute the program without stoping,even error is there!
*/

// underflow for withdraw
class UnderflowException : public std::exception
{
private:
    char message[60];

public:
    UnderflowException(const char *p)
    {
        strcpy(message, p);
    }
    char *getMessage()
    {
        return message;
    }
};

// overflow exception for deposit
class OverflowException : public std::exception
{
private:
    char message[90];

public:
    OverflowException(const char *p)
    {
        strcpy(message, p);
    }
    char *getMessage()
    {
        return message;
    }
};

class Account
{
private:
    int balance;

public:
    Account()
    {
        balance = 500;
    }
    Account(int b)
    {
        balance = b;
    }

    void withdraw(int amt)
    {
        if (balance - amt < 500)
        {
            throw UnderflowException("underflow Error throw : Minimum required 500 rupee\n");
        }
        else
        {
            balance -= amt;
            std::cout << "withdraw Done\n";
        }
    }

    void deposit(int amount)
    {
        if (balance + amount > 50000)
        {
            throw OverflowException("Error throw : overflow rupee\n");
        }
        else
        {
            balance += amount;
            std::cout << "deposit Done\n";
        }
    }
};

int main()
{
    Account a(600);

    // try-catch block
    // never type conversion happens in try-catch block
    try
    {
        a.withdraw(200);
        a.deposit(5000);
    }
    catch (int element)
    {
        std::cout << "Error throw : Minimum required 500 rupee\n";
    }
    catch (const char *msg)
    {
        std::cout << msg << '\n';
    }
    catch (UnderflowException uObj)
    {
        std::cerr << uObj.getMessage();
    }
    catch (OverflowException overObj)
    {
        std::cerr << overObj.getMessage();
    }
    catch (...) // generic catch which handles all throws
    {
        std::cout << "some error: not understand extact error\n";
    }

    return 0;
}