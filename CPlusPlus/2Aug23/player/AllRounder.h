#ifndef ALLROUNDER_H
#define ALLROUNDER_H

#include "Batsman.h"
#include "Bowler.h"

class AllRounder : public Batsman, public Bowler
{
private:
    int allRounderRank;

public:
    AllRounder();
    AllRounder(std::string name, int number,
               double weight, double height, int catches, int wickets,
               BowlerTypes Type, double sRate, int runs, int rank);
    ~AllRounder();

    void accept();
    void display();
};



#endif // ALLROUNDER_H
