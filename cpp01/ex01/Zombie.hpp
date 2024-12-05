/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:23:36 by pmolzer           #+#    #+#             */
/*   Updated: 2024/12/05 16:46:08 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP // Include guard to prevent multiple inclusions of this header file
#define ZOMBIE_HPP

#include <string> // Include the string library for using std::string

// Class representing a Zombie with a name and behaviors
class Zombie 
{
private:
    std::string name; // Private member variable to store the name of the Zombie

public:
    Zombie(); // Default constructor declaration
    Zombie(std::string name); // Constructor that takes a string to initialize the Zombie's name
    ~Zombie(); // Destructor declaration

    void announce() const; // Method to announce the Zombie's presence
    // The '&' symbol indicates that the parameter 'name' is passed by reference, 
    // which avoids making a copy of the std::string object. This is more efficient, 
    // especially for large strings, as it reduces memory usage and improves performance.
    void setName(const std::string& name); // Method to set the Zombie's name
};

Zombie* zombieHorde(int N, std::string name); // Function prototype to create a horde of Zombies

#endif