#ifndef BOWLER_H
#define BOWLER_H

#include "Cricketer.h"

enum class BowlerTypes
{
    SPINNER,
    LEFT_HANDED,
    RIGHT_HANDED,
    FASTER
};

class Bowler : virtual public Cricketer
{
private:
    int NumberOfWickets;
    enum BowlerTypes bowlerTypes;

public:
    Bowler();
    Bowler(std::string name, int number,
           double weight, double height, int catches, int wickets,
           BowlerTypes Type);
    ~Bowler();

    void accept();
    void display();

    enum BowlerTypes getBowlerTypes() const { return bowlerTypes; }
    void setBowlerTypes(const enum BowlerTypes &bowlerTypes_) { bowlerTypes = bowlerTypes_; }
};

#endif // BOWLER_H
