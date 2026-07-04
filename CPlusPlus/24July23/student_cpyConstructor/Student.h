#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student
{
    static int rollno; // auto-generate

    int roll;
    std::string name;
    int *marks;   //pointer

    float avg;

public:
    static int marks_count;
    Student();
    ~Student();
    Student(std::string name, int marks[]);

    // copy constructor
    Student(Student &s);

    int rollNumber();

    float calcuteAvergeMarks();
    int calculateMinMarks();
    int calculateMaxMarks();

    void sortMarks();
    // bool compareAverage(Student s);
    bool operator>=(Student &s);

    void accpet();
    void display();

    int getRollno() { return roll; }

    std::string getName() const { return name; }
    void setName(const std::string &name_) { name = name_; }

    float getAvg() const { return avg; }
    void setAvg(float avg_) { avg = avg_; }

    int *getMarks() const { return marks; }
    void setMarks(int *marks_) { marks = marks_; }
};

#endif // STUDENT_H
