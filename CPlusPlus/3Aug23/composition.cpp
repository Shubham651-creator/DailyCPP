#include <iostream>

// containment = has a relation or is a part relation

/*
    composition------> create object in another class is data member
    -physical
    e.g. mobile and simcard; classroom and table, AC, student;


    agreegation------->
    -logical
    e.g. pancard and customer
*/

class Simcard
{
    int simNumber;
    std::string type;
    std::string vendor;

public:
    Simcard()
    {
        simNumber = 123;
        type = "idea";
        vendor = "VI";
    }
    Simcard(int snum, std::string typ, std::string ven)
    {
        simNumber = snum;
        type = typ;
        vendor = ven;
    }
    void display()
    {
        std::cout << "simnumber = " << simNumber
                  << "\ntype = " << type
                  << "\nvendor = " << vendor
                  << "\n";
    }
};

class Mobile // container class
{
    int price;
    std::string brand;
    int weight, ht, wdt;

    Simcard sm1; // composition or containment object

public:
    Mobile()
    {
        price = 50000;
        brand = "apple";
    }

    Mobile(int prices, std::string bname, Simcard sim)
    {
        price = prices;
        brand = bname;
        sm1 = sim;
    }
    void display()
    {
        std::cout << "\nMObile price : "
                  << price << " \n brand =  " << brand << " "
                  << "\n";
        sm1.display();
        std::cout << "\n\n";
    }
};

int main()
{
    Mobile m1;
    m1.display();

    Mobile m2(540800, "onePlus", Simcard(3433, "mini", "airtel"));
    m2.display();
    return 0;
}