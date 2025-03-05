### Technical Evaluation Questions: Inheritance & Polymorphism (C++98)

1. **Q: What's the difference between function hiding and polymorphism in this implementation?**  
   **A:** Current behavior shows function hiding:
   ```cpp
   // Base class
   void attack(); // Non-virtual
   
   // Derived class
   void attack(); // Hides ClapTrap::attack
   ```
   True polymorphism would require:
   ```cpp
   virtual void attack(); // In base class
   virtual void attack(); // In derived class (override)
   ```

2. **Q: Demonstrate the difference in method resolution with/without virtual**  
   **A:** Without virtual (current code):
   ```cpp
   ScavTrap scav("S1");
   ClapTrap* ptr = &scav;
   
   scav.attack();  // Calls ScavTrap::attack
   ptr->attack();  // Calls ClapTrap::attack (static binding)
   ```
   With virtual:
   ```cpp
   ptr->attack(); // Calls ScavTrap::attack (dynamic binding)
   ```

3. **Q: How does memory layout differ between hidden and overridden methods?**  
   **A:** Without virtual:
   - No vtable created
   - Function calls resolved at compile-time
   With virtual:
   - Each class gets vtable
   - Objects contain vptr (4/8 bytes overhead)
   ```text
   Memory layout with virtual:
   [vptr][ClapTrap members] → [vptr][ScavTrap members]
   ```

4. **Q: Why can't we achieve runtime polymorphism without virtual in C++98?**  
   **A:** C++98 uses early binding by default. Virtual enables late binding through:
   - vtable mechanism
   - Runtime type information (RTTI)
   - Dynamic dispatch via vptr

5. **Q: What's object slicing and how does virtual prevent it?**  
   **A:** Example of slicing:
   ```cpp
   ScavTrap scav("Scav");
   ClapTrap trap = scav; // Slicing occurs
   trap.attack(); // Always ClapTrap::attack
   ```
   Virtual prevents slicing when using:
   ```cpp
   ClapTrap& ref = scav; // No slicing
   ref.attack(); // Would call ScavTrap::attack if virtual
   ```

6. **Q: How to modify the code to demonstrate both behaviors?**  
   **A:** Test case showing difference:
   ```cpp
   void testAttack(ClapTrap& ct) {
       ct.attack(); // Calls ClapTrap::attack without virtual
   }
   
   ScavTrap scav("Test");
   testAttack(scav); // Behavior depends on virtual keyword
   ```

7. **Q: What's the performance implication of adding virtual?**  
   **A:** Tradeoffs:
   - +15% function call overhead (vtable lookup)
   + Enables polymorphic behavior
   + Allows interface abstraction
   ```cpp
   // Without virtual: 3 direct calls = 3ns
   // With virtual: 3 vtable lookups = 5ns (example)
   ```