/*
** ============================================================================
** RPN.HPP - Reverse Polish Notation Calculator Header
** ============================================================================
**
** PURPOSE:
** This header file defines the RPN (Reverse Polish Notation) class, which
** evaluates mathematical expressions written in postfix notation using a
** stack-based algorithm.
**
** WHAT IS RPN?
** Reverse Polish Notation (also called Postfix Notation) is a mathematical
** notation where operators follow their operands, rather than appearing
** between them (infix notation).
**
** EXAMPLES:
** =========
** Infix (normal):          Postfix (RPN):
** 3 + 4                    3 4 +
** (3 + 4) * 5              3 4 + 5 *
** 8 9 * 9 - 9 - 9 - 4 - 1 +   (this is pure postfix)
**
** WHY RPN?
** - Simple to evaluate with a stack
** - No need for parentheses or operator precedence rules
** - Commonly used in calculators and compilers
** - Unambiguous evaluation order
**
** ============================================================================
*/

#ifndef RPN_HPP
# define RPN_HPP

#include <string>      // For std::string (token storage)
#include <stack>       // For std::stack (main data structure for RPN)

/*
** ============================================================================
** CLASS: RPN
** ============================================================================
**
** RESPONSIBILITY:
** Evaluate mathematical expressions in Reverse Polish Notation (postfix)
** and output the result.
**
** ALGORITHM OVERVIEW (for method execute):
** ==========================================
** 1. Initialize an empty stack
** 2. Parse the input expression into tokens (whitespace-separated)
** 3. For each token:
**    a. If token is a digit: push onto stack
**    b. If token is an operator (+, -, *, /):
**       - Pop two operands from stack (right operand first, then left)
**       - Perform operation: left OP right
**       - Push result back onto stack
**    c. If token is invalid: error
** 4. After processing all tokens:
**    - Stack should contain exactly 1 element (the result)
**    - Output that element
**    - If stack size != 1, it's an error (incomplete or malformed expression)
**
** DESIGN NOTES:
** - Private copy constructor and assignment operator prevent copies
** - Simple state: just a stack of integers
** - Single responsibility: evaluate RPN expressions
**
** ============================================================================
*/
class RPN {
private:
	/*
	** ========================================================================
	** PRIVATE DATA MEMBERS
	** ========================================================================
	*/
	
	/*
	** _stack: The core data structure for RPN evaluation
	** Type: std::stack<int>
	** 
	** Stack holds:
	** - Intermediate operands during evaluation
	** - Final result (should be exactly one element at the end)
	**
	** Stack properties:
	** - LIFO (Last In, First Out) - perfect for RPN evaluation
	** - push() - add element to top
	** - pop() - remove element from top
	** - top() - access top element without removing
	** - size() - number of elements
	** - empty() - check if empty
	**
	** Example during "3 4 +"evaluation:
	** Input: "3 4 +"
	** 1. See 3: push 3 → stack = [3]
	** 2. See 4: push 4 → stack = [3, 4]
	** 3. See +: pop 4, pop 3, compute 3+4=7, push 7 → stack = [7]
	** 4. Done: stack has 1 element, output 7
	*/
	std::stack<int> _stack;
	
	/*
	** ========================================================================
	** PRIVATE METHODS (Copy Control)
	** ========================================================================
	*/
	
	/*
	** Copy constructor (declared but not implemented)
	** Prevents creating copies of RPN objects
	** Reason: Each RPN instance should be independent;
	**         copying would share the same stack which is confusing
	*/
	RPN(const RPN& other);
	
	/*
	** Assignment operator (declared but not implemented)
	** Prevents assignment of RPN objects
	** Reason: Prevents accidentally copying one calculator's state to another
	*/
	RPN& operator=(const RPN& other);

public:
	/*
	** ========================================================================
	** PUBLIC METHODS (User Interface)
	** ========================================================================
	*/
	
	/*
	** Default Constructor
	** Initializes the RPN object with an empty stack
	** Ready to evaluate expressions
	*/
	RPN();
	
	/*
	** Destructor
	** Cleans up resources (stack automatically handles memory)
	*/
	~RPN();

	/*
	** execute(const std::string& expression)
	** Evaluates a mathematical expression written in RPN (postfix notation)
	**
	** PARAMETERS:
	** - expression: A string containing RPN expression
	**   Format: whitespace-separated tokens
	**   Example: "3 4 +"
	**   Example: "8 9 * 9 - 9 - 9 - 4 - 1 +"
	**
	** ALGORITHM:
	** ==========
	** 1. Create a stringstream from the expression for token extraction
	** 2. Extract tokens one by one (whitespace-separated)
	** 3. For each token:
	**    
	**    IF token is a single digit (0-9):
	**    ├── Convert string digit to integer
	**    └── Push onto stack
	**    
	**    ELSE IF token is an operator (+, -, *, /):
	**    ├── Check stack has at least 2 elements
	**    ├── Pop right operand: val2 = stack.pop()
	**    ├── Pop left operand: val1 = stack.pop()
	**    ├── Compute: result = val1 OP val2
	**    │   (Note: order matters for - and /)
	**    └── Push result back onto stack
	**    
	**    ELSE:
	**    └── Invalid token, error
	**
	** 4. After processing all tokens:
	**    ├── Check stack size == 1 (exactly one element)
	**    ├── Output the top element
	**    └── If size != 1, error (malformed expression)
	**
	** VALIDATION RULES:
	** =================
	** - Each operator must have exactly 2 operands available
	** - Final stack must contain exactly 1 element
	** - Operators supported: +, -, *, /
	** - Division by zero is checked and reported as error
	** - Only single digits (0-9) are accepted as operands
	**
	** OUTPUT:
	** =======
	** - Success: Prints the result to stdout
	** - Error: Prints "Error" or "Error: <details>" to stderr
	**
	** EXAMPLES:
	** =========
	** Input: "3 4 +"
	** Process:
	**   - Push 3
	**   - Push 4
	**   - Op +: pop 4, pop 3, compute 3+4=7, push 7
	**   - Stack size = 1, output 7
	** Output: "7"
	**
	** Input: "8 9 * 9 - 9 - 9 - 4 - 1 +"
	** Process:
	**   - Push 8: [8]
	**   - Push 9: [8, 9]
	**   - Op *: pop 9, pop 8, 8*9=72, push 72: [72]
	**   - Push 9: [72, 9]
	**   - Op -: pop 9, pop 72, 72-9=63, push 63: [63]
	**   - Push 9: [63, 9]
	**   - Op -: pop 9, pop 63, 63-9=54, push 54: [54]
	**   - ... continue ...
	**   - Stack size = 1, output final result
	**
	** ERROR CASES:
	** ============
	** 1. Stack underflow (not enough operands for operator):
	**    Input: "3 +"
	**    - Push 3: [3]
	**    - Op +: need 2 operands, only have 1
	**    Output: "Error"
	**
	** 2. Multiple values remain (incomplete operation):
	**    Input: "3 4"
	**    - Push 3: [3]
	**    - Push 4: [3, 4]
	**    - End of input, stack size = 2 (should be 1)
	**    Output: "Error"
	**
	** 3. Division by zero:
	**    Input: "5 0 /"
	**    - Push 5: [5]
	**    - Push 0: [5, 0]
	**    - Op /: pop 0, pop 5, 5/0
	**    Output: "Error: Division by zero."
	**
	** 4. Invalid token:
	**    Input: "3 4 &"
	**    - Push 3, push 4
	**    - See &: not a digit, not valid operator
	**    Output: "Error"
	*/
	void execute(const std::string& expression);
};

#endif
