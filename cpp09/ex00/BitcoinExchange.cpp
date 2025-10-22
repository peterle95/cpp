/*
** ============================================================================
** BITCOINEXCHANGE.CPP
** ============================================================================
**
** IMPLEMENTATION DETAILS:
** This file implements the BitcoinExchange class methods, handling:
** 1. Loading historical Bitcoin data from CSV
** 2. Validating user input (dates, amounts, format)
** 3. Looking up exchange rates for specific dates
** 4. Computing and outputting Bitcoin value conversions
**
** KEY ALGORITHMS:
** - Date validation with leap year calculation
** - std::map::lower_bound() for efficient date lookups
** - String parsing with std::stringstream
**
** ============================================================================
*/

#include "BitcoinExchange.hpp"
#include <cstdlib>     // For std::atoi (string to int conversion)

/*
** ============================================================================
** CONSTRUCTORS AND DESTRUCTORS
** ============================================================================
*/

/*
** Default Constructor: BitcoinExchange()
** Initializes the BitcoinExchange object with an empty _data map.
** No special initialization needed - std::map constructor handles this.
*/
BitcoinExchange::BitcoinExchange() {}

/*
** Destructor: ~BitcoinExchange()
** Cleans up resources. Since we use std::map which manages its own memory,
** no explicit cleanup is necessary.
*/
BitcoinExchange::~BitcoinExchange() {}

/*
** ============================================================================
** HELPER FUNCTION: isValidDate()
** ============================================================================
**
** PURPOSE: Validates that a date string is in correct format and represents
**          a valid calendar date from 2009 onwards.
**
** PARAMETERS:
** - date: Reference to a string to validate (format: "YYYY-MM-DD")
**
** RETURNS: true if date is valid, false otherwise
**
** VALIDATION STEPS:
** 1. Length check: Must be exactly 10 characters (YYYY-MM-DD)
** 2. Format check: Hyphens must be at positions 4 and 7
** 3. Digit check: Characters at positions 0,1,2,3,5,6,8,9 must be digits
** 4. Range validation:
**    - Year >= 2009 (Bitcoin started in 2009)
**    - Month: 1-12
**    - Day: 1-31 (with special handling per month)
** 5. Leap year handling:
**    - February in leap years: max 29 days
**    - February in non-leap years: max 28 days
**    - Other months: 30 or 31 as appropriate
**
** EXAMPLE VALID DATES:
** - "2009-01-02" (Bitcoin's first transaction)
** - "2011-06-15"
** - "2024-12-31"
**
** EXAMPLE INVALID DATES:
** - "2008-12-31" (Before Bitcoin era)
** - "2024-02-30" (Feb doesn't have 30 days)
** - "2024-13-01" (Invalid month)
**
** ============================================================================
*/
bool isValidDate(const std::string &date)
{
	// Step 1: Check exact length
	if (date.length() != 10)
		return false;
	
	// Step 2: Check hyphen positions (YYYY-MM-DD format)
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	// Step 3: Check that all other characters are digits
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)  // Skip the hyphen positions
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	
	// Step 4: Extract year, month, and day as integers
	// Substring positions: [0,4) = year, [5,7) = month, [8,10) = day
	int year, month, day;
	std::stringstream ss_year(date.substr(0, 4));
	ss_year >> year;
	std::stringstream ss_month(date.substr(5, 2));
	ss_month >> month;
	std::stringstream ss_day(date.substr(8, 2));
	ss_day >> day;

	// Step 5: Validate year (2009 or later), month (1-12), day (1-31)
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	
	// Step 6: Special handling for February - check leap year and day validity
	if (month == 2) 
	{
		// Leap year calculation:
		// - Divisible by 4 AND not by 100 OR divisible by 400
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (isLeap && day > 29) 
			return false;
		if (!isLeap && day > 28) 
			return false;
	}
	
	// Step 7: Validate days for months with only 30 days
	// Months: April (4), June (6), September (9), November (11)
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	
	// All checks passed
	return true;
}

