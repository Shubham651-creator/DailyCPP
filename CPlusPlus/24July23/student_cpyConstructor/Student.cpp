#include <iostream>
#include "Student.h"

Student::Student()
{
    roll = rollno;
    name = "shubham";
    marks = new int[5];
    rollno++;
}

Student::~Student()
{
    delete[] marks; // to avoid memory leakage
}

// deep copy constructor
Student::Student(Student &s)
{
    this->roll = s.roll;
    this->name = s.name;
    marks = new int[5];
    for (int i = 0; i < 5; i++)
    {
        this->marks[i] = marks[i];
    }
}

Student::Student(std::string name, int marks[5])
{
    roll = rollno;
    this->name = name;
    for (int i = 0; i < 5; i++)
    {
        this->marks[i] = marks[i];
    }
    rollno++;
}

int Student::rollNumber() // auto-generate
{
    return 0;
}
float Student::calcuteAvergeMarks()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += marks[i];
    }
    avg = sum / 5;
    return avg;
}
int Student::calculateMaxMarks()
{
    int mx = 0;
    for (int i = 0; i < 5; i++)
    {
        if (marks[i] > mx)
        {
            mx = marks[i];
        }
    }
    return mx;
}
int Student::calculateMinMarks()
{
    int min = calculateMaxMarks();
    for (int i = 0; i < 5; i++)
    {
        if (marks[i] < min)
        {
            min = marks[i];
        }
    }
    return min;
}

void Student::sortMarks()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (marks[i] < marks[j])
            {
                int temp = marks[j];
                marks[j] = marks[i];
                marks[i] = temp;
            }
        }
    }
    std::cout << "The sorted array is ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << marks[i] << "\t";
    }
    std::cout << "\n\n";
}

// operator overloading
bool Student::operator>=(Student &s)
{
    if (avg > s.avg)
        return true;
    else
        return false;
}

void Student::accpet()
{
    std::string sname;
    std::cout << "Enter Student's name : ";
    std::cin >> sname;
    name = sname;

    for (int i = 0; i < 5; i++)
    {
        std::cin >> marks[i];
    }
    sortMarks();
}
void Student::display()
{

    std::cout << "Name: " << name << "\n";
    std::cout << "Roll Number : " << roll << "\n";
    std::cout << "Marks: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << marks[i] << "\t";
    }
    std::cout << "\nAverge marks of " << name << " is " << calcuteAvergeMarks() << "\n";
    std::cout << "\nMaximum marks of " << name << " is " << calculateMaxMarks() << "\n";
    std::cout << "\nMinimum marks of " << name << " is " << calculateMinMarks();

    std::cout << "\n\n";
}

int Student::rollno = 1;

int Student::marks_count = 0;