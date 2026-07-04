#include <iostream>
#include "CarNew.h"
#include "CarCategoryNew.h"

// dont use global varible much which is bad practice
// SOR : separation of Responsibility!

// how to take enum as input
enum CarCategoryNew TakeInputGiveEnum()
{
    int choice = 0;
    std::cout << "Enter : 1.SUV; 2.Sedan; 3.Sprot; 4.HatchBack\n";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        return CarCategoryNew::SUV; 
    case 2:
        return CarCategoryNew::Sedan; 
    case 3:
        return CarCategoryNew::Sport; 
    case 4:
        return CarCategoryNew::HatchBack; 
    default:
        return CarCategoryNew::NA; 
    }
}

void createObject(CarNew **arr, int N)
{
    std::string name;
    int count;
    enum CarCategoryNew carCategory;
    float price;

    for (int i = 0; i < N; i++)
    {
        std::cin >> name >> count >> price;

        carCategory = TakeInputGiveEnum();
        // std::cout << name<<"\n" << count <<"\n"<< price<<"\n" << carCategory<<"\n";
        
        arr[i] = new CarNew(name, count, carCategory, price);
        // CarNew(name, count, carCategory, price);
        arr[i]->display();
    }

    // for (int i = 0; i < N; i++)
    // {
    //     std::cout << name<<"\n" << count <<"\n"<< price<<"\n" << carCategory<<"\n";
    // }
}

int main()
{
    // array of pointer
    CarNew *arr[3];
    createObject(arr, 3);

    return 0;
}

/*

    ("DZIRE", 5, carCategory::Sadan, 500000.0f)
*/
