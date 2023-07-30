#pragma once

#include <memory>

#include "Pig.h"
#include "Dog.h"
#include "Chicken.h"


std::shared_ptr<Animal> createAnimal(const std::string& animal_type) {
    if (animal_type == "pig") {
        return std::make_shared<Pig>();
    } else if (animal_type == "dog") {
        return std::make_shared<Dog>();
    } else if (animal_type == "teddy") {
        return std::make_shared<Teddy>();
    } else if (animal_type == "chicken") {
        return std::make_shared<Chicken>();
    } else {
        return nullptr;
    }
}
