#include <iostream>
#include "Travel.h"

void searchTrain(Travel travel[], int size)
{
    std::string train_name;
    std::cout << "Enter train number: ";
    std::cin >> train_name;

    for (int trainCount = 0; trainCount < size; trainCount++)
    {
        if (train_name == travel[trainCount].getTrainName())
        {
            std::cout << "Train is found\n";
            return;
        }
    }
    std::cout << "Train is NOT found\n";
    return;
}

int main()
{
    Travel travel[5];
    int size = 2;

    for (int trainCount = 0; trainCount < size; trainCount++)
    {
        travel[trainCount].accept();
    }
    for (int trainCount = 0; trainCount < size; trainCount++)
    {
        travel[trainCount].display();
    }

    // search the train onces
    searchTrain(travel, size);
    searchTrain(travel, size);

    return 0;
}