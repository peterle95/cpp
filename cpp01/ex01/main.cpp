/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:12:55 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:22:29 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TASK OF THE PROGRAM:
Implement the following function in the appropriate file:
Zombie* zombieHorde( int N, std::string name );
It must allocate N Zombie objects in a single allocation. Then, it has to initialize the
zombies, giving each one of them the name passed as parameter. The function returns a
pointer to the first zombie.
Implement your own tests to ensure your zombieHorde() function works as expected.
Try to call announce() for each one of the zombies.
Don’t forget to delete all the zombies and check for memory leaks.
*/

#include "Zombie.hpp"
#include <iostream>

// The main function serves as the entry point of the program. 
// It creates a horde of zombies, announces each one, and then cleans up the allocated memory.
int main() 
{
    int hordeSize;
    std::cout << "Enter the number of zombies in the horde: ";
    std::cin >> hordeSize;
    Zombie* horde = zombieHorde(hordeSize, "ZombieClone"); // Allocate a horde of zombies and initialize them with the name "ZombieClone".

    for (int i = 0; i < hordeSize; ++i)  // Loop through each zombie in the horde.
    {
        std::cout << "Zombie " << i + 1 << ": "; // Print the index of the current zombie.
        horde[i].announce(); // Call the announce method for the current zombie to display its message.
    }

    delete[] horde; // Deallocate the memory used for the horde of zombies.

    return 0; // Return 0 to indicate successful completion of the program.
}