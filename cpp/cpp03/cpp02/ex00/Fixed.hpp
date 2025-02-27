/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:04:03 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/07 15:54:25 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed 
{
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif