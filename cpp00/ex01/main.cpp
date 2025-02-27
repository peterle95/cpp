/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:57:55 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/08 12:58:13 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() 
{
    PhoneBook book;
    std::string command;

    while (true) 
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> command;
        if (command == "ADD") 
            book.addContact();
        else if (command == "SEARCH") 
            book.searchContact();
        else if (command == "EXIT") 
            break;
        else 
            std::cout << "Invalid command" << std::endl;
    }
    return 0;
}
