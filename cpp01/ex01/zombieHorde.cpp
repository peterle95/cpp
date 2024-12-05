/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:23:41 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/05 16:52:06 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// This function creates a horde of N Zombies and assigns them a given name.
Zombie* zombieHorde(int N, std::string name) 
{
    Zombie *horde = new Zombie[N]; 
    // Dynamically allocate an array of N Zombies. The variable 'horde' is a pointer 
    // because it holds the address of the first element of the dynamically allocated 
    // array in heap memory, allowing access to all Zombie objects in the array.
    
    for (int i = 0; i < N; ++i) 
    { // Loop through each Zombie in the horde.
        // The setName method is called on the current Zombie object in the horde array, which is accessed using the index 'i'.
        // This method takes the 'name' parameter, which is a string passed to the zombieHorde 
        // function, and assigns it to the 'name' attribute of the Zombie object.
        // By doing this, each Zombie in the horde is given the same name, allowing them to 
        // share a common identity while still being distinct objects in memory.
        // This operation is crucial for ensuring that each Zombie can announce itself with 
        // the correct name later on.
        horde[i].setName(name); // Set the name of the current Zombie to the provided name.

        // horde is a pointer to an array of Zombie objects. 
        // Since horde[i] accesses the Zombie object at index i, we use the dot operator (.) 
        // to call the setName method on that object. 
        // If we were to use horde[i]->setName(name), it would imply that horde[i] is a pointer 
        // to a Zombie object, which it is not; horde[i] is the actual Zombie object itself.
    }
    
    return horde; // Return the pointer to the array of Zombies.
}

/* To use horde->setName(name); and horde->next, you would need to change 
the structure of your Zombie class and how the horde is defined. Currently, 
horde is an array of Zombie objects, and you cannot use the arrow operator (->) directly on an array.
If you want to use horde->setName(name);, you would typically need to have horde 
be a pointer to a single Zombie object or a linked list structure where each Zombie 
has a pointer to the next Zombie. Here's how you could implement a linked list structure for your Zombie objects:
Example of a Linked List Structure

Modify the Zombie class to include a pointer to the next Zombie:

class Zombie {
public:
    std::string name;
    Zombie* next; // Pointer to the next Zombie in the list

    void setName(std::string newName) {
        name = newName;
    }
};

Change the zombieHorde function to create a linked list:

Zombie* zombieHorde(int N, std::string name) 
{
    if (N <= 0) return nullptr; // Handle case where N is non-positive

    Zombie* head = new Zombie; // Create the first Zombie
    head->setName(name); // Set the name for the first Zombie
    Zombie* current = head; // Pointer to track the current Zombie

    for (int i = 1; i < N; ++i) 
    {
        current->next = new Zombie; // Create the next Zombie
        current = current->next; // Move to the next Zombie
        current->setName(name); // Set the name for the current Zombie
    }
    current->next = nullptr; // Terminate the list

    return head; // Return the pointer to the head of the list
} */