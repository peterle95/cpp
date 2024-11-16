/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:21 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/15 13:38:50 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * This header file defines the Fixed class, which represents fixed-point 
 * numbers. Fixed-point representation is useful for applications that 
 * require precise decimal representation without the overhead of floating-point 
 * arithmetic. This class provides various functionalities such as 
 * constructors, operator overloads, and conversion methods.
 */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> /* Include the iostream library for input and output operations */

class Fixed /* Define the Fixed class */
{
private:
    int _fixedPointValue; /* Store the fixed-point value as an integer */
    static const int _fractionalBits = 8; /* Define the number of bits for the fractional part */

public:
    Fixed(); /* Default constructor */
    Fixed(const int n); /* Constructor that initializes from an integer */
    Fixed(const float n); /* Constructor that initializes from a float */
    Fixed(const Fixed &src); /* Copy constructor */
    Fixed &operator=(const Fixed &rhs); /* Assignment operator */
    ~Fixed(); /* Destructor */

    int getRawBits(void) const; /* Get the raw fixed-point value */
    void setRawBits(int const raw); /* Set the raw fixed-point value */
    float toFloat(void) const; /* Convert the fixed-point value to a float */
    int toInt(void) const; /* Convert the fixed-point value to an integer */

    // Comparison operators
    bool operator>(const Fixed &rhs) const; /* Greater than operator */
    bool operator<(const Fixed &rhs) const; /* Less than operator */
    bool operator>=(const Fixed &rhs) const; /* Greater than or equal to operator */
    bool operator<=(const Fixed &rhs) const; /* Less than or equal to operator */
    bool operator==(const Fixed &rhs) const; /* Equality operator */
    bool operator!=(const Fixed &rhs) const; /* Inequality operator */

    // Arithmetic operators
    Fixed operator+(const Fixed &rhs) const; /* Addition operator */
    Fixed operator-(const Fixed &rhs) const; /* Subtraction operator */
    Fixed operator*(const Fixed &rhs) const; /* Multiplication operator */
    Fixed operator/(const Fixed &rhs) const; /* Division operator */

    // Increment/Decrement operators
    Fixed &operator++(); /* Pre-increment operator */
    Fixed operator++(int); /* Post-increment operator */
    Fixed &operator--(); /* Pre-decrement operator */
    Fixed operator--(int); /* Post-decrement operator */

    // Static member functions
    static Fixed &min(Fixed &a, Fixed &b); /* Return the minimum of two Fixed objects */
    static const Fixed &min(const Fixed &a, const Fixed &b); /* Return the minimum of two const Fixed objects */
    static Fixed &max(Fixed &a, Fixed &b); /* Return the maximum of two Fixed objects */
    static const Fixed &max(const Fixed &a, const Fixed &b); /* Return the maximum of two const Fixed objects */
};

/* Overload the output stream operator to print Fixed objects */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */

/* 
 * This header file is part of a larger project that implements fixed-point 
 * arithmetic. The Fixed class is used in conjunction with other files, 
 * such as Fixed.cpp, which contains the implementation of the methods 
 * declared here, and main.cpp, which demonstrates the usage of the Fixed 
 * class through various operations and outputs.
 */