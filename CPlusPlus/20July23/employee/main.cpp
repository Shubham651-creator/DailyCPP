#include <iostream>
#include "Employee.h"

void search(Employee arr[], int n)
{
    int num;
    std::cout << "Enter Employee number to search: ";
    std::cin >> num;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].getEmpid() == num)
        {
            std::cout << "Employee is found\n";
            flag = true;
            break;
        }
    }
    if (!flag)
        std::cout << "Employee is NOT found\n";
}

void modify(Employee arr[], int n)
{
    int num;
    std::cout << "Enter Employee number to modify: ";
    std::cin >> num;

    std::cout << "Menu\t 1.Employee name\t2.Salary\n";
    int choice;
    std::cin >> choice;

    for (int i = 0; i < n; i++)
    {
        switch (choice)
        {
        case 1:
            if (arr[i].getEmpid() == num)
            {
                std::string name;
                std::cin >> name;
                arr[i].setEname(name);
            }
            break;

        case 2:
            if (arr[i].getEmpid() == num)
            {
                float bal;
                std::cin >> bal;
                arr[i].setSalary(bal);
            }
            break;

        default:
            break;
        }
    }
}

void putData(Employee arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].show();
    }
}

void showMeun(Employee arr[], int n)
{
    int choice;
    char ch;
    do
    {
        std::cout << "Application: 1.Search\t2.Modify\t3.Display \n";
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
            putData(arr, n);
            break;

        default:
            break;
        }
        std::cout << "\nDo you want further operations(y/n)? ";
        std::cin >> ch;

    } while (ch == 'y');
}

void getData(Employee arr[], int n)
{ 
    float bal;
    std::string name;
    for (int i = 0; i < n; i++)
    {
        std::cin>> name >> bal; 
        arr[i].setEname(name);
        arr[i].setSalary(bal);
    }
}

int main()
{
     int n ;
    std::cout << "Enter Number of employee: ";
    std::cin >> n;

    Employee e[n]; 

    getData(e, n); // take a user input

    showMeun(e, n);

    // make object using pointer which assigned memory to heap
    std::cout << "Create object using pointer i.e assigned memory in heap\n";
    Employee *a = new Employee;
    a->show();
    std::cout << "release the heap memory using 'delete' keyword.\n";
    delete a;

    /*

    Const object:

    We don’t want the object to be modified after,
    it has been initialized with values, not even by mistake.

    So to restrict only certain objects from modification we use const objects because 
    the const object attributes cannot be changed once initialized with values.
    */
    std::cout << "\nCreated the object using const keyword\n";
    const Employee a1;
    a1.show();

    //a1.setSalary(1500.00f); //give error because a1 is constant obj.

    return 0;
}