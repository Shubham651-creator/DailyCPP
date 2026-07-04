#include <iostream>
#include "Student.h"

void operator>>(std::istream &in, Student &s)
{
    in >> s.name;
    for (int i = 0; i < 5; i++)
    {
        in >> s.marks[i];
    }
}

void operator<<(std::ostream &out, const Student &s)
{
    out << "Name: " << s.name << "\n";
    for (int i = 0; i < 5; i++)
    {
        out << s.marks[i] << "\t";
    }
    out << std::endl;
}

int main()
{

    // Function overloading and return by ref : 25 July 2023
    Student s1;

    // take input - accpet()
    std::cin >> s1; // operator>>(cin, s1) - friend function

    // Display()
    std::cout << s1; // operator<<(cout, s1) - friend function

    //[]overloading
    // it returns the index value of marks array
    int ele = s1[2]; // ele = s1.operator[](2)
    std::cout << "The index value of marks array: ele = " << ele << "\n";

    // For below implementation used return changed 'int' into 'int&'
    s1[3] = 98; // s1.operator[](3) = 55
    for (int i = 0; i < 5; i++)
    {
        std::cout << "The changed marks array = " << s1[i] << "\n";
    }

    // modify element at index 2 by 44
    //()overloading
    s1(2, 14);
    for (int i = 0; i < 5; i++)
    {
        std::cout << "s1(2,14) = " << s1[i] << "\n";
    }

    /*
        1. std::cin>>s1;
        2. std::cout<<s2;

        3. int ele = s1[2]; // ele = s1.operator[](2)

            s1[3] = 55 ; //s1.operator[](3) = 55

        4. s1(2, 44); //modify element at index 2 by 44

    */

    return 0;
}