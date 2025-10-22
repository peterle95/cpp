# CPP09: Module Overview

## Purpose

Module CPP09 teaches advanced C++ Standard Template Library (STL) usage through practical exercises involving data structures and algorithms. The focus is on:

- **std::map**: Sorted associative container for key-value pairs
- **std::stack**: LIFO data structure for expression evaluation
- **File I/O**: Reading and writing files
- **String Parsing**: Breaking down and analyzing text data
- **Algorithm Design**: Solving problems with appropriate data structures
- **Error Handling**: Validating input and handling edge cases

## Exercises Overview

### Exercise 00: Bitcoin Exchange

**Topic**: `std::map` and Date-based Lookups

#### Problem Statement
Create a program that loads historical Bitcoin exchange rate data and calculates the value of Bitcoin on specific dates.

#### Key Concepts
- `std::map<std::string, float>` for sorted date-to-rate mappings
- `std::map::lower_bound()` for efficient approximate matching
- Complex date validation with leap year calculations
- File I/O with CSV format
- Input validation and error handling

#### Data Structures
```cpp
std::map<std::string, float> _data;  // date → exchange_rate
```

#### Key Algorithm: lower_bound() Lookup

```
Given dates: 2009-01-02, 2009-01-03, 2009-01-05

Request 2009-01-04:
├─ lower_bound("2009-01-04") → first element >= "2009-01-04"
├─ Returns iterator to 2009-01-05
├─ Since it->first != "2009-01-04", decrement iterator
└─ Use 2009-01-03's rate (closest earlier date)

This allows interpolation: if exact date not available,
use the most recent available date's rate.
```

#### Files
- `BitcoinExchange.hpp`: Class declaration with extensive comments
- `BitcoinExchange.cpp`: Implementation of data loading and processing
- `main.cpp`: Entry point with argument validation
- `EXERCISE_EXPLANATION.md`: Comprehensive walkthrough
- `data.csv`: Historical Bitcoin data
- `input.txt`: Example user input

#### Execution Flow
```
main()
  ↓
Create BitcoinExchange object
  ↓
readData()
  ├─ Open data.csv
  └─ Populate _data map
  ↓
processInput(filename)
  ├─ Parse each line (date | amount)
  ├─ Validate inputs
  ├─ Use lower_bound() to find exchange rate
  └─ Calculate and output result
```

#### Time Complexity
- Loading data: O(n log n) where n = number of data points
- Processing input: O(m log n) where m = number of queries
- Each lookup via lower_bound(): O(log n)

---

### Exercise 01: Reverse Polish Notation (RPN) Calculator

**Topic**: `std::stack` and Expression Evaluation

#### Problem Statement
Implement a calculator that evaluates mathematical expressions in Reverse Polish Notation (postfix notation).

#### Key Concepts
- `std::stack<int>` for LIFO operand storage
- Token parsing and classification
- Stack-based expression evaluation
- Understanding RPN advantages over infix notation
- Operator order and operand handling

#### Data Structures
```cpp
std::stack<int> _stack;  // Stores operands during evaluation
```

#### Key Algorithm: RPN Evaluation

```
For each token in expression:
  IF token is a digit:
    push onto stack
  ELSE IF token is operator:
    pop right operand (val2)
    pop left operand (val1)
    compute: result = val1 OP val2
    push result
  ELSE:
    error (invalid token)

After all tokens:
  IF stack size = 1:
    output: stack.top()
  ELSE:
    error
```

#### Critical Concept: Operand Order

For `"5 3 -"`:
```
Stack when reaching "-": [5, 3]
Correct:
  val2 = pop() → 3
  val1 = pop() → 5
  Result: 5 - 3 = 2 ✓

Wrong:
  val1 = pop() → 3
  val2 = pop() → 5
  Result: 3 - 5 = -2 ✗
```

#### Files
- `RPN.hpp`: Class declaration with extensive comments
- `RPN.cpp`: Implementation with algorithm walkthrough
- `main.cpp`: Entry point with argument validation
- `EXERCISE_EXPLANATION.md`: Comprehensive guide with examples
- `manual.md`: Original documentation (kept for reference)

#### Execution Flow
```
main()
  ↓
Create RPN object with empty stack
  ↓
execute(expression)
  ├─ Tokenize input string
  ├─ For each token:
  │  ├─ Classify (digit/operator/invalid)
  │  └─ Process accordingly
  ├─ Validate final stack size = 1
  └─ Output result or error
```

#### Time Complexity
- Tokenization: O(n) where n = length of expression
- Token processing: O(n) for n tokens
- Each push/pop: O(1)
- Overall: O(n)

---

## Comparison: Exercise 00 vs Exercise 01

| Aspect | Ex00 (Bitcoin) | Ex01 (RPN) |
|--------|---|---|
| **Data Structure** | `std::map` | `std::stack` |
| **Primary Goal** | Data lookup with interpolation | Expression evaluation |
| **Algorithm Complexity** | Binary search (lower_bound) | Linear stack operations |
| **Input Format** | CSV + date/amount lines | Postfix expression tokens |
| **Key Challenge** | Date validation & lookup | Operand ordering |
| **Real-world Use** | Financial data analysis | Calculator implementation |

---

## Common Patterns Used

### 1. File I/O Pattern
```cpp
std::ifstream file(filename);
if (!file.is_open()) { /* error */ }
std::string line;
while (std::getline(file, line)) { /* process */ }
```

### 2. String Parsing Pattern
```cpp
std::stringstream ss(line);
std::string token;
while (ss >> token) { /* process each token */ }
```

