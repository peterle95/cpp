/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:16 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/11 22:07:17 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits) {}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed &src) { *this = src; }

Fixed &Fixed::operator=(const Fixed &rhs) 
{
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }

void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

float Fixed::toFloat(void) const 
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const { return this->_fixedPointValue >> _fractionalBits; }

bool Fixed::operator>(const Fixed &rhs) const { return this->_fixedPointValue > rhs._fixedPointValue; }
bool Fixed::operator<(const Fixed &rhs) const { return this->_fixedPointValue < rhs._fixedPointValue; }
bool Fixed::operator>=(const Fixed &rhs) const { return this->_fixedPointValue >= rhs._fixedPointValue; }
bool Fixed::operator<=(const Fixed &rhs) const { return this->_fixedPointValue <= rhs._fixedPointValue; }
bool Fixed::operator==(const Fixed &rhs) const { return this->_fixedPointValue == rhs._fixedPointValue; }
bool Fixed::operator!=(const Fixed &rhs) const { return this->_fixedPointValue != rhs._fixedPointValue; }

Fixed Fixed::operator+(const Fixed &rhs) const { return Fixed(this->toFloat() + rhs.toFloat()); }
Fixed Fixed::operator-(const Fixed &rhs) const { return Fixed(this->toFloat() - rhs.toFloat()); }
Fixed Fixed::operator*(const Fixed &rhs) const { return Fixed(this->toFloat() * rhs.toFloat()); }
Fixed Fixed::operator/(const Fixed &rhs) const 
{
    if (rhs._fixedPointValue == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() 
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) 
{
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed &Fixed::operator--() 
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) 
{
    Fixed temp(*this);
    operator--();
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}