#include <iostream>

// Data member as a pointer

/*
Whenever class contains pointer as a attribute/data member,
then
 - implment destructor to avoid memory leakage
 - implement copy constructor to avoid dangling pointer

Let,we create object of a class in heap memory which contains pointer as a attribute /data member
e.g.:

    Student *s = new Student;
    delete s; //request to call destructor
*/

class Calculator
{

    int *arr;
    int *p;
    int size;

public:
    Calculator()
    {
        size = 3;
        arr = new int[size]; // stored in heap
        p = new int[size];
    }

    // explicity copy constructor ( Deep copy )
    // it avoid dangling pointer
    Calculator(Calculator& c) // c = c1
    {
        size = c.size; // c2.size = c.size
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = c.arr[i]; // c2.arr[i] = c.arr[i]
        }
    }

    // destructor
    // it will call when it goes out of scope
    // Destructor can't be overloaded and it called by IMPLICITY
    ~Calculator() // It avoid memory leakage
    {
        std::cout << "The destructor called\n";
        delete[] arr;
        delete[] p;
        std::cout << "The destructor called at end\n";
    }

    Calculator(int s)
    {
        size = s;
        arr = new int[size];
    }

    void accept()
    {
        std::cout << "\nEnter the elements : \n";
        for (int i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << "\n";
        }
    }

    float calAvg()
    {
        float sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += arr[i];
        }
        return sum / size;
    }

    //operator overloading
    bool operator==(Calculator &c)
    {
        if (calAvg() == c.calAvg())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void print(Calculator &c2) // c2.Calculate(c1)
{
    std::cout << "You are in print function\n";
    c2.display();
}

int main()
{

    Calculator c1, c2;
    c1.accept();
    c2.accept();
    if (c1 == c2) // c1.operator==(c2)
    {
        std::cout << "\nAvg is same.\n";
    }
    else
    {
        std::cout << "\nAvg is not same.\n";
    } 

    // Calculator c1; // stored in stack
    // c1.accept();
    // print(c1);

    // Calculator c4(c1);
    // c4.display();

    // Calculator *c3 = new Calculator;
    // delete c3; // request to called destructor

    return 0;
}