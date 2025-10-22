# Exercise 01: Reverse Polish Notation (RPN) Calculator

## Overview

This exercise implements a calculator that evaluates mathematical expressions written in Reverse Polish Notation (RPN), also known as postfix notation. RPN is a mathematical notation where operators follow their operands instead of being between them.

## Purpose of the Exercise

The goal is to practice:
- **Stack Data Structure**: Using `std::stack` for efficient LIFO operations
- **String Parsing**: Tokenizing input strings and classifying tokens
- **Algorithm Design**: Implementing the classic stack-based RPN evaluation algorithm
- **Error Handling**: Detecting malformed expressions and invalid operations
- **Operator Precedence**: Understanding how RPN eliminates the need for precedence rules
- **Postfix Notation**: Converting between infix (normal) and postfix (RPN) thinking

## What is Reverse Polish Notation (RPN)?

### Definition

RPN is a notation where:
- **Operands** (numbers) come before **operators** (mathematical symbols)
- Each operator applies to the most recent operands
- No parentheses needed (order is unambiguous)

### Comparison: Infix vs Postfix

| Operation | Infix (Normal) | Postfix (RPN) |
|-----------|---|---|
| Add 3 and 4 | `3 + 4` | `3 4 +` |
| Multiply then add | `3 + 4 * 5` | `3 4 5 * +` |
| With parentheses | `(3 + 4) * 5` | `3 4 + 5 *` |
| Complex | `8 * 9 - 9 - 9 - 9 - 4 - 1 + 1` | `8 9 * 9 - 9 - 9 - 9 - 4 - 1 +` |

### Why RPN?

- **Simple evaluation**: Just iterate left-to-right with a stack
- **No operator precedence needed**: Order is explicit
- **No parentheses needed**: Structure is unambiguous
- **Efficient computation**: Direct execution, no parsing tree needed
- **Real-world use**: Used in calculators (HP calculators), compilers, expression evaluation engines

## Program Architecture

### Class: RPN

```
RPN
│
├── Private Members:
│   └── _stack: std::stack<int>
│       └── Stores operands during evaluation
│
├── Private Methods:
│   ├── RPN(const RPN&)      [deleted]
│   └── operator=(const RPN&) [deleted]
│
└── Public Methods:
    ├── RPN()
    ├── ~RPN()
    └── execute(const std::string& expression)
```

### Data Flow

```
Command Line: ./rpn "3 4 +"
    ↓
main()
    ↓
RPN::execute("3 4 +")
    ├─→ Parse tokens: ["3", "4", "+"]
    ├─→ Process "3": push 3 on stack
    ├─→ Process "4": push 4 on stack
    ├─→ Process "+": pop 4, pop 3, compute 3+4=7, push 7
    ├─→ Verify stack size = 1
    └─→ Output: 7
```

## How It Works Step by Step

### Phase 1: Program Initialization

```
1. Run: ./rpn "8 9 * 9 - 9 - 9 - 4 - 1 +"
2. main() validates argc == 2 ✓
3. Create RPN object with empty stack
4. Call execute() with the expression string
```

### Phase 2: Tokenization

The input string is broken into tokens (whitespace-separated):

```
Input: "8 9 * 9 - 9 - 9 - 4 - 1 +"
Tokens: ["8", "9", "*", "9", "-", "9", "-", "9", "-", "4", "-", "1", "+"]
```

**Method**: `std::stringstream` with `>> token` operator

### Phase 3: Token Processing Loop

For each token, one of three things happens:

#### Token Type 1: Single Digit

```
Token: "3"
Check: length == 1 && isdigit('3')?  YES
Action: Convert to integer (3) and push onto stack
Result: stack = [3]
```

#### Token Type 2: Operator

```
Token: "+"
Check: Is it "+", "-", "*", or "/"?  YES
Action:
  1. Verify stack has ≥ 2 elements
  2. Pop right operand (val2)
  3. Pop left operand (val1)
  4. Compute: result = val1 OP val2
  5. Push result back
Result: stack = [result]
```

#### Token Type 3: Invalid

```
Token: "abc"
Check: Not a digit, not an operator
Action: Report error and stop
Result: stderr = "Error"
```

### Phase 4: The Stack During Execution

Example: `"8 9 * 9 - 9 - 9 - 4 - 1 +"`

