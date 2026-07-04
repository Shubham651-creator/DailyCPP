#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student
{
    static int rollno; // auto-generate

    int roll;
    std::string name;
    int marks[5];

    float avg;

public:
    static int marks_count;
    Student();
    Student(std::string name, int marks[]);

    //25 july 23
    int& operator[](int index);
    void operator() (int index, int value);
    // void accpet();
    friend void operator>>(std::istream& in, Student& s);
    // void display();
    friend void operator<<(std::ostream& out, const Student& s);


    float calcuteAvergeMarks();
    int calculateMinMarks();
    int calculateMaxMarks();

    void sortMarks();
    bool compareAverage(Student s);

    int getRollno() { return roll; }

    std::string getName() const { return name; }
    void setName(const std::string &name_) { name = name_; }

    int getMarks() const
    {
        if (marks_count == 5)
        {
            marks_count = 0;
        }
        return marks[marks_count++];
    }
    void setMarks(int marks_)
    {
        if (marks_count < 6)
        {
            marks[marks_count] = marks_;
            // std::cout<<"The marks is "<<marks[marks_count]<<"\n";
            marks_count++;

            if (marks_count == 5)
            {
                marks_count = 0;
                // std::cout<<"The marks count=zero is "<<marks_count<<"\n";
            }
        }
    }

    float getAvg() const { return avg; }
    void setAvg(float avg_) { avg = avg_; }
};

#endif // STUDENT_H