### 3. Validation Pattern
```cpp
if (condition_fails) {
  std::cerr << "Error: ..." << std::endl;
  return;  // or continue/break as appropriate
}
```

### 4. Container-based Lookup
```cpp
auto it = container.lower_bound(key);
if (it != container.begin() && (it == container.end() || it->first != key)) {
  --it;  // Use previous element
}
```

---

## Learning Progression

The exercises progress in difficulty:

1. **Exercise 00**: Data management and lookup
   - Focus: File I/O, data structures, searching
   - Complexity: Moderate (date validation, lower_bound usage)

2. **Exercise 01**: Algorithm implementation
   - Focus: Stack-based computation, token processing
   - Complexity: Moderate (operand ordering, state management)

Both exercises require:
- Effective use of STL containers
- Input validation and error handling
- Clear algorithm implementation
- Comprehensive understanding of underlying data structures

---

## Key STL Features Demonstrated

### std::map
- **Properties**: Sorted by key, O(log n) operations
- **Usage**: Key-value storage with efficient lookup
- **Methods**: `insert()`, `find()`, `lower_bound()`, `upper_bound()`

### std::stack
- **Properties**: LIFO access, O(1) operations
- **Usage**: Temporary storage with ordered access
- **Methods**: `push()`, `pop()`, `top()`, `size()`, `empty()`

### std::stringstream
- **Properties**: Text-based I/O interface for strings
- **Usage**: Token parsing and string manipulation
- **Operators**: `>>` (extraction), `<<` (insertion)

### std::ifstream
- **Properties**: File input stream
- **Usage**: Reading data from files
- **Methods**: `open()`, `is_open()`, `getline()`

---

## Error Handling Patterns

### Graceful Degradation
```cpp
// File not found - print warning but continue
if (!file.is_open()) {
  std::cerr << "Error: could not open file." << std::endl;
  return;
}
```

### Line-by-Line Validation
```cpp
while (std::getline(file, line)) {
  if (!isValid(line)) {
    std::cerr << "Error: " << line << std::endl;
    continue;  // Skip to next line
  }
  process(line);
}
```

### Multi-layer Checks
```cpp
// Validation pyramid
if (!checkFormat(data)) return error;
if (!checkRange(data)) return error;
if (!checkBusiness(data)) return error;
process(data);
```

---

## Documentation Structure

Each exercise includes:

1. **Source Code Comments**: Extensive inline comments explaining:
   - Algorithm steps
   - Data structure usage
   - Edge cases and validation
   - Examples and walkthrough

2. **EXERCISE_EXPLANATION.md**: Comprehensive markdown document with:
   - Overview and purpose
   - Architecture and design
   - Step-by-step execution with examples
   - Error handling patterns
   - Comparison tables
   - Common mistakes and how to avoid them

3. **Header Comments**: At file level explaining:
   - Overall purpose
   - Key concepts
   - Data flow and relationships

---

## Compilation and Execution

### Build
```bash
cd cpp09/ex00  # or ex01
make           # Compiles the program
```

### Run Examples

**Exercise 00:**
```bash
./btc input.txt
```

**Exercise 01:**
```bash
./rpn "3 4 +"
./rpn "8 9 * 9 - 9 - 9 - 9 - 4 - 1 +"
```

### Clean
```bash
make clean     # Removes compiled files
```

---

## Further Learning

### Concepts to Research
- B-trees and map implementation
- Stack frames and recursion
- Expression parsing and compilation
- Operator precedence and associativity
- Infix to postfix conversion algorithms

### Extensions
- **Ex00**: Support floating-point amounts, multiple files
- **Ex01**: Support multi-digit numbers, more operators, variables

### Related Topics
- **Compiler design**: Lexing, parsing, AST evaluation
- **Financial systems**: Real-world data handling
- **Calculator applications**: GUI interfaces, extended operators

---

## Quick Reference

### When to Use Each Data Structure

**Use std::map when:**
- Need sorted key-value pairs
- Need efficient lookup by key
- Need range queries (lower_bound, upper_bound)
- Data is sparse (not all possible keys present)

**Use std::stack when:**
- Need LIFO (Last In, First Out) access
- Evaluating expressions or following recursive patterns
- Need temporary storage of items
- Order of retrieval is opposite of insertion

**Use std::vector when:**
- Need random access by index
- Most operations are append or iteration
- Memory efficiency is critical

**Use std::queue when:**
- Need FIFO (First In, First Out) access
- Processing items in arrival order

---

## File Organization

```
cpp09/
├── ex00/
│   ├── BitcoinExchange.hpp     (Extensively commented)
│   ├── BitcoinExchange.cpp     (Extensively commented)
│   ├── main.cpp                (Extensively commented)
│   ├── EXERCISE_EXPLANATION.md (Comprehensive guide)
│   ├── data.csv                (Bitcoin historical data)
│   ├── input.txt               (Example input)
│   └── Makefile
│
└── ex01/
    ├── RPN.hpp                 (Extensively commented)
    ├── RPN.cpp                 (Extensively commented with examples)
    ├── main.cpp                (Extensively commented)
    ├── EXERCISE_EXPLANATION.md (Comprehensive guide)
    ├── manual.md               (Original documentation)
    └── Makefile
```

---

## Summary

CPP09 focuses on **practical STL usage** with two exercises:

1. **Bitcoin Exchange**: Maps, file I/O, date validation, binary search
2. **RPN Calculator**: Stacks, tokenization, expression evaluation

Both exercises emphasize:
- Clear algorithm implementation
- Comprehensive error handling
- Effective data structure usage
- Clean, well-documented code

The extensive comments and markdown documentation provide multiple levels of understanding, from quick reference to deep algorithmic walkthroughs.
