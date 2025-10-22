# Exercise 00: Bitcoin Exchange

## Overview

This exercise implements a Bitcoin exchange rate calculator that processes historical Bitcoin price data and computes the value of Bitcoin on specific dates.

## Purpose of the Exercise

The goal is to practice:
- **File I/O**: Reading data from CSV files and processing input files
- **Data Structures**: Using `std::map` for efficient date-based lookups
- **String Parsing**: Extracting and validating data from formatted text
- **Date Validation**: Implementing complex validation logic including leap year calculations
- **Error Handling**: Providing meaningful error messages for invalid inputs
- **Algorithm Design**: Using `lower_bound()` to find approximate matches in sorted data

## Program Architecture

### Class: BitcoinExchange

```
BitcoinExchange
│
├── Private Members:
│   └── _data: std::map<std::string, float>
│       └── Stores date -> exchange_rate mappings
│
├── Private Methods:
│   ├── BitcoinExchange(const BitcoinExchange&)  [deleted]
│   └── operator=(const BitcoinExchange&)        [deleted]
│
└── Public Methods:
    ├── BitcoinExchange()
    ├── ~BitcoinExchange()
    ├── readData()
    └── processInput(const std::string& filename)
```

### Data Flow

```
Command Line Arguments (input.txt)
    ↓
main()
    ↓
BitcoinExchange::readData()  ← Loads data.csv
    ↓
BitcoinExchange::processInput()
    ├─→ Parse each line (date | amount)
    ├─→ Validate date and amount
    ├─→ Look up exchange rate using lower_bound()
    └─→ Output result or error
```

## How It Works Step by Step

### Phase 1: Initialization

```
1. Program starts: ./btc input.txt
2. main() validates arguments (argc must be 2)
3. BitcoinExchange object created with empty _data map
4. readData() opens "data.csv"
```

### Phase 2: Loading Historical Data

The `readData()` method:

```
1. Opens "data.csv" file
2. Skips header line: "date,exchange_rate"
3. For each line in CSV:
   ├── Parse: "2009-01-02,13.7513"
   ├── Extract date: "2009-01-02"
   ├── Extract price: 13.7513
   └── Store in map: _data["2009-01-02"] = 13.7513
4. File closes (map is now sorted by date)

Result: _data = {
  "2009-01-02" → 13.7513,
  "2009-01-03" → 770.0,
  "2009-01-04" → 770.0,
  ...
  "2024-10-22" → 42000.50
}
```

**Key Property**: Map keys are automatically sorted lexicographically. Since dates use YYYY-MM-DD format, lexicographic order equals chronological order.

### Phase 3: Processing User Input

The `processInput()` method:

```
1. Opens input file (e.g., "input.txt")
2. Skips header line: "date | value"
3. For each line in input file:
   
   Line: "2011-01-03 | 3"
   
   STEP A: Parse the line
   ├── Extract date: "2011-01-03"
   ├── Extract separator: '|'
   ├── Extract amount: 3.0
   └── Check for extra data (error if present)
   
   STEP B: Validate date
   ├── Format check: YYYY-MM-DD (10 chars, hyphens at pos 4,7)
   ├── Digit check: All non-hyphen positions are digits
   ├── Range check: Year ≥ 2009, Month 1-12, Day 1-31
   └── Leap year check: Feb days properly limited
   
   STEP C: Validate amount
   ├── Check: amount ≥ 0 (non-negative)
   └── Check: amount ≤ 1000 (not too large)
   
   STEP D: Look up exchange rate
   ├── Use lower_bound("2011-01-03")
   ├── If exact date exists: use that rate
   ├── If no exact date: use closest earlier date's rate
   └── If no earlier date: error "no data available"
   
   STEP E: Calculate and output
   ├── result = amount × exchange_rate
   ├── Output: "2011-01-03 => 3 = 90"
   └── OR Output: "Error: ..."
```

### Phase 4: Key Lookup Algorithm (lower_bound)

The critical part is finding the right exchange rate. This uses `std::map::lower_bound()`:

#### Concept

```
lower_bound(key) returns iterator to first element with key ≥ search_key

Given _data = {
  "2009-01-02" → 100,
  "2009-01-03" → 200,
  "2009-01-05" → 300
}
```

#### Case 1: Exact Date Exists

```
Search: "2009-01-03"
lower_bound("2009-01-03") → points to "2009-01-03" → 200
Result: Use rate 200
```

#### Case 2: Date Between Two Entries

```
Search: "2009-01-04"
lower_bound("2009-01-04") → points to "2009-01-05" (first date ≥ 2009-01-04)
Since it->first != "2009-01-04", decrement iterator
Result: Points to "2009-01-03" → use rate 200 (closest earlier date)
```

#### Case 3: Date After All Data

```
Search: "2009-01-06"
lower_bound("2009-01-06") → end() (no element ≥ 2009-01-06)
Since it == end(), decrement to get last element
Result: Points to "2009-01-05" → use rate 300
```

