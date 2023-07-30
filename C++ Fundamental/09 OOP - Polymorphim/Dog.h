#pragma once

#include <iostream>
#include "Animal.h"

class Dog : public Animal {
  public:
    void animalSound() const override {
      std::cout << "The dog says: bow wow \n";
    }
};

class Teddy : public Dog {
  public:
    void animalSound() const override {
      std::cout << "The Teddy says: I'm a teddy dog \n";
    }
};