/*
** ============================================================================
** METHOD: readData()
** ============================================================================
**
** PURPOSE: Loads historical Bitcoin exchange rate data from "data.csv"
**          and populates the _data map for later lookups.
**
** ALGORITHM:
** 1. Open the file "data.csv" in the current directory
** 2. If file doesn't exist or can't be opened, print error and return
** 3. Skip the first line (CSV header: "date,exchange_rate")
** 4. For each subsequent line:
**    a. Extract the date (YYYY-MM-DD)
**    b. Extract the exchange rate (float value)
**    c. Store in _data map: _data[date] = price
** 5. File automatically closes when ifstream goes out of scope
**
** FILE FORMAT EXAMPLE:
** date,exchange_rate
** 2009-01-02,13.7513
** 2009-01-03,770.0
** 2009-01-04,770.0
** ...
** 2024-01-01,42000.50
**
** DATA STRUCTURE AFTER LOADING:
** _data = {
**   "2009-01-02" -> 13.7513,
**   "2009-01-03" -> 770.0,
**   "2009-01-04" -> 770.0,
**   ...
** }
**
** NOTE: Keys are automatically sorted by date (lexicographical order).
**       Since dates are YYYY-MM-DD format, lexicographical = chronological.
**
** ERROR HANDLING:
** - Silent failure if file not found (prints error to cerr)
** - Assumes well-formed CSV input (no parsing error handling)
** - All prices converted to float, invalid numbers become 0.0
**
** ============================================================================
*/
void BitcoinExchange::readData()
{
	// Open the data file for reading
	std::ifstream file("data.csv");
	
	// Check if file opened successfully
	if (!file.is_open())
	{
		std::cerr << "Error: could not open data file." << std::endl;
		return;
	}

	std::string line;
	
	// Skip the first line (header: "date,exchange_rate")
	std::getline(file, line);
	
	// Read all subsequent lines
	while (std::getline(file, line))
	{
		// Create a string stream from the current line
		std::stringstream ss(line);
		
		std::string date;
		std::string value;
		
		// Extract date up to the comma
		std::getline(ss, date, ',');
		
		// Extract value after the comma
		std::getline(ss, value, ',');
		
		// Convert the value string to a float
		std::stringstream converter(value);
		float price;
		converter >> price;
		
		// Store the date-price pair in the map
		// Map key: date string (automatically sorted)
		// Map value: exchange rate as float
		_data[date] = price;
	}
	// File automatically closes here
}