```
Processing step-by-step:

Step 1: "8"  → push 8
        Stack: [8]

Step 2: "9"  → push 9
        Stack: [8, 9]

Step 3: "*"  → pop 9, pop 8, 8*9=72, push 72
        Stack: [72]

Step 4: "9"  → push 9
        Stack: [72, 9]

Step 5: "-"  → pop 9, pop 72, 72-9=63, push 63
        Stack: [63]

Step 6: "9"  → push 9
        Stack: [63, 9]

Step 7: "-"  → pop 9, pop 63, 63-9=54, push 54
        Stack: [54]

Step 8: "9"  → push 9
        Stack: [54, 9]

Step 9: "-"  → pop 9, pop 54, 54-9=45, push 45
        Stack: [45]

Step 10: "4" → push 4
         Stack: [45, 4]

Step 11: "-" → pop 4, pop 45, 45-4=41, push 41
         Stack: [41]

Step 12: "1" → push 1
         Stack: [41, 1]

Step 13: "+" → pop 1, pop 41, 41+1=42, push 42
         Stack: [42]

End: Stack has exactly 1 element
Output: "42"
```

### Phase 5: Result Validation

After processing all tokens:

```
if (stack.size() == 1)
  ├─ Output: stack.top()  ✓ Correct!
  └─ Example: "7"

else if (stack.size() == 0)
  ├─ Error: No result
  └─ Output: "Error"

else (stack.size() > 1)
  ├─ Error: Multiple values left (missing operator)
  ├─ Example: Input "3 4" leaves [3, 4]
  └─ Output: "Error"
```

## Critical Concept: Operand Order

### Why Pop Right First?

```
For expression: "5 3 -"
We want: 5 - 3 = 2 (NOT 3 - 5 = -2)

Stack state when we reach "-":
[5, 3]
 ↑  ↑
bottom top

Correct popping sequence:
1. val2 = pop() → val2 = 3, stack = [5]
2. val1 = pop() → val1 = 5, stack = []
3. Compute: val1 - val2 = 5 - 3 = 2 ✓

Wrong popping sequence:
1. val1 = pop() → val1 = 3, stack = [5]
2. val2 = pop() → val2 = 5, stack = []
3. Compute: val1 - val2 = 3 - 5 = -2 ✗
```

### Order Matters for Subtraction and Division

| Operation | Stack | Pop Order | Calculation | Result |
|-----------|-------|-----------|-------------|--------|
| `5 3 -` | `[5, 3]` | val2=3, val1=5 | 5 - 3 | 2 ✓ |
| `8 2 /` | `[8, 2]` | val2=2, val1=8 | 8 / 2 | 4 ✓ |
| `2 8 /` | `[2, 8]` | val2=8, val1=2 | 2 / 8 | 0 ✓ |

### Order Doesn't Matter for Addition and Multiplication

| Operation | Stack | Calculation | Result |
|-----------|-------|-------------|--------|
| `3 4 +` | `[3, 4]` | 3 + 4 = 7 | 7 ✓ |
| `4 3 +` | `[4, 3]` | 4 + 3 = 7 | 7 ✓ |
| `3 4 *` | `[3, 4]` | 3 * 4 = 12 | 12 ✓ |
| `4 3 *` | `[4, 3]` | 4 * 3 = 12 | 12 ✓ |

## Error Handling

### Error Conditions

| Error Type | Condition | Example | Output |
|-----------|-----------|---------|--------|
| **Stack Underflow** | Operator with < 2 operands | `"3 +"` | `"Error"` |
| **Invalid Token** | Non-digit, non-operator token | `"3 4 &"` | `"Error"` |
| **Division by Zero** | Dividing by 0 | `"5 0 /"` | `"Error: Division by zero."` |
| **Multiple Values** | Stack has > 1 element at end | `"3 4"` | `"Error"` |
| **No Values** | Stack is empty at end | `""` (empty) | `"Error"` |
| **Wrong Arguments** | argc != 2 | `./rpn` or `./rpn "a" "b"` | `"Error: Please provide..."` |

### Error Examples with Traces

#### Example 1: Stack Underflow

```
Input: "3 +"
Execution:
  Token "3": push 3 → stack = [3]
  Token "+": Check stack.size() >= 2? 1 >= 2? NO → ERROR
Output: "Error"
```

#### Example 2: Multiple Values

```
Input: "3 4"
Execution:
  Token "3": push 3 → stack = [3]
  Token "4": push 4 → stack = [3, 4]
  After all tokens: stack.size() = 2, not 1 → ERROR
Output: "Error"
```

#### Example 3: Division by Zero

```
Input: "5 0 /"
Execution:
  Token "5": push 5 → stack = [5]
  Token "0": push 0 → stack = [5, 0]
  Token "/": 
    pop val2 = 0
    pop val1 = 5
    Check: val2 == 0? YES → ERROR
Output: "Error: Division by zero."
```

#### Example 4: Invalid Token

```
Input: "3 4 abc"
Execution:
  Token "3": push 3 → stack = [3]
  Token "4": push 4 → stack = [3, 4]
  Token "abc": 
    Is digit? NO (length != 1)
    Is operator? NO
    → ERROR
Output: "Error"
```

