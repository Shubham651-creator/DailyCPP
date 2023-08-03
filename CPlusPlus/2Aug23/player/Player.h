#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
private:
    std::string playerName;
    int playerNumber;
    double playerWeight, playerHeight;

public:
    Player();
    Player(std::string name, int number, double weight, double height);
    ~Player();

    void accept();
    void display();
};

#endif // PLAYER_H
