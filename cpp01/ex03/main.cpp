/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmolzer <pmolzer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:46:58 by pmolzer           #+#    #+#             */
/*   Updated: 2024/11/10 11:56:51 by pmolzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*TASK OF THE EXERCISE:
Implement a Weapon class that has:
• A private attribute type, which is a string.
• A getType() member function that returns a const reference to type.
• A setType() member function that sets type using the new one passed as parameter.
Now, create two classes: HumanA and HumanB. They both have a Weapon and a
name. They also have a member function attack() that displays (of course, without the
angle brackets):
<name> attacks with their <weapon type>
HumanA and HumanB are almost the same except for these two tiny details:
• While HumanA takes the Weapon in its constructor, HumanB doesn’t.
• HumanB may not always have a Weapon, whereas HumanA will always be armed.
*/

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/** 
 * The main function serves as the entry point of the program, demonstrating the functionality 
 * of HumanA and HumanB classes with a Weapon. It shows how both types of humans can attack 
 * using a weapon and how the weapon type can be changed.
 */
int main() 
{
    {
        // Create a Weapon object named 'club' with the type "crude spiked club".
        Weapon club = Weapon("crude spiked club"); /** Initialize a Weapon object with a specific type. */
        
        // Create a HumanA object named 'bob', initialized with the name "Kevin" and the 'club' weapon.
        HumanA bob("Kevin", club); /** Instantiate a HumanA object with a name and a weapon reference. */
        
        // Call the attack method on 'bob', which will display the attack message.
        bob.attack(); /** Execute the attack method to show how 'bob' uses the weapon. */
        
        // Change the type of the 'club' weapon to "some other type of club".
        club.setType("some other type of club"); /** Update the weapon's type to a new string value. */
        
        // Call the attack method on 'bob' again to show the updated weapon type in the attack message.
        bob.attack(); /** Execute the attack method again to reflect the change in weapon type. */
    }
    {
        // Create another Weapon object named 'club' with the type "crude spiked club".
        Weapon club = Weapon("crude spiked club"); /** Initialize a second Weapon object with the same type. */
        
        // Create a HumanB object named 'jim', initialized with the name "Jim". Initially, 'jim' has no weapon.
        HumanB jim("Jim"); /** Instantiate a HumanB object with a name, without an initial weapon. */
        
        // Set the 'club' weapon for 'jim' using the setWeapon method.
        jim.setWeapon(club); /** Assign the previously created weapon to 'jim' using a setter method. */

        // Call the attack method on 'jim', which will display the attack message with the current weapon type or indicate no weapon.
        jim.attack(); /** Execute the attack method to show how 'jim' uses the weapon or indicate no weapon. */
        
        // Change the type of the 'club' weapon to "some other type of club".
        club.setType("some other type of club"); /** Update the weapon's type to a new string value. */
        
        // Call the attack method on 'jim' again to show the updated weapon type in the attack message.
        jim.attack(); /** Execute the attack method again to reflect the change in weapon type. */
    }
    // The two sets of curly braces {} create separate scopes. 
    // This ensures that the Weapon objects created within each scope are destroyed 
    // when the scope ends, preventing potential memory issues and allowing for 
    // the same variable name 'club' to be reused in the second scope without conflict.
    return 0;
}