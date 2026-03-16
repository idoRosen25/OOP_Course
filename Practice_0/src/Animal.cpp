#include "Animal.h"
#include <iostream>

Animal::Animal(std::string name) : name(name) {}

void Animal::speak() {
    std::cout << name << " makes a sound." << std::endl;
}
