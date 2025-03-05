### Overview

This simulation demonstrates C++98 inheritance mechanics through `ClapTrap` (base) and `ScavTrap` (derived) classes. Key implementation details:

```cpp:cpp03/ex01/ClapTrap.hpp
// Protected members enable direct access in derived classes
class ClapTrap {
protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints; 
    unsigned int attackDamage;
public:
    ClapTrap(std::string name);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
```

```cpp:cpp03/ex01/ScavTrap.hpp
// Public inheritance with method hiding
class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    void attack(const std::string& target); // Hides ClapTrap::attack
    void guardGate();
};
```

### Key Technical Implementation Details

1. **Construction/Destruction Order**:
```cpp:cpp03/ex01/main.cpp
ClapTrap *ptr = new ScavTrap("Test");
// Output:
// ClapTrap Test is created!
// ScavTrap Test is created!
delete ptr; 
// Output:
// ScavTrap Test is destroyed!
// ClapTrap Test is destroyed!
```

2. **Attribute Initialization**:
```cpp:cpp03/ex01/ScavTrap.cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;    // Direct access to protected members
    energyPoints = 50;
    attackDamage = 20;
}
```

3. **Function Hiding Mechanism**:
```cpp:cpp03/ex01/main.cpp
ScavTrap scav("S1");
ClapTrap* base = &scav;

scav.attack("A");  // Calls ScavTrap::attack
base->attack("B"); // Calls ClapTrap::attack (no virtual)
```

### Critical Technical Considerations

1. **Memory Layout**:
```
ClapTrap Instance: [name][hitPoints][energyPoints][attackDamage]
ScavTrap Instance: [ClapTrap members][no additional members]
Size: Both 28 bytes (assuming 4-byte ints and 16-byte string)
```

2. **Method Resolution Table**:
```
Without virtual:
ClapTrap: attack@0x1000
ScavTrap: attack@0x2000, guardGate@0x3000

With virtual (hypothetical):
VTable ClapTrap: [~ClapTrap][attack]
VTable ScavTrap: [~ScavTrap][attack_override]
```

3. **Destruction Chain**:
```
delete ptr:
1. ScavTrap destructor (explicit)
2. ClapTrap destructor (implicit base cleanup)
```

### Evaluation Focus Points

1. **Construction Validation**:
```cpp
ScavTrap scav("SC4V");
// Verify initialization:
assert(scav.hitPoints == 100);
assert(scav.energyPoints == 50); 
assert(scav.attackDamage == 20);
```

2. **Energy Point Management**:
```cpp
ClapTrap clap("CL4P");
for (int i = 0; i < 12; i++) {
    clap.attack("Target"); // Fails after 10th attack
}
```

3. **Type Slice Protection**:
```cpp
ScavTrap scav("S");
ClapTrap copy = scav;  // Slicing occurs
copy.attack("X");      // Always uses ClapTrap::attack
```

### Updated Implementation Notes

1. **Protected Member Access**:
- Allows direct manipulation in derived classes
- Avoids getter/setter boilerplate
- Requires careful maintenance of invariants

2. **Destruction Sequence**:
- Derived destructor completes first
- Base destructor automatically invoked after
- Critical for resource cleanup order

3. **Attack Method Hiding**:
- ScavTrap::attack hides ClapTrap::attack
- No polymorphic behavior without `virtual`
- Explicit scope resolution required:
```cpp
ScavTrap s("S");
s.ClapTrap::attack("Target"); // Force base version
```

### Execution Flow Visualization

```text
Construction:
ClapTrap Constructor -> ScavTrap Constructor

Method Call:
ScavTrap.attack() 
  if (energy > 0 && HP > 0)
    print attack message
    energy--

Destruction:
ScavTrap Destructor -> ClapTrap Destructor
```