/* This class implements a complaint management system called Harl.
 * It demonstrates the use of pointers to member functions in C++.
 * The class works in conjunction with Harl.cpp which contains the implementations
 * and main.cpp which demonstrates the usage of this class.
 * The program simulates different levels of complaints (debug, info, warning, error)
 * without using traditional if/else statements, instead utilizing an array of
 * function pointers for better code organization and maintainability.
 */

#ifndef HARL_HPP    /* Header guard to prevent multiple inclusions */
#define HARL_HPP    /* Define the header guard */

#include <string>   /* Include string library for std::string usage */

class Harl {        /* Define the Harl class */
private:
    /* Private member functions that implement different levels of complaints.
     * These functions are called through function pointers in the complain method */
    void debug();   /* Handles debug level complaints about bacon in burgers */
    void info();    /* Handles info level complaints about bacon pricing */
    void warning(); /* Handles warning level complaints about customer loyalty */
    void error();   /* Handles error level complaints demanding manager attention */

public:
    /* Public interface to trigger complaints based on specified level.
     * This function uses pointers to member functions to call the appropriate
     * private member function based on the input level string */
    void complain(std::string level);
};

#endif

/*Yes, the project follows the requirements outlined in the exercise. Here's how it aligns with the specified criteria:

1. **Function Execution via Pointers**: The `complain()` function in the `Harl` class successfully executes the other member functions (`debug()`, `info()`, `warning()`, and `error()`) using pointers to member functions. This is done through an array of function pointers, which is a key requirement of the exercise.

2. **Matching Strings to Function Pointers**: The implementation uses an array of strings (`levels`) that correspond to the complaint levels. The `complain()` function iterates through this array to find a match with the input string (`level`). When a match is found, it calls the corresponding member function using the pointer syntax. This approach effectively meets the requirement of matching strings to function pointers without using `if/else` statements.

3. **Flexibility in Messages**: The student has the option to change the messages displayed by the `Harl` class. The current implementation uses predefined messages, but the exercise allows for customization, which is valid as long as the functionality remains intact.

4. **No Use of Conditional Statements**: The implementation adheres to the restriction of not using `if/else/elif` statements for determining which function to call. Instead, it relies on the array of function pointers and the corresponding string array to achieve the desired behavior.

Overall, the implementation is valid and meets the exercise's requirements effectively.
*/