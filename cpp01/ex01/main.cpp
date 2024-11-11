/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:04:05 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/11 22:04:06 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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