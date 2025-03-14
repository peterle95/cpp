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

### Practical Applications of Inheritance/Polymorphism

1. **GUI Framework Development**  
```cpp
class Widget 
{
public:
    virtual void draw() = 0;
    virtual void handleEvent(Event e) = 0;
};

class Button : public Widget 
{
    void draw() override { /* Render button */ }
    void handleEvent(Event e) override { /* Click handling */ }
};

class Slider : public Widget 
{
    void draw() override { /* Render slider track */ }
    void handleEvent(Event e) override { /* Drag handling */ }
};

// Unified rendering loop
void renderUI(const vector<Widget*>& components) 
{
    for (auto widget : components) {
        widget->draw();  // Polymorphic call
    }
}
```
**Why it matters**: Enables creating new UI elements without modifying rendering system

2. **Automotive Systems**  
```cpp
class EngineController 
{
public:
    virtual void adjustThrottle() = 0;
    virtual ~EngineController() {}
};

class CombustionEngine : public EngineController 
{
    void adjustThrottle() override 
    {
        // Mechanical throttle body control
    }
};

class ElectricMotor : public EngineController 
{
    void adjustThrottle() override 
    {
        // Power electronics modulation
    }
};

class HybridSystem : public EngineController 
{
    void adjustThrottle() override 
    {
        // Balance between ICE and electric
    }
};
```
**Key Benefit**: Same interface for different propulsion systems enables hybrid control strategies

3. **Medical Device Alerts**  
```cpp
class PatientMonitor {
public:
    virtual void checkStatus() = 0;
    virtual string getAlert() = 0;
};

class HeartRateMonitor : public PatientMonitor {
    void checkStatus() override {
        // Analyze ECG signals
    }
    string getAlert() override {
        return "Cardiac arrhythmia detected";
    }
};

class OxygenSensor : public PatientMonitor {
    void checkStatus() override {
        // Measure SpO2 levels
    }
    string getAlert() override {
        return "Oxygen saturation below 90%";
    }
};

void criticalCareSystem(vector<PatientMonitor*>& devices) {
    for (auto device : devices) {
        device->checkStatus();
        if (!device->getAlert().empty()) {
            nurseStation.notify(device->getAlert());
        }
    }
}
```
**Advantage**: Uniform alert handling across different biometric sensors

### Why These Matter for Your Project
1. Demonstrates how class hierarchies model real-world relationships
2. Shows practical value of virtual method dispatch
3. Illustrates maintainability benefits for complex systems
4. Highlights interface consistency across implementations
