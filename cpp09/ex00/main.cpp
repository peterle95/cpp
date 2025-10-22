/*
** ============================================================================
** MAIN.CPP - Exercise 00: Bitcoin Exchange
** ============================================================================
**
** PURPOSE:
** Entry point for the Bitcoin Exchange program. This file is responsible for:
** - Validating command-line arguments
** - Creating and initializing a BitcoinExchange object
** - Loading the historical data
** - Processing user input file
**
** PROGRAM FLOW:
** 1. Check that exactly one argument (input filename) is provided
** 2. Create a BitcoinExchange instance
** 3. Load Bitcoin exchange rate data from data.csv
** 4. Process user input file to calculate Bitcoin values
**
** ============================================================================
*/

#include "BitcoinExchange.hpp"

/*
** ============================================================================
** FUNCTION: main(int argc, char **argv)
** ============================================================================
**
** PARAMETERS:
** - argc: Argument count (number of command-line arguments including program name)
** - argv: Argument vector (array of C-strings with command-line arguments)
**         argv[0] = program name (./btc)
**         argv[1] = input filename (e.g., input.txt)
**
** RETURN VALUE:
** - 0 on success
** - 1 on invalid usage (wrong number of arguments)
**
** USAGE:
** ./btc <filename>
**
** EXAMPLES:
** ./btc input.txt           (correct: processes Bitcoin values from input.txt)
** ./btc                     (error: missing filename argument)
** ./btc file1.txt file2.txt (error: too many arguments)
**
** EXECUTION FLOW:
** ================
** 1. Validate argc
**    - Expected: argc == 2 (program name + one filename)
**    - If not 2, print usage error and exit with code 1
**
** 2. Create BitcoinExchange object
**    - Stack-allocated object (will auto-destruct at end of main)
**    - Initializes with empty _data map
**
** 3. Load data from CSV
**    - Calls btc.readData()
**    - Loads historical Bitcoin rates from "data.csv"
**    - If file not found, prints error and continues with empty data
**
** 4. Process input file
**    - Calls btc.processInput(argv[1])
**    - Reads user input file specified as command-line argument
**    - For each line, calculates Bitcoin value and outputs result or error
**
** 5. Program termination
**    - Object destructs automatically
**    - Memory freed by std::map
**    - Returns 0 (success) to operating system
**
** ERROR HANDLING:
** ===============
** This file performs minimal error handling - only argument count validation.
** All other errors (file not found, bad input format, etc.) are handled
** within the BitcoinExchange class methods.
**
** ============================================================================
*/
int main(int argc, char **argv)
{
	// STEP 1: Validate command-line arguments
	// Expected: exactly 2 arguments (program name + input filename)
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return 1;  // Exit with error code
	}

	// STEP 2: Create BitcoinExchange object
	// This object will manage the data loading and input processing
	BitcoinExchange btc;
	
	// STEP 3: Load historical Bitcoin exchange rate data
	// Reads from "data.csv" and populates internal _data map
	btc.readData();
	
	// STEP 4: Process user input file
	// argv[1] is the filename passed as command-line argument
	// For each line: validate, calculate Bitcoin value, output result
	btc.processInput(argv[1]);

	// STEP 5: Return success
	// Object btc automatically destructs here, freeing all resources
	return 0;
}