/*
** ============================================================================
** METHOD: processInput(const std::string &filename)
** ============================================================================
**
** PURPOSE: Reads user input file and calculates Bitcoin values for each entry,
**          using the loaded exchange rate data.
**
** FILE FORMAT EXPECTED:
** date | amount
** 2011-01-03 | 3
** 2011-01-03 | 2.1
** 2012-06-15 | 1.2
** ...
**
** ALGORITHM:
** 1. Open the input file
** 2. Skip the header line
** 3. For each subsequent line:
**    a. Parse date, separator, and amount
**    b. Validate all three components
**    c. Look up exchange rate for that date (or nearest earlier date)
**    d. Calculate: result = amount × exchange_rate
**    e. Output: "date => amount = result"
**    f. If any validation fails, output specific error and continue
**
** KEY LOOKUP ALGORITHM (using std::map::lower_bound):
** =========================================
** lower_bound(date) returns an iterator to the first element with key >= date.
**
** Case 1: Exact date exists in map
**   - lower_bound returns iterator to that element
**   - Use that date's exchange rate
**
** Case 2: Exact date doesn't exist, but earlier dates do
**   - lower_bound returns iterator to the first date > requested date
**   - Decrement the iterator to get the closest earlier date
**   - Use that date's exchange rate
**
** Case 3: No date earlier than requested date exists
**   - lower_bound returns iterator to first element
**   - It->first (first date in map) is > requested date
**   - Cannot decrement: this is an error
**   - Output: "Error: no data available for date X or earlier."
**
** Case 4: Map is empty
**   - lower_bound returns end()
**   - Cannot process: return with error
**
** EXAMPLE LOOKUP WALKTHROUGH:
** Given _data = {"2009-01-02" -> 100, "2009-01-03" -> 200, "2009-01-05" -> 300}
**
** Request: "2009-01-03"
**   lower_bound("2009-01-03") returns iterator to "2009-01-03"
**   Use rate: 200
**
** Request: "2009-01-04"
**   lower_bound("2009-01-04") returns iterator to "2009-01-05"
**   Decrement iterator to get "2009-01-03"
**   Use rate: 200 (closest earlier date)
**
** Request: "2009-01-01"
**   lower_bound("2009-01-01") returns iterator to "2009-01-02"
**   It->first ("2009-01-02") > requested date
**   We're at begin(), can't decrement
**   ERROR: no data available for this date or earlier
**
** VALIDATION RULES:
** ==================
** 1. Line format: exactly "DATE | AMOUNT" (separator is '|')
** 2. No extra characters before, after, or between components
** 3. Date must pass isValidDate() check
** 4. Amount must be >= 0 (non-negative)
** 5. Amount must be <= 1000 (reasonable upper limit)
** 6. Date must have Bitcoin data available (>= 2009-01-02)
**
** ERROR MESSAGES:
** ===============
** - "Error: bad input => ..." (invalid date format or missing separator)
** - "Error: not a positive number." (amount < 0)
** - "Error: too large a number." (amount > 1000)
** - "Error: no data available for date X or earlier." (date before first data)
**
** ============================================================================
*/
void BitcoinExchange::processInput(const std::string &filename)
{
	// Open the input file for reading
	std::ifstream file(filename.c_str());
	
	// Check if file opened successfully
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	
	// Skip the first line (header)
	std::getline(file, line);

	// Process each line in the file
	while (std::getline(file, line))
	{
		// Create a stringstream to parse the line
		std::stringstream ss(line);
		
		std::string date;
		char separator;
		float value;

		/*
		** PARSING THE LINE:
		** Uses stringstream's extraction operator (>>)
		** This automatically handles whitespace trimming
		** 
		** Expected format: "date | amount"
		** Example: "2011-01-03 | 3.5"
		** 
		** ss >> date >> separator >> value extracts:
		** - date: string until whitespace
		** - separator: single character (should be '|')
		** - value: float number
		**
		** If parsing fails (returns false), the line is malformed
		*/
		if (!(ss >> date >> separator >> value) || separator != '|')
		{
			/*
			** SPECIAL ERROR HANDLING:
			** Try to extract just the date to give more specific error message
			** If the bad part is actually a bad date, report the date
			** Otherwise, report the whole line
			*/
			std::stringstream error_ss(line);
			std::string error_token;
			error_ss >> error_token;
			if (!isValidDate(error_token)) {
				std::cerr << "Error: bad input => " << error_token << std::endl;
			} else {
				std::cerr << "Error: bad input => " << line << std::endl;
			}
			continue;  // Skip to next line
		}

		/*
		** CHECK FOR EXTRA DATA:
		** After parsing date, separator, and value,
		** there should be no remaining tokens on the line
		** If there are, it's malformed input
		*/
		std::string remainder;
		if (ss >> remainder) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;  // Skip to next line
		}

		/*
		** VALIDATE DATE FORMAT AND RANGE:
		** Checks if date is properly formatted and within valid range
		** (YYYY-MM-DD, year >= 2009)
		*/
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;  // Skip to next line
		}

		/*
		** VALIDATE AMOUNT IS NON-NEGATIVE:
		** Bitcoin amounts cannot be negative
		*/
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;  // Skip to next line
		}

		/*
		** VALIDATE AMOUNT IS NOT TOO LARGE:
		** Reject amounts greater than 1000 BTC
		** This is a reasonable sanity check
		*/
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;  // Skip to next line
		}

		/*
		** ================================================================
		** KEY LOOKUP: Find the exchange rate for this date
		** ================================================================
		** 
		** USE: std::map::lower_bound(date)
		** 
		** This returns an iterator to the first element with key >= date
		** If exact date exists, returns iterator to that element
		** If no exact date, returns iterator to first element > date
		** If no element >= date, returns end() iterator
		*/
		std::map<std::string, float>::iterator it = _data.lower_bound(date);

		/*
		** CASE: No data available for date or any earlier date
		** This happens when lower_bound returns begin() iterator
		** and the first element's date is > requested date
		** (meaning requested date is before all available data)
		*/
		if (it == _data.begin() && it->first > date)
		{
			std::cerr << "Error: no data available for date " << date << " or earlier." << std::endl;
			continue;  // Skip to next line
		}

		/*
		** CASE: Exact date not found, or date is past all available data
		** If it == end(), no element >= date exists (use last element)
		** If it != end() but it->first != date, exact date not found
		** In both cases: use the closest earlier date (decrement iterator)
		*/
		if (it == _data.end() || it->first != date)
		{
			--it;  // Move to previous element (guaranteed to be valid due to earlier check)
		}
		
		/*
		** NOW: it points to the exchange rate to use
		** it->first is the date (for output)
		** it->second is the exchange rate for that date
		**
		** CALCULATION: BTC value = amount × exchange_rate
		** OUTPUT FORMAT: "input_date => amount = total_value"
		**
		** EXAMPLE:
		** Input: "2011-01-03 | 3"
		** If 2011-01-03 rate is 30, and no exact match:
		** Find closest earlier date (e.g., 2011-01-02 with rate 30)
		** Output: "2011-01-03 => 3 = 90"
		*/
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
	// File automatically closes here
}
