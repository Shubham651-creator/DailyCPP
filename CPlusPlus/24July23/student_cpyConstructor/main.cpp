#include <iostream>
#include "Student.h"

static int n = 0;

bool search(Student s[])
{
    int num;
    std::cout << "Enter searching Roll Number : ";
    std::cin >> num;

    for (int i = 0; i < n + 1; i++)
    {
        if (s[i].getRollno() == num)
        {
            std::cout << "Roll Number is found\n";
            return true;
        }
    }
    return false;
}

void modify(Student s[])
{
    int num;
    std::cout << "Enter Roll number to modify: ";
    std::cin >> num;

    std::cout << "Menu\t 1.name\t2.Enter marks\t3.Exit\n";
    int choice;
    std::cin >> choice;

    for (int i = 0; i < n + 1; i++)
    {
        switch (choice)
        {
        case 1: // name
            if (s[i].getRollno() == num)
            {
                std::string name;
                std::cin >> name;
                s[i].setName(name);
            }
            break;

        case 2: // marks
            if (s[i].getRollno() == num)
            {
                int mark;
                for (int j = 0; j < 5; j++)
                {
                    std::cin >> mark;
                    s[i].setMarks(&mark);
                }
            }
            break;

        case 3:
            break;
        }
    }
}

void showMenu(Student s[])
{
    int choice;
    do
    {
        std::cout << "MENU\t1.Search\t2.Modify\t3.Display\t4.Add Student\t5.Compare Averge\t6.Exit\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            search(s);
            break;

        case 2:
            modify(s);
            break;

        case 3:
            for (int j = 0; j < n + 1; j++)
            {
                s[j].display();
            }
            break;

        case 4:
            n++;
            s[n].accpet();
            break;

        case 5:
            int first, second;
            std::cout << "Enter first roll number: ";
            std::cin >> first;
            std::cout << "Enter second roll number: ";
            std::cin >> second;

            bool flag;
            // flag = s[first - 1].compareAverage(s[second - 1]);

            if (s[first - 1] >= s[second - 1])
            {
                std::cout << "The " << s[first - 1].getName() << " has higher marks than " << s[second - 1].getName() << "\n";
            }
            else
            {
                std::cout << "The " << s[first - 1].getName() << " has lower marks than " << s[second - 1].getName() << "\n";
            }

            break;
        case 6:
            exit(0);
            break;
        }

    } while (1);
}

int main()
{
    Student s[100];
    s[0].accpet();
    showMenu(s);

    return 0;
}