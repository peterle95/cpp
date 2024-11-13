/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:05:46 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/13 17:22:48 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed(); // Default constructor
    Fixed(const int n); // Constructor that takes an integer
    Fixed(const float n); // Constructor that takes a float
    Fixed(const Fixed &src); // Copy constructor    
    Fixed &operator=(const Fixed &rhs); // Assignment operator
    ~Fixed(); // Destructor

    int getRawBits(void) const;  // Getter for the raw fixed-point value
    void setRawBits(int const raw); // Setter for the raw fixed-point value
    float toFloat(void) const; // Convert to float
    int toInt(void) const; // Convert to int
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif