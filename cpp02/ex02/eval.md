## Project Analysis

### 1. File Purpose and Functionality
Implements a fixed-point number class that maintains precision using integer arithmetic. Key components:
- Fixed-point value storage using integer with fractional bits
- Arithmetic operator overloads for fixed-point operations
- Conversion functions to/from floating-point types

### 2. Technical Implementation Details
```cpp
class Fixed {
private:
    int              _value;
    static const int _fractionalBits = 8;
public:
    // ... constructors/destructors ...
    Fixed& operator=(const Fixed& other);
    int    getRawBits() const;
    void   setRawBits(int const raw);
    // ... arithmetic operators ...
};
```
- Fixed-point value stored as integer with 8 fractional bits
- Uses bit shifting (<< 8 and >> 8) for scaling conversions
- Implements full set of comparison and arithmetic operators

### 3. Problems Encountered and Solutions
**Precision Management:**
- Solution: Use consistent bit shifting operations for all conversions
- Tradeoff: Limits maximum representable value compared to floating-point

**Operator Overloading:**
- Challenge: Maintaining proper scaling during arithmetic operations
- Solution: Implement temporary scaling adjustment in operator implementations

### 4. Memory Management Considerations
- No dynamic memory allocation required
- All operations use stack-allocated objects
- Copy constructor/assignment operator handle integer value duplication

### 5. Potential Evaluation Questions

1. **Why use fixed-point arithmetic instead of floating-point?**
   Answer: Avoids floating-point precision inconsistencies, provides predictable precision for financial calculations, and uses integer operations which can be faster on some architectures.

2. **How is the fixed-point value stored in memory?**
   Answer: Stored as an integer with 8 bits reserved for fractional part (Q24.8 format). Value = _value / 2^8

3. **Why implement both member and non-member operator overloads?**
   Answer: Member operators (like +=) modify object state, while non-member operators (like +) create new objects. This maintains const-correctness and proper operator semantics.

4. **How are conversion constructors used in this implementation?**
   Answer: Allow implicit conversion from int/float to Fixed type:
   ```cpp
   Fixed(float f) : _value(f * (1 << _fractionalBits)) {}
   Fixed(int i) : _value(i << _fractionalBits) {}
   ```

5. **What edge cases must be considered in arithmetic operations?**
   - Integer overflow during multiplication
   - Division by zero
   - Loss of precision when converting from float
   Solution: Use larger temporary types (long) during calculations

6. **How would you test the precision boundaries?**
   Answer: Verify smallest representable value (1/256), maximum value (2^23-1/256), and mid-point rounding behavior

7. **Why make _fractionalBits static const?**
   Answer: Ensures consistent scaling across all class instances and allows compiler optimizations

8. **How is const-correctness maintained?**
   Answer: All member functions that don't modify state are marked const, allowing use on const objects

9. **What would happen with a very large float input?**
   Answer: Potential integer overflow in _value, which would wrap around (undefined behavior). Should add range checking in conversion constructor.

10. **How does this implementation avoid memory leaks?**
    Answer: No dynamic memory allocation used - all members are primitive types managed on the stack

11. **Why must the assignment operator be implemented as a member function?**
    Answer: The assignment operator has special semantics in C++ where it must modify the left-hand operand. As a member function:
    - Directly accesses private `_value` member without friend declarations
    - Can handle self-assignment checks (though not needed here with primitive type)
    - Maintains natural syntax (`a = b` vs `a.operator=(b)`)
    - Non-member implementation would require friend access and lose access to private members

12. **How does operator+= differ from operator+ in implementation?**
    Answer: The key differences stem from their operational semantics:
    ```cpp
    // Compound assignment (+=) modifies object and returns reference
    Fixed& operator+=(const Fixed& rhs) {
        _value += rhs._value;  // Direct state modification
        return *this;          // Allows chaining: a += b += c
    }
    
    // Binary operator (+) creates new object without modifying operands
    Fixed operator+(const Fixed& a, const Fixed& b) {
        return Fixed::fromRaw(a.getRawBits() + b.getRawBits());
    }
    ```
    - `+=` is more efficient for multiple operations
    - `+` preserves immutability of original operands

