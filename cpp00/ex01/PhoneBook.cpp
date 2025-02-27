/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:55:34 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/08 12:56:02 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), oldest(0) {}

void PhoneBook::addContact() 
{
    std::string first, last, nick, phone, secret;
    
    std::cout << "Enter first name: ";
    std::cin >> first;
    std::cout << "Enter last name: ";
    std::cin >> last;
    std::cout << "Enter nickname: ";
    std::cin >> nick;
    std::cout << "Enter phone number: ";
    std::cin >> phone;
    std::cout << "Enter darkest secret: ";
    std::cin >> secret;

    contacts[oldest].setContact(first, last, nick, phone, secret);
    oldest = (oldest + 1) % 8;
    if (count < 8) 
        count++;
}

void PhoneBook::searchContact() 
{
    if (count == 0) 
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    for (int i = 0; i < count; i++) 
    {
        contacts[i].displayShort(i);
    }
    int index;
    std::cout << "Enter index to display: ";
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= count) 
    {
        std::cout << "Invalid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    contacts[index].displayFull();
}
