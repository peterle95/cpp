/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:07:48 by pmolzer           #+#    #+#             */
/*   Updated: 2025/02/18 09:58:45 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    /* Fixed c( Fixed(1)/ Fixed(0));
    Fixed d( Fixed(22.3f) / Fixed(3));
    Fixed e(10);
    Fixed f(5);
    Fixed g(5.5f);
    Fixed h(5.5f); */

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    /* std::cout << e << " > " << f << " = " << (e > f) << std::endl;
    std::cout << e << " < " << f << " = " << (e < f) << std::endl;
    std::cout << g << " == " << h << " = " << (g == h) << std::endl;
    std::cout << e << " != " << f << " = " << (e != f) << std::endl;
    std::cout << e << " >= " << f << " = " << (e >= f) << std::endl;
    std::cout << f << " <= " << e << " = " << (f <= e) << std::endl;

    std::cout << e << " + " << f << " = " << e + f << std::endl;
    std::cout << e << " - " << f << " = " << e - f << std::endl;
    std::cout << e << " * " << f << " = " << e * f << std::endl;
    std::cout << e << " / " << f << " = " << e / f << std::endl;
    std::cout << "Division by zero: " << c << std::endl; */

    std::cout << b << std::endl;
    /* std::cout << c << std::endl;
    std::cout << d << std::endl; */

    std::cout << Fixed::max( a, b ) << std::endl;

   std::cout << "Max(" << a << ", " << b << ") = " << Fixed::max(a, b) << std::endl;
    std::cout << "Min(" << a << ", " << b << ") = " << Fixed::min(a, b) << std::endl;
    std::cout << "Const Min(" << 1.2f << ", " << 2.5f << ") = "
              << Fixed::min(Fixed(1.2f), Fixed(2.5f)) << std::endl;
    std::cout << "Const Max(" << 4.2f << ", " << 4.3f << ") = " 
              << Fixed::max(Fixed(4.2f), Fixed(4.3f)) << std::endl;

    return 0;
}