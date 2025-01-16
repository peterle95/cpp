/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:16 by pmolzer           #+#    #+#             */
/*   Updated: 2025/01/16 12:00:01 by pmolzer          ###   ########.fr       */
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
bool Fixed::operator>(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue > rhs._fixedPointValue; 
}

// Less than operator
bool Fixed::operator<(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue < rhs._fixedPointValue; 
}

// Greater than or equal to operator
bool Fixed::operator>=(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue >= rhs._fixedPointValue; 
}

// Less than or equal to operator
bool Fixed::operator<=(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue <= rhs._fixedPointValue; 
}

// Equality operator
bool Fixed::operator==(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue == rhs._fixedPointValue; 
}

// Inequality operator
bool Fixed::operator!=(const Fixed &rhs) const 
{ 
    return this->_fixedPointValue != rhs._fixedPointValue; 
}

// Addition operator
Fixed Fixed::operator+(const Fixed &rhs) const 
{ 
    return Fixed(this->toFloat() + rhs.toFloat()); 
}

// Subtraction operator
Fixed Fixed::operator-(const Fixed &rhs) const 
{ 
    return Fixed(this->toFloat() - rhs.toFloat()); 
}

// Multiplication operator
Fixed Fixed::operator*(const Fixed &rhs) const 
{ 
    return Fixed(this->toFloat() * rhs.toFloat()); 
}

// Division operator with error handling for division by zero
Fixed Fixed::operator/(const Fixed &rhs) const 
{
    if (rhs._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Pre-increment operator
Fixed &Fixed::operator++() 
{
    this->_fixedPointValue++;
    return *this;
}

// Post-increment operator
Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    operator++();
    return temp;
}

// Pre-decrement operator
Fixed &Fixed::operator--() 
{
    this->_fixedPointValue--;
    return *this;
}

// Post-decrement operator
Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    operator--();
    return temp;
}

// Returns the minimum of two Fixed objects (non-const)
Fixed &Fixed::min(Fixed &a, Fixed &b) 
{ 
    return (a < b) ? a : b; 
}

// Returns the minimum of two Fixed objects (const)
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{ 
    return (a < b) ? a : b; 
}

// Returns the maximum of two Fixed objects (non-const)
Fixed &Fixed::max(Fixed &a, Fixed &b) 
{ 
    return (a > b) ? a : b; 
}

// Returns the maximum of two Fixed objects (const)
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{ 
    return (a > b) ? a : b; 
}

// Overloaded output stream operator for Fixed objects
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}