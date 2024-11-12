/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:04:03 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 08:53:42 by pmolzer          ###   ########.fr       */
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
    /* This constructor initializes a Fixed object with a default value. */

    Fixed(const Fixed &src);
    /* This constructor creates a new Fixed object as a copy of an existing one.
       The parameter 'src' is a reference to another Fixed object from which
       the new object will copy its value. Using 'const' here indicates that
       the 'src' object will not be modified by this constructor, ensuring
       that the original object remains unchanged. This promotes safety and
       clarity in the code, as it signals to the user that the function
       will not alter the input object. The syntax 'const Fixed &src' means
       that 'src' is a reference to a constant Fixed object, allowing for
       efficient copying without the overhead of creating a copy of the object. */

    Fixed &operator=(const Fixed &rhs);
    /* This operator allows one Fixed object to be assigned the value of another.
       The parameter 'rhs' is a reference to the Fixed object being assigned from.
       Similar to the copy constructor, 'const' ensures that 'rhs' will not be
       modified during the assignment process. The syntax 'Fixed &operator='
       indicates that this function returns a reference to the current object,
       allowing for chained assignments (e.g., a = b = c). This operator first
       checks for self-assignment and then copies the value from 'rhs' to the
       current object, ensuring that the assignment is done correctly. */

    ~Fixed();
    /* This destructor cleans up when a Fixed object goes out of scope. */

    int getRawBits(void) const;
    /* This function returns the raw value of the fixed-point number. */

    void setRawBits(int const raw);
    /* This function sets the raw value of the fixed-point number. */
};

#endif