/*
** ============================================================================
** RPN.CPP - Reverse Polish Notation Calculator Implementation
** ============================================================================
**
** CONTAINS:
** - RPN constructor and destructor
** - execute() method: core RPN evaluation algorithm
**
** KEY COMPONENTS:
** 1. Parsing: Extract tokens from input string using stringstream
** 2. Token classification: Determine if token is digit, operator, or invalid
** 3. Stack operations: Push operands, pop for operators, push results
** 4. Validation: Check stack state for errors
**
** ============================================================================
*/

#include "RPN.hpp"
#include <iostream>    // For std::cout, std::cerr
#include <sstream>     // For std::stringstream (tokenization)
#include <cstdlib>     // For std::atoi (string to int conversion)

/*
** ============================================================================
** CONSTRUCTORS AND DESTRUCTORS
** ============================================================================
*/

/*
** Default Constructor: RPN()
** Initializes an RPN calculator with an empty stack
** Ready to evaluate expressions
*/
RPN::RPN() {}

/*
** Destructor: ~RPN()
** Cleans up resources. The stack automatically manages its own memory.
*/
RPN::~RPN() {}

/*
** ============================================================================
** METHOD: execute(const std::string& expression)
** ============================================================================
**
** PURPOSE:
** Evaluates a mathematical expression in Reverse Polish Notation (RPN/postfix)
** and outputs the result or an error message.
**
** PARAMETERS:
** - expression: A string containing the RPN expression
**   Format: tokens separated by whitespace
**   Tokens: single digits (0-9) or operators (+, -, *, /)
**   Example: "3 4 +"
**   Example: "8 9 * 9 - 9 - 9 - 4 - 1 +"
**
** RETURN: void
** Outputs to stdout (result) or stderr (error)
**
** ============================================================================
**
** ALGORITHM WALKTHROUGH:
** ======================
**
** STEP 1: Initialize Parsing
** ───────────────────────────
*/
void RPN::execute(const std::string& expression) {
	// Create a stringstream from the input expression
	// This allows us to extract tokens word-by-word
	std::stringstream ss(expression);
	std::string token;

	/*
	** STEP 2: Process Each Token
	** ───────────────────────────
	** ss >> token extracts whitespace-separated tokens one by one
	** Continue until no more tokens available
	**
	** Each iteration processes one token which is either:
	** - A digit (0-9): an operand to push on stack
	** - An operator (+, -, *, /): operation to perform
	** - Anything else: an error
	*/
	while (ss >> token) {
		
		/*
		** TOKEN TYPE 1: SINGLE DIGIT
		** ==========================
		** Check if token is a single character and that character is a digit
		**
		** token.length() == 1: Ensure exactly one character
		** std::isdigit(token[0]): Check if that character is 0-9
		**
		** Example: "5" → length=1, isdigit('5')=true → push 5
		**          "42" → length=2 → not single digit, would be invalid
		**          "a" → isdigit('a')=false → not a digit
		*/
		if (token.length() == 1 && std::isdigit(token[0])) {
			// Convert single-character string to integer
			// std::atoi("5") → 5
			_stack.push(std::atoi(token.c_str()));
		}
		/*
		** TOKEN TYPE 2: OPERATOR
		** ======================
		** Check if token is one of the four operators: +, -, *, /
		**
		** RPN Operator Processing:
		** 1. Verify stack has at least 2 elements
		** 2. Pop the right operand (second value popped)
		** 3. Pop the left operand (first value popped)
		** 4. Compute: result = left_operand OP right_operand
		** 5. Push result back onto stack
		**
		** Why pop right first, then left?
		** - Stack is LIFO (Last In, First Out)
		** - Most recently pushed value is at top
		** - For "3 4 -": 3 is pushed first (below), 4 second (on top)
		** - When we pop: first pop gets 4 (val2), second pop gets 3 (val1)
		** - We compute: val1 - val2 = 3 - 4 = -1
		** - This is the correct interpretation of "3 4 -"
		**
		** OPERATOR ORDER MATTERS:
		** For subtraction and division, operand order is critical
		** "5 3 -" should give 5-3=2 (not 3-5=-2)
		** "8 2 /" should give 8/2=4 (not 2/8=0)
		*/
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
			
			/*
			** VALIDATION: Check stack has at least 2 elements
			** If not enough operands, this is a malformed expression
			** 
			** Example error case: "3 +"
			** - Push 3: stack = [3]
			** - See +: need 2 operands, only have 1
			** - Stack size (1) < 2, so this is an error
			*/
			if (_stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				return;  // Stop processing and exit
			}
			
			/*
			** POP OPERANDS IN CORRECT ORDER
			** ==============================
			** 
			** val2 = pop() first (the right operand, on top of stack)
			** val1 = pop() second (the left operand, underneath)
			**
			** Stack state before pops:
			** [... val1, val2]
			**        ↑    ↑
			**       bottom top
			**
			** After val2 = _stack.top() and pop():
			** [... val1]
			**
			** After val1 = _stack.top() and pop():
			** [...]
			*/
			int val2 = _stack.top();  // Get the top element (right operand)
			_stack.pop();             // Remove it from stack
			int val1 = _stack.top();  // Get new top element (left operand)
			_stack.pop();             // Remove it from stack

			/*
			** PERFORM OPERATION AND PUSH RESULT
			** ==================================
			** Based on the operator, compute result = val1 OP val2
			** Then push the result back onto stack
			**
			** Key insight: Only operations that support the integer type
			** are implemented. Floating point would require different design.
			*/
			if (token == "+") 
				_stack.push(val1 + val2);
			else if (token == "-") 
				_stack.push(val1 - val2);
			else if (token == "*") 
				_stack.push(val1 * val2);
			else if (token == "/") {
				/*
				** DIVISION SPECIAL CASE: Check for division by zero
				** If right operand (divisor) is 0, this is undefined
				** Report error and stop processing
				*/
				if (val2 == 0) {
					std::cerr << "Error: Division by zero." << std::endl;
					return;
				}
				_stack.push(val1 / val2);
			}
		}
		/*
		** TOKEN TYPE 3: INVALID TOKEN
		** ============================
		** If token is not a digit and not an operator, it's invalid
		** Examples: "a", "&&", "abc", "12"(multi-digit), etc.
		**
		** This represents a malformed expression
		** Report error and stop processing
		*/
		else {
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	/*
	** STEP 3: Validation After Processing All Tokens
	** ===============================================
	** A correctly formed RPN expression leaves exactly ONE value on the stack
	** This value is the result of the entire expression
	**
	** If stack has more or fewer than 1 element, the expression is malformed:
	** 
	** Case 1: Stack size = 0
	** Example: "" (empty expression)
	** Problem: No result to output
	** Solution: Report error
	**
	** Case 2: Stack size > 1
	** Example: "3 4" (missing operator)
	** Stack state: [3, 4] (two values)
	** Problem: Multiple values, which one is the result?
	** Solution: Report error
	**
	** Case 3: Stack size = 1 ✓
	** Example: "3 4 +"
	** Stack state: [7] (one value)
	** Problem: None - this is correct!
	** Solution: Output the result
	*/
	if (_stack.size() == 1) {
		// Exactly one element on stack - this is the result
		std::cout << _stack.top() << std::endl;
	} else {
		// Either no elements or multiple elements - both are errors
		std::cerr << "Error" << std::endl;
	}
}

/*
** ============================================================================
** DETAILED EXECUTION EXAMPLES
** ============================================================================
**
** EXAMPLE 1: Simple Addition
** ==========================
** Input: "3 4 +"
** 
** Initial: stack = []
** 
** Token 1: "3"
** ├─ Is digit? Yes
** ├─ Action: push 3
** └─ stack = [3]
**
** Token 2: "4"
** ├─ Is digit? Yes
** ├─ Action: push 4
** └─ stack = [3, 4]
**
** Token 3: "+"
** ├─ Is operator? Yes
** ├─ Stack size check: 2 >= 2? Yes
** ├─ Pop: val2 = 4, stack = [3]
** ├─ Pop: val1 = 3, stack = []
** ├─ Compute: 3 + 4 = 7
** ├─ Push: 7
** └─ stack = [7]
**
** End of tokens: stack.size() = 1
** Output: "7"
**
** ──────────────────────────────────────────────────────────────────────────
**
** EXAMPLE 2: Complex Expression
** ==============================
** Input: "8 9 * 9 - 9 - 9 - 4 - 1 +"
** 
** Token "8": push 8                      → stack = [8]
** Token "9": push 9                      → stack = [8, 9]
** Token "*": pop 9, pop 8, 8*9=72, push → stack = [72]
** Token "9": push 9                      → stack = [72, 9]
** Token "-": pop 9, pop 72, 72-9=63     → stack = [63]
** Token "9": push 9                      → stack = [63, 9]
** Token "-": pop 9, pop 63, 63-9=54     → stack = [54]
** Token "9": push 9                      → stack = [54, 9]
** Token "-": pop 9, pop 54, 54-9=45     → stack = [45]
** Token "4": push 4                      → stack = [45, 4]
** Token "-": pop 4, pop 45, 45-4=41     → stack = [41]
** Token "1": push 1                      → stack = [41, 1]
** Token "+": pop 1, pop 41, 41+1=42     → stack = [42]
** 
** End: stack.size() = 1
** Output: "42"
**
** ──────────────────────────────────────────────────────────────────────────
**
** EXAMPLE 3: Error - Stack Underflow
** ==================================
** Input: "3 4 + 5 -"
** 
** Token "3": push 3              → stack = [3]
** Token "4": push 4              → stack = [3, 4]
** Token "+": pop 4, pop 3, push 7 → stack = [7]
** Token "5": push 5              → stack = [7, 5]
** Token "-": pop 5, pop 7, 7-5=2 → stack = [2]
** 
** End: stack.size() = 1
** Output: "2"  ✓ This is actually valid!
**
** ──────────────────────────────────────────────────────────────────────────
**
** EXAMPLE 4: Error - Insufficient Operands
** ========================================
** Input: "3 +"
** 
** Token "3": push 3        → stack = [3]
** Token "+": 
** ├─ Is operator? Yes
** ├─ Stack size check: 1 >= 2? NO
** ├─ Action: Print error and return
** └─ Output: "Error"
**
** ──────────────────────────────────────────────────────────────────────────
**
** EXAMPLE 5: Error - Multiple Values Remain
** =========================================
** Input: "3 4"
** 
** Token "3": push 3        → stack = [3]
** Token "4": push 4        → stack = [3, 4]
** 
** End of tokens: stack.size() = 2
** End check: 2 == 1? NO
** Output: "Error"
**
** ──────────────────────────────────────────────────────────────────────────
**
** EXAMPLE 6: Error - Division by Zero
** ===================================
** Input: "5 0 /"
** 
** Token "5": push 5        → stack = [5]
** Token "0": push 0        → stack = [5, 0]
** Token "/":
** ├─ Is operator? Yes
** ├─ Stack size check: 2 >= 2? Yes
** ├─ Pop: val2 = 0, stack = [5]
** ├─ Pop: val1 = 5, stack = []
** ├─ Divide: val2 == 0? YES
** ├─ Action: Print error and return
** └─ Output: "Error: Division by zero."
**
** ══════════════════════════════════════════════════════════════════════════
*/
