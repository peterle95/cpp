#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

// This function remains the same and is correct for C++98
void BitcoinExchange::readData()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open data file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string value;
		std::getline(ss, date, ',');
		std::getline(ss, value, ',');
		
		std::stringstream converter(value);
		float price;
		converter >> price;
		_data[date] = price;
	}
}

// This function remains the same and is correct for C++98
bool isValidDate(const std::string &date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	
	int year, month, day;
	std::stringstream ss_year(date.substr(0, 4));
	ss_year >> year;
	std::stringstream ss_month(date.substr(5, 2));
	ss_month >> month;
	std::stringstream ss_day(date.substr(8, 2));
	ss_day >> day;

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (isLeap && day > 29) return false;
		if (!isLeap && day > 28) return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}

// This function is now corrected with robust parsing
void BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		char separator;
		float value;

		// Use stringstream to parse the line. This robustly handles whitespace.
		if (!(ss >> date >> separator >> value) || separator != '|')
		{
			// Special handling for lines that are just bad dates without a separator
			std::stringstream error_ss(line);
			std::string error_token;
			error_ss >> error_token;
			if (!isValidDate(error_token)) {
				std::cerr << "Error: bad input => " << error_token << std::endl;
			} else {
				std::cerr << "Error: bad input => " << line << std::endl;
			}
			continue;
		}

		// Check for any extra characters on the line after the value
		std::string remainder;
		if (ss >> remainder) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = _data.lower_bound(date);
		if (it == _data.begin() && it->first > date)
		{
			std::cerr << "Error: no data available for date " << date << " or earlier." << std::endl;
			continue;
		}

		if (it == _data.end() || it->first != date)
		{
			--it;
		}
		
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}