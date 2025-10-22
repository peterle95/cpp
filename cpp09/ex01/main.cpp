/*
** ============================================================================
** MAIN.CPP - Exercise 01: RPN Calculator
** ============================================================================
**
** PURPOSE:
** Entry point for the RPN (Reverse Polish Notation) calculator program.
** This file is responsible for:
** - Validating command-line arguments
** - Creating an RPN calculator instance
** - Executing the provided RPN expression
**
** PROGRAM FLOW:
** 1. Check that exactly one argument (RPN expression) is provided
** 2. Create an RPN object
** 3. Execute the expression and output result or error
**
** ============================================================================
*/

#include "RPN.hpp"
#include <iostream>    // For std::cerr (error output)

/*
** ============================================================================
** FUNCTION: main(int argc, char **argv)
** ============================================================================
**
** PARAMETERS:
** - argc: Argument count (number of command-line arguments)
**         argc = 1: program name only (missing expression)
**         argc = 2: program name + expression (correct)
**         argc > 2: program name + multiple arguments (too many)
**
** - argv: Argument vector (array of C-strings)
**         argv[0] = program name (e.g., "./rpn")
**         argv[1] = RPN expression (e.g., "3 4 +")
**
** RETURN VALUE:
** - 0 on successful evaluation (even if expression results in error)
** - 1 on invalid usage (wrong number of arguments)
**
** USAGE:
** ======
** ./rpn "<expression>"
**
** EXAMPLES:
** =========
** ./rpn "3 4 +"              → Output: 7
** ./rpn "8 9 * 9 - 9 - 9 - 4 - 1 +"  → Output: 42
** ./rpn "5 0 /"              → Error: Division by zero.
** ./rpn                      → Error: Wrong number of arguments
** ./rpn "3" "4"              → Error: Wrong number of arguments
**
** IMPORTANT NOTES:
** ================
** 1. The entire expression must be a SINGLE argument
**    Use quotes when running from shell: ./rpn "3 4 +"
**    Not: ./rpn 3 4 +  (this would be 4 arguments)
**
** 2. Tokens in the expression are whitespace-separated
**    Example: "3 4 +" has 3 tokens: "3", "4", "+"
**    Example: "3,4,+" would be interpreted as one token
**
** ============================================================================
**
** EXECUTION FLOW:
** ===============
**
** STEP 1: Validate argc
** ────────────────────
** Expected: argc == 2 (program name + expression)
** If argc != 2:
** ├─ Print usage error to stderr
** └─ Return 1 (error code)
**
** STEP 2: Create RPN object
** ─────────────────────────
** Instantiate an RPN calculator
** Stack-allocated (auto-destructs at end of main)
**
** STEP 3: Execute expression
** ──────────────────────────
** Call rpn.execute(argv[1])
** This processes the expression and outputs result or error
**
** STEP 4: Return success
** ──────────────────────
** Return 0 to OS
** (RPN object destructs here, cleaning up resources)
**
** ============================================================================
*/
int main(int argc, char **argv) {
	// STEP 1: Validate command-line arguments
	// Expected: exactly 2 arguments (program name + RPN expression)
	if (argc != 2) {
		std::cerr << "Error: Please provide an RPN expression as a single argument." << std::endl;
		return 1;  // Exit with error code
	}

	// STEP 2: Create RPN calculator object
	// This object handles all RPN evaluation logic
	RPN rpn;
	
	// STEP 3: Execute the RPN expression
	// argv[1] contains the RPN expression as a string
	// Output (result or error) goes to stdout/stderr
	rpn.execute(argv[1]);

	// STEP 4: Return success
	// Object rpn automatically destructs here, freeing all resources
	return 0;
}
