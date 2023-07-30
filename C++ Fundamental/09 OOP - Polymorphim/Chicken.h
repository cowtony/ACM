#pragma once

#include <iostream>
#include "Animal.h"

class Chicken : public Animal {
  public:
    void animalSound() const override;
};

void Chicken::animalSound() const {
    std::cout << "Chick chick \n";
}

