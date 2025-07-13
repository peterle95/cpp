/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:32:26 by pmolzer           #+#    #+#             */
/*   Updated: 2025/07/13 12:55:18 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() 
{}

Serializer::Serializer(const Serializer& other) 
{ (void)other; }

Serializer& Serializer::operator=(const Serializer& other) 
{ (void)other; return *this; }

Serializer::~Serializer() 
{}

// Convert Data pointer to uintptr_t
uintptr_t Serializer::serialize(Data* ptr) 
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// Convert uintptr_t back to Data pointer
Data* Serializer::deserialize(uintptr_t raw) 
{
    return reinterpret_cast<Data*>(raw);
}