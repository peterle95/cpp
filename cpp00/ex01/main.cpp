/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:57:55 by pmolzer           #+#    #+#             */
/*   Updated: 2024/09/06 20:57:57 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook book;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "EXIT") {
            break;
        } else if (command == "ADD") {
            book.addContact();
        } else if (command == "SEARCH") {
            book.searchContact();
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}