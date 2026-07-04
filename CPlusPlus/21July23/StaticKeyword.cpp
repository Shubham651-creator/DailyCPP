#include <iostream>

// To implement getter and setter use ctrl+ dot(.)

class Account
{
    // non static member - created per object
    int accNumber;
    std::string cname;
    float balance;

    // shared attribute for all object
    // class variable- for whole class single copy is created
    static double rateOfInterest; // rate of interest is same for all
    static int cnt;
    static int x;

public:
    // getter method / accessor method- to access valure of particular attribute
    int getAccNum() { return accNumber; }
    std::string getCname() { return cname; }
    float getBalance() { return balance; }

    // setter method/ mutator method - to change value of particular attribute
    void setAccNum(int a) { accNumber = a; }
    void setCname(std::string c) { cname = c; }
    void setBalance(float b) { balance = b; }

    Account()
    {
        accNumber = cnt;
        cname = "shubham";
        balance = 30100;
        cnt++;
        x++;
    }

    Account(std::string cnm, float bal)
    {
        accNumber = cnt;
        cname = cnm;
        balance = bal;
        cnt++;
        x++;
    }

    void show() const
    {
        std::cout << accNumber << " " << cname << " " << balance << "\n";
    }

    static int getX() { return x; }
};

// void search(Account arr[], int n)
// {
//     int num;
//     std::cout << "Enter account number to search: ";
//     std::cin >> num;
//     bool flag = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i].getAccNum() != num)
//         {
//             std::cout << "Account is found\n";
//             flag = true;
//             break;
//         }
//     }
//     if (!flag)
//         std::cout << "Account is NOT found\n";
// }

void showMeun()
{
}

int Account::cnt = 21038495;
int Account::x = 0;

int main()
{

    // Account *ptr = new Account;
    // ptr->show();

    // Account arr[3] = {
    //     {101, "sanket", 10000},
    //     {102, "srujesh", 20000},
    //     {103, "awale", 30000}};

    // const Account a; // const object
    // a.show();        // const object can call constant function only


    // We can access static member functions,
    //without creating class object
    std::cout << Account::getX();

    return 0;
}