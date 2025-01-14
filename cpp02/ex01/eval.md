I'll help you present the CPP Module 02 Ex01 project as a 42 student.

# Project Overview

This project focuses on implementing a fixed-point number class in C++98, expanding on the previous exercise by adding more functionality to handle both integer and floating-point conversions.

## Key Requirements

1. Create a `Fixed` class that represents fixed-point numbers
2. Implement constructors for integers and floating-point numbers
3. Add conversion functions (`toFloat()` and `toInt()`)
4. Overload the insertion operator (`<<`)

```cpp
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
```

### Insertion Operator (<<) Explanation

#### 1. Purpose:

Allows us to print Fixed objects directly using std::cout
Converts the fixed-point number to a readable floating-point format
Makes the class more user-friendly and integrates with C++ streams

#### 2. Implementation Details:
Takes two parameters:
std::ostream &out: Reference to the output stream
const Fixed &fixed: Constant reference to our Fixed object
Uses toFloat() to convert the fixed-point value to a readable format
Returns the stream reference to allow chaining (cout << fixed1 << fixed2)

## Implementation Approach

### Fixed-Point Number Representation

```cpp
class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
    // ...
};
```

I chose to use:
- A 32-bit integer (`_fixedPointValue`) to store the number
- 8 bits for the fractional part (`_fractionalBits`)
- The remaining 24 bits for the integer part

This gives us:
- Range: approximately ±16 million
- Precision: 1/256 (about 0.00390625)

The range and precision of the fixed-point number representation were determined based on the design choices made for the `Fixed` class. 

1. **Range**: The `_fixedPointValue` is stored as a 32-bit integer. With 8 bits allocated for the fractional part, the remaining 24 bits can represent integer values. This allows for a maximum value of \(2^{24} - 1\) (approximately 16 million) and a minimum value of \(-2^{24}\) (approximately -16 million).

2. **Precision**: The precision is defined by the number of bits used for the fractional part. With 8 bits for the fractional component, the smallest representable increment is \(1/256\) (or \(2^{-8}\)), which is approximately 0.00390625. This means that the fixed-point representation can accurately represent decimal values to this precision.


### Key Functions

1. **Integer Constructor**:
```cpp:Fixed.cpp
Fixed::Fixed(const int n)
{
    _fixedPointValue = n << _fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}
```
- Shifts the integer left by 8 bits to make room for the fractional part
- Example: 5 becomes 1280 (5 * 2^8)

The integer constructor shifts the input integer `n` left by 8 bits to allocate space for the fractional part in the fixed-point representation. 

In binary, shifting left by 1 bit is equivalent to multiplying by 2. Therefore, shifting left by 8 bits is equivalent to multiplying by \(2^8\) (or 256). 

For example, when `n` is 5:
- In binary, 5 is represented as `0000 0000 0000 0000 0000 0000 0000 0101`.
- Shifting this left by 8 bits results in `0000 0000 0000 0000 0000 0101 0000 0000`, which is the binary representation of 1280.

Thus, the calculation is:
\[ 5 \times 256 = 1280 \] 

This allows the `Fixed` class to store the integer value while reserving the lower 8 bits for the fractional part.


We need the shifted value (1280 in this case) to properly represent fixed-point numbers with both integer and fractional parts. Here's why:

1. **Purpose**:
- We're using a single integer (`_fixedPointValue`) to store both the integer and decimal parts
- The left shift by 8 bits creates space for decimal values
- This allows us to represent numbers like 5.5, 5.25, 5.125, etc.

2. **Example**:
````
Integer 5:    00000101 << 8
Becomes:      00000101.00000000  (1280 in decimal)

Integer 5.5:  00000101.10000000  (1408 in decimal)
                      ^
                      |
              decimal point (conceptual)
````

3. **Why 8 bits**:
- Gives us 256 possible decimal values (2^8)
- Allows representation of decimals like 0.5 (128), 0.25 (64), 0.125 (32), etc.
- Provides a good balance between range and precision

So when we store 5 as 1280, we're essentially reserving space for decimal values that might be needed in other operations, even if this particular number is a whole integer.

The conversion between 1408 and 5.5 happens through the `toFloat()` function:

`````cpp:Fixed.cpp
float Fixed::toFloat(void) const 
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
    // 1408 / 256 = 5.5
}
`````

Here's how it works:

1. **Storage (Float Constructor)**:
`````cpp:Fixed.cpp
Fixed::Fixed(const float n)
{
    _fixedPointValue = roundf(n * (1 << _fractionalBits));
    // 5.5 * 256 = 1408
}
`````

1. **`round`**:
   - This function is used for rounding double-precision floating-point numbers (`double`).
   - It returns a double value.
   - Example usage: double result = round(5.5);

2. **`roundf`**:
   - This function is specifically for rounding single-precision floating-point numbers (`float`).
   - It returns a float value.
   - Example usage: float result = roundf(5.5f);    

2. **Binary Representation**:
```
5.5 in fixed-point (1408):
Binary: 0000 0101 1000 0000
        ┌─────┐ ┌─────────┐
        Integer Fractional
        (5)     (0.5)
```

3. **Conversion Back**:
- When converting back to float, we divide by 256 (2^8):
- 1408 / 256 = 5.5
  - Integer part (1280/256 = 5)
  - Fractional part (128/256 = 0.5)


2. **Float Constructor**:
```cpp:Fixed.cpp
Fixed::Fixed(const float n)
{
    _fixedPointValue = roundf(n * (1 << _fractionalBits));
    std::cout << "Float constructor called" << std::endl;
}
```
- Multiplies the float by 256 (2^8)
- Uses `roundf` to get the nearest integer value
- Example: 5.5 becomes 1408 (5.5 * 256)

3. **Conversion Functions**:
```cpp:Fixed.cpp
float Fixed::toFloat(void) const 
{
    return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const 
{
    return this->_fixedPointValue >> _fractionalBits;
}
```

## Copy Assignment Operator



Let's break down what happens in `a = Fixed(1234.4321f)`:

1. First, `Fixed(1234.4321f)` creates a temporary `Fixed` object:
````cpp:Fixed.cpp
Fixed::Fixed(const float n)
{
    _fixedPointValue = roundf(n * (1 << _fractionalBits));
    // 1234.4321 * 256 = 316014.6176
    // after roundf = 316015
    std::cout << "Float constructor called" << std::endl;
}
````

2. Then, the copy assignment operator is called:
````cpp:Fixed.cpp
Fixed &Fixed::operator=(const Fixed &rhs) 
{
    if (this != &rhs)
    {
        this->_fixedPointValue = rhs.getRawBits();
        // getRawBits simply returns the _fixedPointValue (316015)
        // of the temporary object created in step 1
    }
    return *this;
}
````

So `getRawBits()` doesn't actually extract or convert anything - it just returns the already converted value (`_fixedPointValue`) that was calculated in the float constructor. The conversion from float to fixed-point format happens in the constructor, not in `getRawBits()`.

The sequence is:
1. Float constructor converts 1234.4321f to 316015
2. Copy assignment gets this value (316015) via `getRawBits()`
3. The value 316015 is stored in `a._fixedPointValue`

When you later print `a`, this value is converted back to float by dividing by 256, giving you 1234.4321f again.

## Error Handling & Edge Cases

1. **Self-Assignment Protection**:
```cpp:Fixed.cpp
Fixed &Fixed::operator=(const Fixed &rhs) 
{
    if (this != &rhs) // Prevent self-assignment
    {
        this->_fixedPointValue = rhs.getRawBits();
    }
    return *this;
}
```

2. **Overflow Considerations**:
- The implementation can handle integers up to ±16 million before overflow
- Float-to-fixed conversion rounds numbers to prevent precision loss

## Memory Management

- No dynamic memory allocation is needed
- All member variables are stack-allocated
- Copy constructor and assignment operator ensure proper object copying

## Learning Outcomes

1. **Fixed-Point Arithmetic**:
   - Understanding binary representation of decimal numbers
   - Bit manipulation for efficient calculations

2. **Operator Overloading**:
   - Implementing custom stream output behavior

3. **C++ Best Practices**:
   - Const correctness
   - Reference vs. value semantics
   - Proper class design

Would you like me to elaborate on any specific aspect of the implementation?
