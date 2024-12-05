/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:15:36 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/05 16:44:33 by pmolzer          ###   ########.fr       */
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

int main() 
{
    // Create a new Zombie on the heap with the name "Heapy" and store its pointer in heapZombie.
    Zombie* heapZombie = newZombie("Heapy"); 
    // Call the announce method on the heapZombie to make it announce itself.
    // The '->' operator is a member access operator that allows us to access the members 
    // (both methods and attributes) of an object through a pointer. 
    // In this context, heapZombie is a pointer variable that holds the address of a 
    // Zombie object created on the heap. 

    // WHEN WE USE THE '->' OPERATOR, WE ARE EFFECTIVELY DEREFERENCING THE POINTER TO 
    // ACCESS THE ZOMBIE OBJECT IT POINTS TO. 
    
    // This means we can directly invoke the methods defined in the Zombie class, 
    // such as the announce method. 
    // By calling heapZombie->announce(), we are instructing the program to execute 
    // the announce method for the specific Zombie instance referred to by heapZombie. 
    // This method will output the Zombie's name followed by the characteristic sound, 
    // demonstrating the functionality of the Zombie class.
    heapZombie->announce(); 
    
    // Create a new Zombie on the stack with the name "Stacky" and make it announce itself.
    randomChump("Stacky"); 
    
    // Delete the heap-allocated Zombie to free up memory.
    delete heapZombie; 
    // Return 0 to indicate that the program finished successfully.
    return 0; 
}