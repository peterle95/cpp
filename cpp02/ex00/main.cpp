/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:03:49 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/12 09:25:57 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Include the iostream library for input and output operations
#include "Fixed.hpp" // Include the Fixed class header file

/*TASK OF THE PROGRAM:
Create a class in Orthodox Canonical Form that represents a fixed-point number:
•Private members:
◦An integer to store the fixed-point number value.
◦A static constant integer to store the number of fractional bits. Its value
will always be the integer literal 8.
•Public members:
◦A default constructor that initializes the fixed-point number value to 0.
◦A copy constructor.
◦A copy assignment operator overload.
◦A destructor.
◦A member function int getRawBits( void ) const;
that returns the raw value of the fixed-point value.
◦A member function void setRawBits( int const raw );
that sets the raw value of the fixed-point number.
Running this code:
#include <iostream>
int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}
Should output something similar to:
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
*/


/* 
This program demonstrates the usage of the Fixed class, which represents a 
fixed-point number. It creates instances of the Fixed class, showcasing 
the default constructor, copy constructor, and copy assignment operator. 
The program outputs the raw values of the fixed-point numbers to the console.
*/
int main(void) // Main function where the program execution starts
{
    Fixed a; // Create an instance of Fixed using the default constructor
    /* This calls the default constructor of the Fixed class, which initializes 
    _fixedPointValue to 0 and prints "Default constructor called". */

    Fixed b(a); // Create an instance of Fixed using the copy constructor
    /* This calls the copy constructor of the Fixed class, which copies the 
    value of 'a' into 'b' and prints "Copy constructor called". */

    Fixed c; // Create another instance of Fixed using the default constructor
    /* This again calls the default constructor, initializing _fixedPointValue 
    to 0 for 'c' and printing "Default constructor called". */

    c = b; // Assign the value of 'b' to 'c' using the copy assignment operator
    /* This calls the copy assignment operator, which checks for self-assignment 
    and copies the value from 'b' to 'c', printing "Copy assignment operator called". */

    /* 
    How the Program Knows Which Constructor to Call:
    When an object is created, the C++ compiler determines which constructor to call 
    based on the parameters provided during the object instantiation. 
    - If no parameters are provided (e.g., `Fixed a;`), the default constructor is called.
    - If an object is created using another object as a parameter (e.g., `Fixed b(a);`), 
    the copy constructor is invoked. 
    This mechanism allows for the appropriate constructor to be selected based on the context 
    of the object creation, ensuring that the correct initialization logic is applied.
    */

    std::cout << a.getRawBits() << std::endl; // Output the raw value of 'a'
    /* This calls the getRawBits() member function, which prints 
    "getRawBits member function called" and returns the value of _fixedPointValue, which is 0. */

    std::cout << b.getRawBits() << std::endl; // Output the raw value of 'b'
    /* Similar to the previous line, this calls getRawBits() for 'b', 
    printing the same message and returning 0. */

    std::cout << c.getRawBits() << std::endl; // Output the raw value of 'c'
    /* This calls getRawBits() for 'c', again printing the message and returning 0. */

    return 0; // End of the main function
    /* The program returns 0, indicating successful execution. */
}

/* 
Relation to Other Code in the Project:
This file, main.cpp, serves as the entry point for the program and demonstrates 
the functionality of the Fixed class defined in Fixed.hpp and implemented in 
Fixed.cpp. Line 67, specifically, creates an instance of the Fixed class 
using the copy constructor, which is crucial for understanding how objects 
are copied in C++. This showcases the behavior of the Fixed class when 
an object is initialized with another object, allowing you to see how 
the internal state (_fixedPointValue) is managed through constructors 
and assignment operators.
*/