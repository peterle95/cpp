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