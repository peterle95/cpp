### Technical Evaluation Q&A (ex02 Focus)

1. **Q: Explain the constructor/destructor chain when creating a FragTrap object**  
   **A:** The instantiation order is:
   ```cpp
   ClapTrap() → FragTrap()
   ```
   Destruction reverses this:
   ```cpp
   ~FragTrap() → ~ClapTrap()
   ```
   This ensures proper base class initialization before derived specifics.

2. **Q: How does FragTrap's attack implementation differ from ScavTrap's?**  
   **A:** The key differences are:
   ```cpp
   // ScavTrap attack (typical implementation)
   void attack(const std::string& target) {
       if (energyPoints > 0) {
           energyPoints--;
           std::cout << "ScavTrap " << name << " attacks..." << std::endl;
       }
   }
   
   // FragTrap attack (actual implementation)
   void attack(const std::string& target) {
       if (energyPoints > 0 && hitPoints > 0) {  // Extra hitPoints check
           std::cout << "FragTrap " << name << " attacks..." << std::endl;
           energyPoints--;  // Same energy consumption
       } else {
           std::cout << "Can't attack - low energy/hp" << std::endl;
       }
   }
   ```
   Main differences:
   - Additional hitPoints viability check
   - Different failure message
   - Same energy consumption (1 EP per attack)

3. **Q: What happens if FragTrap::highFivesGuys() is called with 0 hit points?**  
   **A:** The method should first check viability:
   ```cpp
   void highFivesGuys() {
       if (hitPoints <= 0) {
           std::cout << "FragTrap is dead!" << std::endl;
           return;
       }
       // ... high-five logic ...
   }
   ```
   Dead objects can't initiate actions - critical state validation.

4. **Q: Why does FragTrap have different energyPoints (100) vs ScavTrap (50)?**  
   **A:** Implementation-specific balance:
   ```cpp
   // FragTrap constructor
   FragTrap::FragTrap() : ClapTrap("FragDefault") {
       hitPoints = 100;
       energyPoints = 100;  // Sustained ability usage
       attackDamage = 30;
   }
   ```
   Design choice for varied gameplay roles - attacker vs defender.

5. **Q: How would you detect a double-free in the inheritance hierarchy?**  
   **A:** Valgrind analysis pattern:
   ```text
   ==PID== Invalid free() / delete / delete[]
   ==PID==    by ClapTrap::~ClapTrap() (ClapTrap.cpp:XX)
   ==PID==    by FragTrap::~FragTrap() (FragTrap.cpp:YY)
   ```
   Indicates destructor chain issues - virtual destructors might be needed.

6. **Q: Explain the vtable implications of adding showStats() to FragTrap**  
   **A:** Non-virtual method addition:
   ```cpp
   class FragTrap : public ClapTrap {
   public:
       void showStats() const;  // New in vtable
   };
   ```
   Expands FragTrap's vtable by 1 entry, but doesn't affect ClapTrap's layout.

7. **Q: What would happen if attackDamage wasn't protected in ClapTrap?**  
   **A:** Derived classes would need accessors:
   ```cpp
   // If private in ClapTrap:
   void FragTrap::attack() {
       setAttackDamage(30);  // Requires setter method
       // vs direct access when protected
   }
   ```
   Protection level dictates coupling between base and derived classes.

8. **Q: How does showStats() help prevent memory leaks?**  
   **A:** Debugging visibility:
   ```cpp
   void showStats() const {
       std::cout << "HP: " << hitPoints 
                 << " EP: " << energyPoints
                 << " AD: " << attackDamage << std::endl;
   }
   ```
   Reveals invalid values early (negative EP, overflow HP) indicating corruption.

9. **Q: Why can't we static_cast<ClapTrap*> a FragTrap* for method calls?**  
   **A:** Object slicing prevention:
   ```cpp
   FragTrap frag;
   ClapTrap* clap = static_cast<ClapTrap*>(&frag);
   clap->attack();  // Calls ClapTrap::attack() not FragTrap's version
   ```
   Requires virtual functions for polymorphic behavior.

10. **Q: What would happen if we called takeDamage(1000) on a FragTrap?**  
    **A:** Boundary handling:
    ```cpp
    void takeDamage(unsigned int amount) {
        hitPoints = (amount >= hitPoints) ? 0 : hitPoints - amount;
        // Prevents underflow, maintains 0 floor
    }
    ```
    Critical for preventing invalid health states in combat simulations.