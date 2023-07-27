#include <iostream>
#include "Account.h"

static int n = 0;

void search(Account arr[], int n)
{
    int num;
    std::cout << "Enter account number to search: ";
    std::cin >> num;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].getAccNum() == num)
        {
            std::cout << "Account is found\n";
            flag = true;
            break;
        }
    }
    if (!flag)
        std::cout << "Account is NOT found\n";
}

void modify(Account arr[], int n)
{
    int num;
    std::cout << "Enter account number to modify: ";
    std::cin >> num;

    std::cout << "Menu\t 1.name\t2.balance\t3.Withdraw\t4.deposit\t5.Exit\n";
    int choice;
    std::cin >> choice;

    for (int i = 0; i < n; i++)
    {
        switch (choice)
        {
        case 1:
            if (arr[i].getAccNum() == num)
            {
                std::string name;
                std::cin >> name;
                arr[i].setCname(name);
            }
            break;

        case 2:
            if (arr[i].getAccNum() == num)
            {
                float bal;
                std::cin >> bal;
                arr[i].setBalance(bal);
            }
            break;

        case 3:
            if (arr[i].getAccNum() == num)
            {
                float w;
                std::cout << "Enter withdraw amount = ";
                std::cin >> w;
                arr[i].withdraw(w);
            }
            break;

        case 4:
            if (arr[i].getAccNum() == num)
            {
                float dep;
                std::cout << "Enter deposit amount = ";
                std::cin >> dep;
                arr[i].deposit(dep);
            }
            break;

        case 5:
            exit(0);
        }
    }
}

void putData(Account arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].show();
    }
}

void showMeun(Account arr[], int n)
{
    int choice;
    char ch;
    do
    {
        std::cout << "Application: 1.Search\t2.Modify\t3.Display\t4.Add customer\t5.Exit \n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            search(arr, n);
            break;

        case 2:
            modify(arr, n);
            break;
        case 3:
            putData(arr, n+1);
            break;
        case 4:
            n++;
            std::cout<<"the value of n = "<<n<<"\n";
            arr[n].accept();
            break;
        case 5:
            exit(0);
            break;

        default:
            break;
        }

    } while (1);
}

int main()
{
    // int n = 3;
    // std::cout << "Enter Number of customers: ";
    // std::cin >> n;

    Account arr[100];

    // for (int i = 0; i < n; i++)
    // {
    //     arr[i].accept();
    // } // take a user input

    arr[0].accept();
    showMeun(arr, n);
    std::cout << "Number of customer in database= " << Account::getX() << "\n";

    // make object using pointer which assigned memory to heap
    std::cout << "Create object using pointer i.e assigned memory in heap\n";
    Account *a = new Account;
    a->show();
    std::cout << "release the heap memory using 'delete' keyword.\n";
    delete a;

    // create const object
    std::cout << "\nCreated the object using const keyword\n";
    const Account a1;
    a1.show();

    //a1.setBalance(); //compiled time error

    return 0;
}