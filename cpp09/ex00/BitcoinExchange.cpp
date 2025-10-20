#include "BitcoinExchange.hpp"
#include <cstdlib>

/*
 * DEFAULT CONSTRUCTOR
 * 
 * Purpose: Initialize a BitcoinExchange object with an empty dataset.
 * 
 * Logic: The constructor performs no explicit initialization since the member
 * variable _data (a std::map) is automatically initialized as an empty container.
 * This follows the C++98 idiom where STL containers self-initialize when objects
 * are constructed. The map will be populated later by the readData() function.
 */
BitcoinExchange::BitcoinExchange() {}

/*
 * DESTRUCTOR
 * 
 * Purpose: Clean up resources when a BitcoinExchange object is destroyed.
 * 
 * Logic: The destructor is empty because the only member variable is a std::map,
 * which automatically manages its own memory and resources. When the map goes out
 * of scope, it automatically deallocates all stored elements. This demonstrates
 * the RAII (Resource Acquisition Is Initialization) principle in C++.
 */
BitcoinExchange::~BitcoinExchange() {}

/*
 * READ DATA
 * 
 * Purpose: Load historical Bitcoin price data from a CSV file into the internal map.
 * 
 * Logic: This function opens the "data.csv" file, skips the header line, and then
 * reads each subsequent line as a date-price pair. The date serves as the key and
 * the price as the value in the _data map. The map is automatically sorted by date
 * (lexicographically, which works for YYYY-MM-DD format), allowing efficient lookup
 * and range queries later. If the file cannot be opened, an error message is printed
 * and the function returns early. The function uses stringstream for robust parsing
 * of the comma-separated values.
 * 
 * Data Structure Benefit: Using a map keeps the data sorted, which is crucial for
 * the lower_bound() operation used in processInput() to find the nearest date.
 */
void BitcoinExchange::readData()
{
	// Attempt to open the data file. The file should be in the working directory.
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open data file." << std::endl;
		return;  // Exit early if file cannot be opened
	}

	std::string line;
	std::getline(file, line); // Skip the header line (e.g., "date,price")
	
	// Read all remaining lines from the file
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string value;
		
		// Extract the date (everything before the comma)
		std::getline(ss, date, ',');
		
		// Extract the price value (everything after the comma)
		std::getline(ss, value, ',');
		
		// Convert the price string to a float for storage and calculations
		std::stringstream converter(value);
		float price;
		converter >> price;
		
		// Store the date-price pair in the map. The map automatically keeps
		// entries sorted by date, which is essential for binary search operations.
		_data[date] = price;
	}
	// The file is automatically closed when the ifstream goes out of scope
}

/*
 * IS VALID DATE
 * 
 * Purpose: Validate that a date string follows the required format (YYYY-MM-DD)
 * and represents a valid calendar date from 2009 onwards.
 * 
 * Logic: This function performs several layers of validation:
 * 1. String format check: Ensures the date is exactly 10 characters with hyphens
 *    at positions 4 and 7 (YYYY-MM-DD).
 * 2. Digit validation: Confirms that positions 0-3, 5-6, and 8-9 contain only digits.
 * 3. Range validation: Verifies that year >= 2009, month 1-12, and day 1-31.
 * 4. Month-specific validation: Applies different day limits for months with fewer
 *    than 31 days, including leap year handling for February.
 * 
 * Bitcoin Context: Bitcoin didn't exist before 2009, so dates before then are rejected.
 * This prevents users from querying non-existent historical data.
 * 
 * Return: true if the date is valid in all respects, false otherwise.
 */
bool isValidDate(const std::string &date)
{
	// Step 1: Check the string length and separator positions
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	// Step 2: Verify that all non-separator positions contain digits
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;  // Skip separator positions
		if (!isdigit(date[i]))
			return false;
	}
	
	// Step 3: Extract and parse year, month, and day from the date string
	int year, month, day;
	std::stringstream ss_year(date.substr(0, 4));
	ss_year >> year;
	std::stringstream ss_month(date.substr(5, 2));
	ss_month >> month;
	std::stringstream ss_day(date.substr(8, 2));
	ss_day >> day;

	// Step 4: Check basic range constraints
	// Bitcoin started in 2009, so reject earlier dates
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	
	// Step 5: Handle February with leap year logic
	if (month == 2) {
		// Leap year calculation: divisible by 4, except for century years
		// unless they're divisible by 400
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (isLeap && day > 29) return false;
		if (!isLeap && day > 28) return false;
	}
	
	// Step 6: Validate day limits for months with only 30 days
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	
	return true;
}

