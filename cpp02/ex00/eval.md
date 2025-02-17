# Evaluation Questions and Answers

## 1. Copy Constructor
**Question:** How does the copy constructor work in the `Fixed` class and why is it important?  
**Answer:**  
The copy constructor accepts a reference to a constant `Fixed` object to initialize a new instance. It uses the copy assignment operator (`*this = src`) to duplicate the internal `_fixedPointValue`. This ensures the new object is an exact copy without sharing memory (even though no dynamic memory is used here). It is essential for proper object copying when objects are passed by value or returned from functions.

## 2. Copy Assignment Operator
**Question:** What is the significance of the self-assignment check (`if (this != &rhs)`) in the copy assignment operator?  
**Answer:**  
The self-assignment check prevents the scenario where an object is inadvertently assigned to itself, which could lead to data corruption or unnecessary operations. By ensuring that the source and destination are different objects, the operator safely copies the `_fixedPointValue` only when required.

## 3. Static Member Use
**Question:** What role does the `static const int _fractionalBits` play in the `Fixed` class?  
**Answer:**  
The `_fractionalBits` member defines the number of bits used for the fractional part in the fixed-point representation. Being static and constant, it is shared across all instances and ensures that every object of the `Fixed` class uses the same precision configuration. This consistency is crucial for correctly handling fixed-point arithmetic operations.

## 4. Memory Management
**Question:** Discuss the memory management strategy used in this project and its implications during evaluation.  
**Answer:**  
The project does not perform any dynamic memory allocation. All data members are declared with automatic storage, and the destructor serves primarily for tracing the object lifecycle rather than for memory deallocation. Since no dynamic memory allocation occurs, this design inherently prevents memory leaks, which can be validated by tools like Valgrind.

## 5. Debug Output
**Question:** How do the debug messages within constructors and member functions assist in the evaluation process?  
**Answer:**  
Debug messages (e.g., "Default constructor called", "Copy constructor called", "Destructor called") provide real-time feedback about the object lifecycle and method invocations. They help evaluators trace the sequence of operations, ensuring that object creation, copying, and destruction occur as designed. This traceability is key in diagnosing and verifying correct copy semantics and lifecycle management.

---

# Fixed-Point Specific Questions

## 6. Fixed-Point Representation Fundamentals
**Question:** What is a fixed-point number representation, and how does it differ from floating-point representation?  
**Answer:**  
A fixed-point number representation stores a number as an integer along with an implied scaling factor (typically by using a fixed number of fractional bits). Unlike floating-point numbers, which allocate bits for a mantissa and exponent to handle a wide range of values dynamically, fixed-point has a fixed precision and scale. This results in predictable performance and simpler arithmetic at the cost of a limited range and precision.

## 7. Role of `_fractionalBits`
**Question:** How does the `_fractionalBits` constant in the `Fixed` class affect the operations and precision of fixed-point arithmetic in this project?  
**Answer:**  
The `_fractionalBits` constant determines how many bits are used to represent the fractional part of the number. This fixed value ensures a consistent scaling factor across all fixed-point calculations, thereby regulating the precision. It directly affects the smallest increment or decrement possible in the number's value, and any arithmetic operation must adhere to the scale defined by `
