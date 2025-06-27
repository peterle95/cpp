/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 00:00:00 by pmolzer           #+#    #+#             */
/*   Updated: 2025/06/27 16:29:05 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

/*
 * FACTORY PATTERN IMPLEMENTATION
 * 
 * The Intern class implements the Factory Design Pattern, which provides
 * an interface for creating objects without specifying their exact class.
 * 
 * Key Factory Pattern Elements:
 * 1. Factory Class: Intern (this class)
 * 2. Product Interface: AForm (abstract base class)
 * 3. Concrete Products: ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm
 * 4. Factory Method: makeForm() - creates objects based on string input
 * 
 * Benefits:
 * - Encapsulates object creation logic
 * - Allows runtime object creation based on parameters
 * - Promotes loose coupling between client code and concrete classes
 * - Makes adding new form types easier (just add new creation method)
 */
class Intern
{
public:
    // Orthodox Canonical Form constructors/destructor
    Intern();                                    // Default constructor
    Intern(const Intern& other);                // Copy constructor
    ~Intern();                                  // Destructor
    Intern& operator=(const Intern& other);     // Assignment operator

    /*
     * MAIN FACTORY METHOD
     * 
     * This is the core of the Factory pattern. It takes a form name as string
     * and returns a pointer to the appropriate AForm-derived object.
     * 
     * Parameters:
     *   formName - String identifier for the type of form to create
     *   target   - Target parameter passed to the form constructor
     * 
     * Returns:
     *   AForm* - Pointer to newly created form object, or NULL if invalid name
     * 
     * This method demonstrates the Factory pattern by:
     * - Hiding the complexity of object creation from the client
     * - Using a uniform interface (string) to create different object types
     * - Centralizing creation logic in one place
     */
    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    /*
     * PRIVATE FACTORY HELPER METHODS
     * 
     * These methods implement the actual object creation for each form type.
     * They are private because they're implementation details of the factory.
     * 
     * Each method:
     * - Creates a specific type of form
     * - Returns it as AForm* (polymorphic return type)
     * - Is called via function pointer from makeForm()
     * 
     * This design allows for easy extension - to add a new form type,
     * you would:
     * 1. Add a new makeXXXForm() method here
     * 2. Add it to the arrays in makeForm() implementation
     */
    AForm* makeShrubberyCreationForm(const std::string& target);    // Creates ShrubberyCreationForm
    AForm* makeRobotomyRequestForm(const std::string& target);      // Creates RobotomyRequestForm
    AForm* makePresidentialPardonForm(const std::string& target);   // Creates PresidentialPardonForm
};

/*
 * FACTORY PATTERN EVIDENCE IN THE IMPLEMENTATION:
 * 
 * Looking at Intern.cpp, you can see the Factory pattern in action:
 * 
 * 1. String-to-Function Mapping:
 *    - Array of form names: ["shrubbery creation", "robotomy request", "presidential pardon"]
 *    - Array of function pointers: [&Intern::makeShrubberyCreationForm, ...]
 * 
 * 2. Runtime Object Creation:
 *    - Client calls makeForm("robotomy request", "target")
 *    - Factory searches for matching string
 *    - Calls appropriate creation method via function pointer
 *    - Returns polymorphic AForm* pointing to concrete object
 * 
 * 3. Encapsulation:
 *    - Client doesn't need to know about concrete classes
 *    - Client doesn't need to handle object creation complexity
 *    - All creation logic is centralized in the factory
 * 
 * 4. Polymorphism:
 *    - All creation methods return AForm*
 *    - Client can work with returned objects through base class interface
 *    - Actual object type is determined at runtime
 */

#endif