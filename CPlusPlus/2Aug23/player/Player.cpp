#include <iostream>
#include "Player.h"

Player::Player()
{
    playerName = "Virat";
    playerNumber = 117;
    playerWeight = 65;
    playerHeight = 5.9;
}

Player::Player(std::string name, int number, double weight, double height)
    : playerName(name), playerNumber(number), playerWeight(weight), playerHeight(height)
{
}

Player::~Player()
{
}

void Player::accept()
{
    std::cout << "\nEnter player name, id number, weight, height respectively.\n";
    std::cin >> playerName >> playerNumber >> playerWeight >> playerHeight;
    std::cout << "\n";
}

void Player::display()
{
    std::cout << "\nplayer name = " << playerName
              << "\n player id = " << playerNumber
              << "\nweight = " << playerWeight
              << "\nheight = " << playerHeight
              << "\n";
}
