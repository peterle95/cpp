### Key Differences Between ex01 and ex02

1. **Class Hierarchy Extension**:
```cpp
// ex01: Single inheritance
class ScavTrap : public ClapTrap {...};

// ex02: Multiple derived classes
class ScavTrap : public ClapTrap {...};
class FragTrap : public ClapTrap {...};
```

2. **Class-Specific Features**:
```cpp
// ex01 (ScavTrap only)
void guardGate();  // Unique to ScavTrap

// ex02 (FragTrap addition)
void highFivesGuys();  // Unique to FragTrap
void showStats() const; // New debugging method
```

3. **Attribute Initialization**:
```cpp
// ex01 ScavTrap stats:
hitPoints = 100;
energyPoints = 50;
attackDamage = 20;

// ex02 FragTrap stats:
hitPoints = 100;
energyPoints = 100;  // Increased energy
attackDamage = 30;   // Higher damage
```

4. **Method Override Patterns**:
```cpp
// ex01 Attack message:
"ScavTrap: " << name << " attacks..."

// ex02 FragTrap Attack:
"FragTrap: " << name << " attacks..." 
// Distinct class identifier
```

5. **Construction/Destruction Messages**:
```text
ex01 Flow:
ClapTrap → ScavTrap creation
ScavTrap → ClapTrap destruction

ex02 Additional Flow:
ClapTrap → FragTrap creation
FragTrap → ClapTrap destruction
```

6. **Testing Complexity**:
```cpp
// ex02 main.cpp adds:
- Multiple derived class interaction
- Stat verification methods
- Energy depletion tests
- Death state validation
```

### Evaluation Focus Differences

| Aspect                | ex01                      | ex02                          |
|-----------------------|---------------------------|-------------------------------|
| Core Concept          | Single inheritance        | Multiple derivatives          |
| Polymorphism Testing  | Base vs derived methods   | Cross-class method comparison |
| Memory Challenges     | Basic construction chain  | Multiple object interaction   |
| Edge Cases            | Energy depletion          | Death state + repair limits   |
| Special Methods       | guardGate() only          | highFivesGuys() + stats       |

### Implementation Challenges Comparison

1. **ex01 Challenges**:
- Managing ScavTrap-specific attack logic
- Proper construction/destruction chaining
- Preventing base class method misuse

2. **ex02 New Challenges**:
- Coordinating multiple derived classes
- Maintaining distinct attack values:
  ```cpp
  // Attack Damage Variations
  ClapTrap: 0 → ScavTrap: 20 → FragTrap: 30
  ```
- Handling mixed object types in testing
- Ensuring proper stat display formatting

### Memory Management Differences

```text
ex01 Allocation Pattern:
ClapTrap → ScavTrap

ex02 Extended Pattern:
ClapTrap → ScavTrap
ClapTrap → FragTrap
│           │
└─ Mixed object tests
```

### Evaluation Question Differences

1. **ex01 Focus**:
- "Explain the constructor chain when creating ScavTrap"
- "How does method hiding affect base class calls?"

2. **ex02 Additions**:
- "Compare memory layouts of ScavTrap vs FragTrap"
- "How does showStats() help debug inheritance issues?"
- "Why do FragTrap attacks consume different energy than ScavTrap?"