13. **Why implement the << operator as a friend function?**
    Answer: The stream insertion operator needs special handling:
    ```cpp
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
        os << fixed.toFloat();  // Requires access to private _value via getter
        return os;              // Maintains stream state and chaining
    }
    ```
    - Must be non-member to match natural usage: `cout << fixed` vs `fixed << cout`
    - Friendship grants access while keeping encapsulation
    - Return stream reference enables chaining: `cout << a << b`

14. **How is precision maintained during multiplication?**
    Answer: Multiplication requires careful scaling management:
    ```cpp
    Fixed operator*(const Fixed& a, const Fixed& b) {
        long temp = static_cast<long>(a.getRawBits()) * b.getRawBits();
        return Fixed(static_cast<int>(temp >> Fixed::_fractionalBits));
    }
    ```
    - Uses `long` to prevent overflow during intermediate calculation
    - Shifts right by fractional bits to compensate for double scaling
    - Example: 1.5 * 2.0 (stored as 384 and 512) becomes (384*512)=196608, shifted >>8 = 768 (3.0)

15. **Why return bool from comparison operators instead of other types?**
    Answer: Comparison operators follow standard semantics:
    ```cpp
    bool operator>(const Fixed& lhs, const Fixed& rhs) {
        return lhs.getRawBits() > rhs.getRawBits();
    }
    ```
    - Returns `bool` to match expected comparison results
    - Const references prevent unnecessary copies
    - No modification of operands ensures safe usage in conditional expressions

16. **How does prefix vs postfix increment differ in implementation?**
    Answer: The implementations reflect their distinct behaviors:
    ```cpp
    // Prefix: increment then return reference
    Fixed& operator++() {
        _value += 1 << _fractionalBits;  // Add 1.0 in fixed-point
        return *this;                    // Return modified object
    }
    
    // Postfix: return copy before increment
    Fixed operator++(int) {
        Fixed temp(*this);   // Make copy of current state
        ++(*this);           // Use prefix to increment
        return temp;         // Return original value
    }
    ```
    - Dummy `int` parameter distinguishes postfix version
    - Postfix is less efficient due to temporary copy

17. **Why make conversion methods like toFloat() const?**
    Answer: Const correctness ensures:
    ```cpp
    float toFloat() const {  // Marked const
        return static_cast<float>(_value) / (1 << _fractionalBits);
    }
    ```
    - Safe to call on const objects (`const Fixed f; f.toFloat()`)
    - Clearly communicates no state modification
    - Enables use in const contexts (e.g., operator<< for const references)

18. **How are mixed-type operations handled (e.g., Fixed + int)?**
    Answer: Conversion constructors enable automatic type promotion:
    ```cpp
    Fixed a(5);
    Fixed b = a + 3;  // 3 converted to Fixed via Fixed(int)
    ```
    - Requires careful constructor design to prevent implicit conversions
    - `explicit` keyword used where automatic conversion isn't desired
    - Operators implemented as non-members enable symmetric conversions

19. **Why implement both default and copy constructors?**
    Answer: Ensures proper initialization in all scenarios:
    ```cpp
    Fixed() : _value(0) {}  // Default to 0.0
    
    Fixed(const Fixed& other) : _value(other._value) {}  // Bitwise copy
    
    explicit Fixed(int i) : _value(i << _fractionalBits) {}  // Prevent implicit int conversion
    ```
    - Default constructor avoids uninitialized objects
    - Copy constructor enables pass-by-value semantics
    - Explicit constructors prevent accidental conversions

20. **How does division handle fractional precision?**
    Answer: Prescaling numerator before division:
    ```cpp
    Fixed operator/(const Fixed& a, const Fixed& b) {
        if (b.getRawBits() == 0) throw std::runtime_error("Division by zero");
        long temp = static_cast<long>(a.getRawBits()) << _fractionalBits;
        return Fixed(static_cast<int>(temp / b.getRawBits()));
    }
    ```
    - Shifts left to preserve precision before division
    - Uses larger type (long) to prevent overflow during scaling
    - Example: 3.0 / 2.0 becomes (768 << 8) = 196608 / 512 = 384 (1.5)
