#include <iostream>
#include "Inventory.h"

int searchProduct(Inventory *inventory, std::string productName)
{

    for (int i = 0; i < 5; i++)
    {
        if (productName == inventory[i].descriptionOfProduct())
        {
            // std::cout << "product found\n";
            return i;
            break;
        }
    }

    std::cout << "Product not found\n";
    return -1;
}

void showMenu(Inventory *inventory)
{
    int choice;
    do
    {
        std::cout << "Menu: 1.Display\t2.Search Product\t3.Purchase\t4.Sales\t5.Exit\n";
        std::cin >> choice;
        std::string productName;
        switch (choice)
        {
        case 1:
            // display
            for (int i = 0; i < 5; i++)
            {
                std::cout << inventory[i];
            }
            break;

        case 2:
            // searching
            std::cout << "Enter searching product name : ";
            std::cin >> productName;
            if (searchProduct(inventory, productName) != -1)
            {
                std::cout << "Product is found\n";
            }
            break;

        case 3:
            // purchase
            std::cout << "Enter purchasing product name : ";
            std::cin >> productName;
            if (searchProduct(inventory, productName) != -1)
            {
                int index = searchProduct(inventory, productName);
                inventory[index].purchase();
            }
            break;

        case 4:
            // sales
            std::cout << "Enter Sales product name : ";
            std::cin >> productName;
            if (searchProduct(inventory, productName) != -1)
            {
                int index = searchProduct(inventory, productName);
                inventory[index].sale();
            }
            break;

        case 5:
            exit(0);
            break;
        }

    } while (1);
}

int main()
{

    Inventory *inventory = new Inventory[5];

    for (int i = 0; i < 5; i++)
    {
        std::cin >> inventory[i];
    }

    showMenu(inventory);

    delete[] inventory;

    return 0;
}