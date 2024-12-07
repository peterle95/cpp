/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:04:05 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/07 16:57:15 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int validateInput(int hordeSize)
{
    if (!(hordeSize > 0 && hordeSize <= 100))
        return 1;
    return 0;
}
int main() 
{
    int hordeSize;
    std::cout << "Enter the number of zombies to create: ";
    std::cin >> hordeSize;
    if(validateInput(hordeSize))
    {
        std::cout << "Invalid input. Please enter a positive integer between 1 and 100." << std::endl;
        return 1;
    }
    Zombie* horde = zombieHorde(hordeSize, "ZombieClone");
    
    for (int i = 0; i < hordeSize; ++i) 
    {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }

    delete[] horde;

    return 0;
}