/*
** ============================================================================
** BITCOINEXCHANGE.HPP
** ============================================================================
** 
** PURPOSE:
** This header file defines the BitcoinExchange class, which is responsible
** for loading historical Bitcoin exchange rate data and processing user input
** to calculate Bitcoin value conversions.
**
** KEY COMPONENTS:
** - _data: A map that stores date-to-price mappings for Bitcoin exchange rates
** - readData(): Loads historical Bitcoin prices from a CSV file
** - processInput(): Reads a user input file and calculates Bitcoin conversions
**
** CLASS DESIGN NOTES:
** - Private copy constructor and assignment operator prevent unwanted copies
** - The class uses std::map for efficient date lookup and lower_bound operations
** - Single responsibility: manages Bitcoin exchange rate data and calculations
**
** ============================================================================
*/

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>    // For std::cerr and std::cout (error and output streams)
#include <string>      // For std::string (string manipulation)
#include <map>         // For std::map (key-value storage with sorted keys)
#include <fstream>     // For std::ifstream (file input stream)
#include <sstream>     // For std::stringstream (string stream for parsing)
#include <algorithm>   // For standard algorithms (included for completeness)

/*
** ============================================================================
** CLASS: BitcoinExchange
** ============================================================================
**
** RESPONSIBILITIES:
** 1. Load and store Bitcoin exchange rate data from a CSV file (data.csv)
** 2. Parse user input containing date and Bitcoin amount
** 3. Calculate the value of Bitcoin on specific dates using lower_bound lookup
**
** DESIGN PATTERN:
** This class follows the Oracle/Data Access Object pattern - it encapsulates
** all operations related to Bitcoin exchange rate data management.
**
** ============================================================================
*/
class BitcoinExchange
{
private:
	/*
	** ========================================================================
	** PRIVATE DATA MEMBERS
	** ========================================================================
	*/
	
	/* 
	** _data: The heart of the class - stores date-to-exchange-rate mappings
	** Key: date string in format "YYYY-MM-DD"
	** Value: float representing the BTC/USD exchange rate for that date
	** 
	** Why std::map?
	** - Keys are automatically sorted by date (lexicographically)
	** - Allows efficient lower_bound() search for "the closest date <= input date"
	** - Time complexity for lookups: O(log n)
	*/
	std::map<std::string, float> _data;
	
	/*
	** ========================================================================
	** PRIVATE METHODS (Copy Control)
	** ========================================================================
	*/
	
	/*
	** Copy constructor (declared but not implemented)
	** Prevents creating copies of BitcoinExchange objects
	** Reason: We want only one instance managing the data to avoid duplication
	*/
	BitcoinExchange(const BitcoinExchange &other);
	
	/*
	** Assignment operator (declared but not implemented)
	** Prevents assignment of BitcoinExchange objects
	** Reason: We want to prevent overwriting existing instances
	*/
	BitcoinExchange &operator=(const BitcoinExchange &other);

public:
	/*
	** ========================================================================
	** PUBLIC METHODS (User Interface)
	** ========================================================================
	*/
	
	/*
	** Default Constructor
	** Initializes an empty BitcoinExchange object
	** The _data map is empty until readData() is called
	*/
	BitcoinExchange();
	
	/*
	** Destructor
	** Cleans up resources (std::map automatically handles memory)
	*/
	~BitcoinExchange();

	/*
	** readData()
	** - Opens and reads the "data.csv" file
	** - Parses each line into date and price pairs
	** - Populates the _data map with historical exchange rates
	** - Skips the first line (header: "date,exchange_rate")
	** 
	** FILE FORMAT EXPECTED:
	** date,exchange_rate
	** 2009-01-02,13.7513
	** 2009-01-03,770.0
	** ... (more lines)
	** 
	** ERROR HANDLING:
	** - If file cannot be opened, prints error message to stderr and returns
	** - No exceptions thrown; class continues with empty data if file fails
	*/
	void readData();
	
	/*
	** processInput(const std::string &filename)
	** - Opens and processes user input file
	** - Expects each line: DATE | AMOUNT (e.g., "2011-01-03 | 3")
	** - Validates date format and amount range (0 to 1000)
	** - Uses _data map to find the exchange rate for the given date
	** - Outputs the calculation result or an error message
	** 
	** LOOKUP ALGORITHM (via lower_bound):
	** 1. If exact date exists in _data, use that rate
	** 2. If exact date doesn't exist, use the closest earlier date's rate
	** 3. If no earlier date exists, output an error
	** 
	** VALIDATION RULES:
	** - Date must be in format YYYY-MM-DD
	** - Date must be >= 2009-01-02 (earliest Bitcoin data)
	** - Amount must be >= 0 (non-negative)
	** - Amount must be <= 1000 (too large check)
	** - Line must have exactly: date | amount (no extra data)
	** 
	** ERROR MESSAGES:
	** - "Error: bad input => ..." (invalid date or format)
	** - "Error: not a positive number." (negative amount)
	** - "Error: too large a number." (amount > 1000)
	** - "Error: no data available for date X or earlier." (date too old)
	*/
	void processInput(const std::string &filename);
};

#endif
