/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:15:36 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/07 13:11:57 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TASK OF THE PROGRAM:
 * The program creates a Zombie on the heap and a Zombie on the stack, then deletes them.
 * First, implement a Zombie class. It has a string private attribute name.
 * Add a member function void announce( void ); to the Zombie class. Zombies
 * announce themselves as follows:
 * <name>: BraiiiiiiinnnzzzZ...
 * Don’t print the angle brackets (< and >). For a zombie named Foo, the message
 * would be:
 * Foo: BraiiiiiiinnnzzzZ...
 * Then, implement the two following functions:
 * • Zombie* newZombie( std::string name );
 *  It creates a zombie, name it, and return it so you can use it outside of the function
 *  scope.
 *  • void randomChump( std::string name );
 *  It creates a zombie, name it, and the zombie announces itself.
 * Now, what is the actual point of the exercise? You have to determine in what case
 * it’s better to allocate the zombies on the stack or heap.
 * Zombies must be destroyed when you don’t need them anymore. The destructor must
 * print a message with the name of the zombie for debugging purposes.
 */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() 
{
    Zombie* heapZombie = newZombie("Heapy");
    heapZombie->announce();
    
    randomChump("Stacky");
    
    delete heapZombie;
    return 0;
}