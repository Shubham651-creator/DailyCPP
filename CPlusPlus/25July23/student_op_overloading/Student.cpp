#include <iostream>
#include "Student.h"

Student::Student()
{
    roll = rollno;
    name = "shubham";
    int marks[5] = {1, 2, 3, 4, 5};
    rollno++;
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
}
bool Student::compareAverage(Student s)
{
    if (avg > s.avg) // first > second
    {
        return true;
    }
    return false;
}

int& Student::operator[] (int index){
    return marks[index];
}

void Student::operator() (int index, int value){
    marks[index]= value;
}

int Student::rollno = 1;

int Student::marks_count = 0;