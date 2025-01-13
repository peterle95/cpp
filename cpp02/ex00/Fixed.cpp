/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:04:14 by pmolzer           #+#    #+#             */
/*   Updated: 2025/01/13 15:55:02 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/* 
Default constructor for the Fixed class. 
This constructor initializes the fixed-point value to 0 and outputs a message.
*/
Fixed::Fixed() : _fixedPointValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

/* 
Copy constructor for the Fixed class. 
This constructor creates a new Fixed object as a copy of an existing one.
*/
Fixed::Fixed(const Fixed &src) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src; // 'this' is a pointer to the current object, allowing access to its members.
}

/* 
Copy assignment operator for the Fixed class. 
This operator allows one Fixed object to be assigned the value of another.*/
Fixed &Fixed::operator=(const Fixed &rhs)
{
/* The syntax 'Fixed &Fixed::operator=(const Fixed &rhs)' defines the copy assignment operator for the Fixed class.
- 'Fixed &' indicates that this function returns a reference to a Fixed object. This allows for 
  chaining of assignment operations (e.g., a = b = c).
- 'Fixed::' specifies that this operator function is a member of the Fixed class. It indicates 
  that the function is associated with the Fixed class and can access its private members.
- 'operator=' is the name of the function, which is a special operator function in C++. 
  It allows the use of the assignment operator '=' to assign one Fixed object to another.
- 'const Fixed &rhs' is the parameter of the function. It is a reference to a constant Fixed object 
  that represents the right-hand side of the assignment. The 'const' qualifier ensures that the 
  original object (rhs) will not be modified during the assignment process, promoting safety and 
  preventing unintended side effects.
- Overall, this syntax defines how one Fixed object can be assigned the value of another Fixed object 
  while ensuring proper memory management and preventing self-assignment issues.*/
     std::cout << "Copy assignment operator called" << std::endl;
     
     /* Check if the current object is not the same as the object being assigned from (rhs). 
        This prevents self-assignment, which could lead to issues. */
     if (this != &rhs) // 'this' is a pointer to the current object, used to check for self-assignment.
         /* If they are different, set the current object's fixed-point value to the raw value of the rhs object. 
            This is done by calling the getRawBits() method on rhs. */
         this->_fixedPointValue = rhs.getRawBits();
     
     /* Return a reference to the current object to allow for chained assignments. */
     return *this; // Returns a reference to the current object.
}

/* 
Destructor for the Fixed class. 
This destructor is called when a Fixed object goes out of scope.
*/
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

/* 
Member function to get the raw fixed-point value. 
This function returns the value of _fixedPointValue and indicates that it was called.
*/
int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

/* 
Member function to set the raw fixed-point value. 
This function sets _fixedPointValue to the provided raw value.
*/
void Fixed::setRawBits(int const raw) 
{
    this->_fixedPointValue = raw;
}

/* 
Relation to Other Code in the Project:
This file, Fixed.cpp, contains the implementation of the Fixed class defined in Fixed.hpp. 
It includes the definitions of the constructors, destructor, and member functions that manage 
the fixed-point number representation. The main function in main.cpp utilizes this class 
to create instances and demonstrate its functionality, such as object copying and value assignment. 
The output messages in this file help trace the flow of object creation and manipulation, 
providing insight into how the class operates during execution.
*/