#### Case 4: Date Before All Data

```
Search: "2009-01-01"
lower_bound("2009-01-01") → points to "2009-01-02" (first element)
Check: it == begin() && it->first > "2009-01-01"
Result: ERROR - "no data available for date or earlier"
```

## Error Handling

The program handles various error conditions:

### Input Validation Errors

| Error | Condition | Output |
|-------|-----------|--------|
| Bad format | Missing separator or wrong format | `Error: bad input => <line>` |
| Bad date | Invalid date format or range | `Error: bad input => <date>` |
| Negative amount | Amount < 0 | `Error: not a positive number.` |
| Too large | Amount > 1000 | `Error: too large a number.` |
| No data | Date before 2009-01-02 | `Error: no data available for date X or earlier.` |

### File I/O Errors

- **data.csv not found**: `Error: could not open data file.`
- **input file not found**: `Error: could not open file.`
- **Wrong arguments**: `Usage: ./btc <filename>`

## Worked Example

### Input File: `input.txt`

```
date | value
2011-01-03 | 3
2011-01-09 | 2
2012-01-11 | 1.2
2001-42-42 | 1
2012-01-11 | -1.2
2012-01-11 | 2147483648
```

### Execution Trace

```
Line 1: "date | value" → Skip (header)

Line 2: "2011-01-03 | 3"
├── Date valid: ✓
├── Amount valid: ✓
├── Look up 2011-01-03
│   └── lower_bound finds closest earlier date with known rate
├── Let's say rate = 30 for 2011-01-03
└── Output: "2011-01-03 => 3 = 90"

Line 3: "2011-01-09 | 2"
├── Date valid: ✓
├── Amount valid: ✓
├── Look up 2011-01-09
│   └── No exact date, use 2011-01-08 (rate = 32)
└── Output: "2011-01-09 => 2 = 64"

Line 4: "2012-01-11 | 1.2"
├── Date valid: ✓
├── Amount valid: ✓
└── Output: "2012-01-11 => 1.2 = <result>"

Line 5: "2001-42-42 | 1"
├── Date valid: ✗ (year < 2009, month 42 invalid, day 42 invalid)
└── Error: "Error: bad input => 2001-42-42"

Line 6: "2012-01-11 | -1.2"
├── Date valid: ✓
├── Amount valid: ✗ (negative)
└── Error: "Error: not a positive number."

Line 7: "2012-01-11 | 2147483648"
├── Date valid: ✓
├── Amount valid: ✗ (> 1000)
└── Error: "Error: too large a number."
```

### Output

```
2011-01-03 => 3 = 90
2011-01-09 => 2 = 64
2012-01-11 => 1.2 = <result>
Error: bad input => 2001-42-42
Error: not a positive number.
Error: too large a number.
```

## Key C++ Concepts Used

### 1. std::map with lower_bound()

```cpp
std::map<std::string, float> _data;  // Maintains sorted keys
auto it = _data.lower_bound(date);   // O(log n) lookup
```

**Why std::map?**
- Automatic sorting by key (date in chronological order)
- Binary search via `lower_bound()` - O(log n) complexity
- Natural solution for "find exact match or approximate match"

### 2. File I/O with ifstream

```cpp
std::ifstream file(filename);
if (!file.is_open()) { /* error */ }
while (std::getline(file, line)) { /* process */ }
// File auto-closes when going out of scope
```

### 3. String Parsing with stringstream

```cpp
std::stringstream ss(line);
ss >> date >> separator >> value;  // Robust parsing with whitespace handling
```

### 4. Date Validation Algorithm

```
if (length != 10) return false;                    // Format
if (date[4] != '-' || date[7] != '-') return false; // Separators
for (each digit position) { if (!isdigit(...)) return false; }  // Digits
// Extract and validate year, month, day ranges
// Special: leap year check for February
```

## Compilation and Execution

```bash
# Compile
make

# Run
./btc input.txt

# Clean
make clean
```

## Common Mistakes to Avoid

1. **Forgetting to handle no data earlier than requested date** - Must check if decrementing iterator is safe
2. **Off-by-one errors in date validation** - Month/day ranges start at 1, not 0
3. **Forgetting leap year calculation** - February can have 28 or 29 days
4. **Not trimming whitespace when parsing** - Use stringstream extraction (>>) not manual parsing
5. **Assuming exact date match exists** - Need to handle lower_bound() returning next date
6. **Not checking for extra data on lines** - Line must have exactly 3 tokens: date, separator, value

## Related Concepts

- **Binary Search**: `lower_bound()` uses binary search internally
- **Sorted Data Structures**: std::map maintains sorted invariant
- **Approximate Matching**: Using lower_bound to find "closest match"
- **Input Validation**: Multi-layered validation (format, range, business logic)
- **State Machine**: Processing is sequential through each input line
