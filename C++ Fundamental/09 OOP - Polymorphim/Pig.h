#pragma once

#include <iostream>
#include "Animal.h"

class Pig : public Animal {
  public:
    void animalSound() const override;
};



void Pig::animalSound() const {
    std::cout << "The pig says: wee wee \n";
}