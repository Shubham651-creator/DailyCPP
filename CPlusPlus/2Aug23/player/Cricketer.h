#ifndef CRICKETER_H
#define CRICKETER_H

#include <iostream>
#include "Player.h"

class Cricketer : public Player
{
private:
  int numberOfCatches;

public:
  Cricketer();
  Cricketer(std::string name, int number, double weight, double height, int catches);
  ~Cricketer();

  void accept();
  void display();
};

#endif // CRICKETER_H