/*
 * PROCESS INPUT
 * 
 * Purpose: Read user-provided input from a file, validate each entry, look up the
 * corresponding Bitcoin price from the loaded data, and compute the total value.
 * 
 * Logic Overview:
 * 1. Open and validate the input file (skipping the header line).
 * 2. Parse each line to extract a date, separator (|), and a quantity value.
 * 3. Perform comprehensive validation on the date and value.
 * 4. Use map::lower_bound() to find the nearest date <= the requested date in
 *    the historical data (if the exact date doesn't exist, use the previous date).
 * 5. Multiply the quantity by the Bitcoin price from that date and output the result.
 * 
 * Error Handling: Invalid inputs generate descriptive error messages but do not
 * halt execution. Processing continues with the next line. This allows the program
 * to report all errors in a batch rather than stopping at the first problem.
 * 
 * Algorithm Detail - lower_bound():
 * The map's lower_bound(date) returns an iterator to the first element whose key
 * is >= the search key. Three cases are possible:
 * - Exact match: it->first == date, use this price directly.
 * - No exact match but data exists before date: decrement iterator to get the
 *   nearest earlier date (most recent available price).
 * - No data before date: it == _data.begin() with it->first > date, which means
 *   no historical data is available for the requested date.
 */
void BitcoinExchange::processInput(const std::string &filename)
{
	// Attempt to open the user-provided input file
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;  // Exit if file cannot be opened
	}

	std::string line;
	std::getline(file, line); // Skip the header line (e.g., "date | value")

	// Process each line of input
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		char separator;
		float value;

		// Attempt to parse: date, separator character, and numeric value.
		// The >> operator automatically handles whitespace, making this robust.
		if (!(ss >> date >> separator >> value) || separator != '|')
		{
			// If parsing fails or separator is not '|', perform targeted error reporting.
			// Extract just the first token to provide a more helpful error message.
			std::stringstream error_ss(line);
			std::string error_token;
			error_ss >> error_token;
			
			// If the first token is not a valid date, report it specifically.
			// Otherwise, report the entire malformed line.
			if (!isValidDate(error_token)) {
				std::cerr << "Error: bad input => " << error_token << std::endl;
			} else {
				std::cerr << "Error: bad input => " << line << std::endl;
			}
			continue;  // Skip to the next line
		}

		// Check for trailing characters after the value (should be none on a valid line).
		// If extra data exists, the entire line is considered malformed.
		std::string remainder;
		if (ss >> remainder) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;  // Skip to the next line
		}

		// Validate that the date follows the required format and is a valid calendar date
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;  // Skip to the next line
		}

		// Validate that the value is non-negative (Bitcoin quantity cannot be negative)
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;  // Skip to the next line
		}
		
		// Validate that the value is not excessively large (prevent unrealistic inputs).
		// The limit of 1000 BTC is set as a sanity check.
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;  // Skip to the next line
		}

		// Find the price data for the requested date using binary search.
		// lower_bound() returns an iterator to the first element >= the search key.
		std::map<std::string, float>::iterator it = _data.lower_bound(date);
		
		// Special case: if lower_bound returns the first element and that element's
		// date is after the requested date, then no data exists on or before the date.
		if (it == _data.begin() && it->first > date)
		{
			std::cerr << "Error: no data available for date " << date << " or earlier." << std::endl;
			continue;  // Skip to the next line
		}

		// If lower_bound didn't find an exact match (it->first != date), then we need
		// the previous entry, which represents the most recent available price before
		// the requested date. Decrement the iterator to move to that entry.
		if (it == _data.end() || it->first != date)
		{
			--it;  // Move to the previous entry (guaranteed to exist by the check above)
		}
		
		// All validations passed. Calculate and output the result:
		// quantity (value) × price per Bitcoin (it->second) = total value in USD
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
	// The file is automatically closed when the ifstream goes out of scope
}