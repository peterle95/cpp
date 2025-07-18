#include <iostream>
#include <string>
#include "whatever.hpp"


/*TASK:
Implement the following function templates:
• swap: Swaps the values of two given parameters. Does not return anything.
• min: Compares the two values passed as parameters and returns the smallest one.
If they are equal, it returns the second one.
• max: Compares the two values passed as parameters and returns the greatest one.
If they are equal, it returns the second one.
These functions can be called with any type of argument. The only requirement is
that the two arguments must have the same type and must support all the comparison
operators.
Templates must be defined in the header files.
Running the following code:
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}
Should output:
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
*/

int main(void) {
    int a = 2;
    int b = 3;
    
    // std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    
    // The :: operator here is the global scope resolution operator
    // It explicitly tells the compiler to use the global swap function
    // (the one we defined in whatever.hpp) rather than std::swap
    ::swap(a, b);
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    
    // Again, :: means "use the global scope version"
    // When the compiler sees ::min(a, b), it looks for a function
    // named 'min' in the global namespace that can handle two int arguments
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    
    // The template system automatically deduces that T = int
    // because both arguments are integers
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    // std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    
    // ere, the compiler deduces that T = std::string
    // and creates a version of swap that works with strings
    ::swap(c, d);
    
    std::cout << "c = " << c << ", d = " << d << std::endl;
    
    // Template instantiation happens automatically:
    // The compiler creates min<std::string> and max<std::string>
    // versions of these functions behind the scenes
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    
    return 0;
}