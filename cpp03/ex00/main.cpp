#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap clap("CL4P-TP");
    
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    return 0;
}