## Worked Example: Complete Execution

### Input: `"3 4 + 2 * 7 /"`

This represents: `((3 + 4) * 2) / 7 = (7 * 2) / 7 = 14 / 7 = 2`

### Step-by-Step Execution

```
Initial state: stack = []

Token "3": Single digit
  → push 3
  → stack = [3]

Token "4": Single digit
  → push 4
  → stack = [3, 4]

Token "+": Operator
  → stack.size() = 2 >= 2 ✓
  → val2 = pop() = 4, stack = [3]
  → val1 = pop() = 3, stack = []
  → result = 3 + 4 = 7
  → push 7
  → stack = [7]

Token "2": Single digit
  → push 2
  → stack = [7, 2]

Token "*": Operator
  → stack.size() = 2 >= 2 ✓
  → val2 = pop() = 2, stack = [7]
  → val1 = pop() = 7, stack = []
  → result = 7 * 2 = 14
  → push 14
  → stack = [14]

Token "7": Single digit
  → push 7
  → stack = [14, 7]

Token "/": Operator
  → stack.size() = 2 >= 2 ✓
  → val2 = pop() = 7, stack = [14]
  → val1 = pop() = 14, stack = []
  → Check: val2 == 0? NO ✓
  → result = 14 / 7 = 2
  → push 2
  → stack = [2]

End of tokens: stack.size() = 1 ✓
Output: "2"
```

## Compilation and Execution

### Compilation

```bash
make
```

This compiles the program into executable `rpn`

### Execution Examples

```bash
# Simple addition
./rpn "3 4 +"
# Output: 7

# Complex expression
./rpn "8 9 * 9 - 9 - 9 - 4 - 1 +"
# Output: 42

# Error: not enough operands
./rpn "3 +"
# Output: Error

# Error: division by zero
./rpn "5 0 /"
# Output: Error: Division by zero.

# Error: too many values
./rpn "3 4"
# Output: Error
```

### Cleanup

```bash
make clean
```

## Key C++ Concepts Used

### 1. std::stack

```cpp
std::stack<int> _stack;

// Operations:
_stack.push(value);     // Add to top
int val = _stack.top(); // Access top without removing
_stack.pop();           // Remove top
size_t size = _stack.size();  // Number of elements
bool empty = _stack.empty();  // Check if empty
```

**Why stack?**
- LIFO (Last In, First Out) is perfect for RPN
- O(1) time complexity for all operations
- Simple and efficient

### 2. std::stringstream for Tokenization

```cpp
std::stringstream ss(expression);
std::string token;
while (ss >> token) {
  // Process each token
}
```

**Why stringstream?**
- Automatically handles whitespace separation
- Cleaner than manual string parsing
- Works with any whitespace (space, tab, newline, etc.)

### 3. Character Classification

```cpp
std::isdigit(token[0])  // Check if character is 0-9
token.length() == 1     // Ensure single digit only
```

### 4. Error Handling Patterns

```cpp
// Check precondition
if (condition_fails) {
  std::cerr << "Error message" << std::endl;
  return;  // Stop processing
}

// Process normally
normal_operation();
```

## Common Mistakes to Avoid

1. **Wrong operator order**: Popping in wrong order gives wrong result
   - Must pop right operand first, then left operand
   - `5 3 -` should give 2, not -2

2. **Forgetting stack validation**: Must check size before popping
   - Stack underflow crashes the program
   - Always verify `stack.size() >= 2` before operator

3. **Not checking final stack size**: Expression might be incomplete
   - `"3 4"` is invalid (no operator)
   - Check that exactly 1 element remains at end

4. **Accepting multi-digit numbers**: Only single digits allowed
   - `"12 3 +"` is invalid
   - Check `token.length() == 1`

5. **Forgetting division by zero check**: Will crash or give undefined behavior
   - Must explicitly check `val2 == 0` before division

6. **Not handling empty expression**: Empty input needs error handling
   - After all tokens processed, if stack is empty, that's an error

## Related C++ STL Concepts

- **std::queue**: FIFO alternative to stack
- **std::deque**: Double-ended queue (underlying for stack)
- **std::vector**: Resizable array (alternative implementation)
- **std::list**: Linked list (another stack implementation option)

## Related Algorithm Concepts

- **Stack-based evaluation**: Fundamental technique for expression evaluation
- **Infix to Postfix conversion**: Converting normal notation to RPN
- **Recursive descent parsing**: Alternative parsing approach
- **Tokenization**: Breaking strings into meaningful units
- **Finite state machine**: Classification of tokens is a simple FSM
