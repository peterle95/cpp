/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:16 by pmolzer           #+#    #+#             */
/*   Updated: 2025/01/17 13:42:37 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor initializes the fixed point value to 0
Fixed::Fixed()
{
    _fixedPointValue = 0;
}

// Constructor that initializes the fixed point value from an integer
Fixed::Fixed(const int n)
{
    _fixedPointValue = n << _fractionalBits;
}

// Constructor that initializes the fixed point value from a float
Fixed::Fixed(const float n) 
{
    _fixedPointValue = roundf(n * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &src) 
{ 
    *this = src; 
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &rhs) 
{
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed() {}

// Returns the raw fixed point value
int Fixed::getRawBits(void) const 
{ 
    return this->_fixedPointValue; 
}

// Sets the raw fixed point value
void Fixed::setRawBits(int const raw) 
{ 
    this->_fixedPointValue = raw; 
}

// Converts the fixed point value to a float
float Fixed::toFloat(void) const 
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

// Converts the fixed point value to an integer
int Fixed::toInt(void) const 
{ 
    return this->_fixedPointValue >> _fractionalBits; 
}

// Greater than operator
// This function overloads the '>' operator to compare two Fixed objects.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// The function returns true if the current object's fixed-point value is greater than that of the rhs object.
bool Fixed::operator>(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue > rhs._fixedPointValue; 
}

// Less than operator
// This function overloads the '<' operator to compare two Fixed objects.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// The function returns true if the current object's fixed-point value is less than that of the rhs object.
bool Fixed::operator<(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue < rhs._fixedPointValue; 
}

// Greater than or equal to operator
// This function overloads the '>=' operator to compare two Fixed objects.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// The function returns true if the current object's fixed-point value is greater than or equal to that of the rhs object.
bool Fixed::operator>=(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue >= rhs._fixedPointValue; 
}

// Less than or equal to operator
// This function overloads the '<=' operator to compare two Fixed objects.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// The function returns true if the current object's fixed-point value is less than or equal to that of the rhs object.
bool Fixed::operator<=(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue <= rhs._fixedPointValue; 
}

// Equality operator
// This function overloads the '==' operator to check for equality between two Fixed objects.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// The function returns true if the current object's fixed-point value is equal to that of the rhs object.
bool Fixed::operator==(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue == rhs._fixedPointValue; 
}

// Inequality operator
// This function overloads the '!=' operator to check for inequality between two Fixed objects.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// The function returns true if the current object's fixed-point value is not equal to that of the rhs object.
bool Fixed::operator!=(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue != rhs._fixedPointValue; 
}

// Addition operator
// This function overloads the '+' operator to add two Fixed objects.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// The function returns a new Fixed object that represents the sum of the current object's value and the rhs object's value.
Fixed Fixed::operator+(const Fixed &rhs) const 
{ 
    return Fixed(this->toFloat() + rhs.toFloat()); 
}

// Subtraction operator
// This function overloads the '-' operator to subtract one Fixed object from another.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// The function returns a new Fixed object that represents the difference between the current object's value and the rhs object's value.
Fixed Fixed::operator-(const Fixed &rhs) const 
{ 
    return Fixed(this->toFloat() - rhs.toFloat()); 
}

// Multiplication operator
// This function overloads the '*' operator to multiply two Fixed objects.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// The function returns a new Fixed object that represents the product of the current object's value and the rhs object's value.
Fixed Fixed::operator*(const Fixed &rhs) const 
{ 
    return Fixed(this->toFloat() * rhs.toFloat()); 
}

// Division operator with error handling for division by zero
// This function overloads the '/' operator to divide one Fixed object by another.
// It takes a constant reference to another Fixed object (rhs) as a parameter.
// If the rhs object's fixed-point value is zero, it outputs an error message and returns a default Fixed object.
// Otherwise, it returns a new Fixed object that represents the quotient of the current object's value and the rhs object's value.
Fixed Fixed::operator/(const Fixed &rhs) const 
{
    if (rhs._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Pre-increment operator
// This function overloads the '++' operator for pre-incrementing the current Fixed object.
// It increments the current object's fixed-point value by 1 and returns a reference to the updated object.
Fixed &Fixed::operator++() 
{
    this->_fixedPointValue++;
    return *this;
}

// Post-increment operator
// This function overloads the '++' operator for post-incrementing the current Fixed object.
// It creates a temporary copy of the current object, increments the current object's value, and returns the temporary copy.
Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    operator++();
    return temp;
}

// Pre-decrement operator
// This function overloads the '--' operator for pre-decrementing the current Fixed object.
// It decrements the current object's fixed-point value by 1 and returns a reference to the updated object.
Fixed &Fixed::operator--() 
{
    this->_fixedPointValue--;
    return *this;
}

// Post-decrement operator
// This function overloads the '--' operator for post-decrementing the current Fixed object.
// It creates a temporary copy of the current object, decrements the current object's value, and returns the temporary copy.
Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    operator--();
    return temp;
}

// Returns the minimum of two Fixed objects (non-const)
// This function returns a reference to the smaller of two Fixed objects.
// It takes two non-const references to Fixed objects (a and b) as parameters.
// The function uses the less than operator to determine which object is smaller and returns it.
Fixed &Fixed::min(Fixed &a, Fixed &b) 
{ 
    return (a < b) ? a : b; 
}

// Returns the minimum of two Fixed objects (const)
// This function returns a reference to the smaller of two Fixed objects.
// It takes two constant references to Fixed objects (a and b) as parameters.
// The function uses the less than operator to determine which object is smaller and returns it.
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{ 
    return (a < b) ? a : b; 
}

// Returns the maximum of two Fixed objects (non-const)
// This function returns a reference to the larger of two Fixed objects.
// It takes two non-const references to Fixed objects (a and b) as parameters.
// The function uses the greater than operator to determine which object is larger and returns it.
Fixed &Fixed::max(Fixed &a, Fixed &b) 
{ 
    return (a > b) ? a : b; 
}

// Returns the maximum of two Fixed objects (const)
// This function returns a reference to the larger of two Fixed objects.
// It takes two constant references to Fixed objects (a and b) as parameters.
// The function uses the greater than operator to determine which object is larger and returns it.
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{ 
    return (a > b) ? a : b; 
}

// Overloaded output stream operator for Fixed objects
// This function overloads the '<<' operator to output the value of a Fixed object to an output stream.
// It takes a reference to an output stream (out) and a constant reference to a Fixed object (fixed) as parameters.
// The function converts the fixed-point value to a float and outputs it to the stream, then returns the stream.
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}