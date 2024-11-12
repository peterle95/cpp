/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:06:35 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/11 22:06:36 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

/* TASK OF THE PROGRAM:
Do you know Harl? We all do, do we? In case you don’t, find below the kind of
comments Harl makes. They are classified by levels:
• "DEBUG" level: Debug messages contain contextual information. They are mostly
used for problem diagnosis.
Example: "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special￾ketchup burger. I really do!"
• "INFO" level: These messages contain extensive information. They are helpful for
tracing program execution in a production environment.
Example: "I cannot believe adding extra bacon costs more money. You didn’t put
enough bacon in my burger! If you did, I wouldn’t be asking for more!"
• "WARNING" level: Warning messages indicate a potential issue in the system.
However, it can be handled or ignored.
Example: "I think I deserve to have some extra bacon for free. I’ve been coming for
years whereas you started working here since last month."
• "ERROR" level: These messages indicate an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention.
Example: "This is unacceptable! I want to speak to the manager now.
You are going to automate Harl. It won’t be difficult since it always says the same
things. You have to create a Harl class with the following private member functions:
• void debug( void );
• void info( void );
• void warning( void );
• void error( void );
Harl also has a public member function that calls the four member functions above
depending on the level passed as parameter:
void complain( std::string level );
The goal of this exercise is to use pointers to member functions. This is not a
suggestion. Harl has to complain without using a forest of if/else if/else. It doesn’t think
twice!
Create and turn in tests to show that Harl complains a lot. You can use the examples
of comments listed above in the subject or choose to use comments of your own."*/

int main() 
{
    Harl harl;

    std::cout << "Harl complains at DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "Harl complains at INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "Harl complains at WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "Harl complains at ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "Harl tries to complain at an invalid level:" << std::endl;
    harl.complain("INVALID");

    return 0;
}