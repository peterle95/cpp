Exercise 00: Bitcoin Exchange
This initial exercise requires the creation of a C++ program named btc to calculate the value of a specified amount of Bitcoin on a given date. The program will take a file as an argument, which contains a series of dates and Bitcoin amounts. The core of this task involves reading and parsing this input file, as well as a provided CSV database of Bitcoin prices, and then performing the necessary calculations.
Core Functionality:
The program must:
Accept a single command-line argument: the path to an input file.
Read a provided CSV file (data.csv) containing historical Bitcoin prices.
Store this historical data in a suitable STL container. For this exercise, std::map is a logical choice, offering efficient lookups based on dates.
Process the input file line by line, with each line formatted as "date | value".
For each line, parse the date and the Bitcoin value.
Validate the date and value according to the specified rules:
Dates must be in "Year-Month-Day" format.
Values must be a positive float or integer between 0 and 1000.
For each valid entry, find the corresponding Bitcoin price in the historical data. If the exact date is not found, the closest earlier date's price should be used.
Calculate the total value by multiplying the Bitcoin amount from the input file by the retrieved exchange rate.
Display the result to the standard output.
Handle potential errors gracefully with appropriate error messages.
Implementation Details:
1. Reading and Storing CSV Data:
The program will first open and read the data.csv file. An std::ifstream is used for file input. Each line of the CSV is read and then parsed. A std::stringstream can be employed to easily separate the date and the price, which are delimited by a comma.[1][2][3] This data is then stored in an std::map<std::string, float>, where the date string serves as the key and the price is the value. The use of std::map allows for efficient searching and retrieval of prices based on dates.
2. Processing the Input File:
The program then opens the input file specified by the command-line argument. It reads the file line by line. For each line, the date and value are separated by a " | " delimiter.
3. Date and Value Validation:
A series of checks are performed on the parsed data from the input file:
Date Format: The date string is validated to ensure it follows the "YYYY-MM-DD" format. This includes checking the year, month, and day for correct ranges and the presence of hyphens in the correct positions.
Value Range: The numerical value is checked to be a positive number and not to exceed 1000.
4. Price Lookup and Calculation:
For each valid date and value, the program looks for the corresponding price in the std::map. If an exact match for the date is found, that price is used. If not, the program must find the closest date that is earlier than the requested date. This can be achieved by using the lower_bound method of std::map, which finds the first element that is not less than the given key. By moving one position back from this iterator (if it's not the beginning of the map), we can find the desired earlier date.
The final value is then calculated by multiplying the Bitcoin amount from the input file by the determined exchange rate.