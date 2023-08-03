#ifndef BATSMAN_H
#define BATSMAN_H

#include "Cricketer.h"

class Batsman : virtual public Cricketer
{
protected:
    double strikeRate;
    int batsmanRuns;

public:
    Batsman();
    Batsman(std::string name, int number, double weight, double height, int catches, double sRate, int runs);
    ~Batsman();

    void accept();
    void display();
};

#endif // BATSMAN_H
