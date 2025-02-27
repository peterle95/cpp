/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:59:52 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/08 12:59:53 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP 
#define PHONEBOOK_HPP 

#include "Contact.hpp"

class PhoneBook 
{ 
private:
    Contact contacts[8];
    int count;
    int oldest;

public:
    PhoneBook(); 
    void addContact();
    void searchContact();
}; 

#endif 
