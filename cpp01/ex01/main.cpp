#include "Zombie.hpp"
#include <iostream>

int main() 
{
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "ZombieClone");

    for (int i = 0; i < hordeSize; ++i) {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }

    delete[] horde;

    return 0;
}