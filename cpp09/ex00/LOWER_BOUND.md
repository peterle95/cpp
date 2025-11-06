# Complete Deep-Dive into `lower_bound` for Bitcoin Exchange

## The Problem We're Solving

You have a Bitcoin price database (`data.csv`) with prices on specific dates. When someone asks "What was 5 BTC worth on 2011-01-05?", you need to find the price, BUT that exact date might not be in your database!

**Rule:** If the exact date doesn't exist, use the **closest earlier date's price**.

---

## Understanding `lower_bound` - The Basics

`lower_bound` answers this question:
> "If I were to insert this value into the sorted container, where would it go?"

It returns an iterator pointing to:
- **The exact match** if it exists, OR
- **The first element GREATER than** your search value

---

## Visual Walkthrough - Let's Build Understanding

### Setup: Your Database

```
Your _data map looks like this:
┌──────────────┬────────┐
│     Date     │ Price  │
├──────────────┼────────┤
│ 2011-01-01   │ 0.30   │ ← position 0 (begin)
│ 2011-01-04   │ 0.30   │ ← position 1
│ 2011-01-07   │ 0.32   │ ← position 2
│ 2011-01-10   │ 0.33   │ ← position 3
│ 2011-01-13   │ 0.42   │ ← position 4
│ 2011-01-16   │ 0.40   │ ← position 5 (last)
└──────────────┴────────┘
                         ↑ (end)
```

---

## Example 1: EXACT MATCH

**User Input:** `2011-01-07 | 5`

**Step-by-step execution:**

```cpp
date = "2011-01-07"
it = _data.lower_bound("2011-01-07");
```

**What happens inside `lower_bound`?**

```
Map:    2011-01-01  2011-01-04  2011-01-07  2011-01-10  2011-01-13
                                     ↑
                                   Found it!
```

**Result:**
- `it` points to: `2011-01-07 => 0.32`
- `it->first` is `"2011-01-07"`
- `it->second` is `0.32`

**Check in your code:**
```cpp
if (it == _data.end() || it->first != date)  // FALSE! it->first == date
{
    --it;  // SKIP THIS - we have exact match
}

// Use it->second directly
std::cout << "2011-01-07 => 5 = " << 5 * 0.32 << std::endl;
// Output: 2011-01-07 => 5 = 1.6
```

✅ **We found the exact date, use its price!**

---

## Example 2: DATE IN THE MIDDLE (Most Important Case!)

**User Input:** `2011-01-05 | 10`

This date **does NOT exist** in our database!

**Step-by-step execution:**

```cpp
date = "2011-01-05"
it = _data.lower_bound("2011-01-05");
```

**What happens inside `lower_bound`?**

```
Map:    2011-01-01  2011-01-04  2011-01-07  2011-01-10  2011-01-13
                                     ↑
        "2011-01-05 would go HERE (between 01-04 and 01-07)"
```

`lower_bound` says: "The first date NOT LESS than 2011-01-05 is **2011-01-07**"

**Result:**
- `it` points to: `2011-01-07 => 0.32`
- `it->first` is `"2011-01-07"` (NOT our date!)

**Check in your code:**
```cpp
if (it == _data.end() || it->first != date)  // TRUE! "2011-01-07" != "2011-01-05"
{
    --it;  // MOVE BACKWARD ONE POSITION!
}
```

**After `--it`:**
```
Map:    2011-01-01  2011-01-04  2011-01-07  2011-01-10  2011-01-13
                         ↑
                    Now points here!
```

- `it` now points to: `2011-01-04 => 0.30`

**Final calculation:**
```cpp
std::cout << "2011-01-05 => 10 = " << 10 * 0.30 << std::endl;
// Output: 2011-01-05 => 10 = 3
```

✅ **We used the closest EARLIER date's price (2011-01-04)**

---

## Example 3: DATE BEFORE ALL DATA (Error Case)

**User Input:** `2009-06-15 | 100`

Your database starts at `2011-01-01`, so this is TOO EARLY!

**Step-by-step execution:**

```cpp
date = "2009-06-15"
it = _data.lower_bound("2009-06-15");
```

**What happens inside `lower_bound`?**

```
Map:    2011-01-01  2011-01-04  2011-01-07  2011-01-10  2011-01-13
            ↑
   "2009-06-15 would go BEFORE everything"
```

`lower_bound` returns an iterator to the **first element** (2011-01-01)

**Result:**
- `it` points to: `2011-01-01 => 0.30`
- `it == _data.begin()` is `TRUE`
- `it->first` is `"2011-01-01"` (which is > `"2009-06-15"`)

**Check in your code:**
```cpp
if (it == _data.begin() && it->first > date)  // TRUE!
{
    std::cerr << "Error: no data available for date " << date 
              << " or earlier." << std::endl;
    continue;  // Don't process this line
}
```

❌ **ERROR! Can't find any earlier date!**

---

## Example 4: DATE AFTER ALL DATA

**User Input:** `2011-01-20 | 50`

Your database ends at `2011-01-16`.

**Step-by-step execution:**

```cpp
date = "2011-01-20"
it = _data.lower_bound("2011-01-20");
```

**What happens inside `lower_bound`?**

```
Map:    2011-01-01  2011-01-04  2011-01-07  2011-01-10  2011-01-13  2011-01-16
                                                                              (end)
                                                                               ↑
                                                "2011-01-20 would go HERE (after everything)"
```

`lower_bound` returns `_data.end()` (past the last element)

**Result:**
- `it == _data.end()` is `TRUE`

**Check in your code:**
```cpp
if (it == _data.end() || it->first != date)  // TRUE! it == end()
{
    --it;  // MOVE BACKWARD ONE POSITION!
}
```

**After `--it`:**
```
Map:    2011-01-01  2011-01-04  2011-01-07  2011-01-10  2011-01-13  2011-01-16
                                                                         ↑
                                                                    Now points here!
```

- `it` now points to: `2011-01-16 => 0.40` (the LAST date in database)

**Final calculation:**
```cpp
std::cout << "2011-01-20 => 50 = " << 50 * 0.40 << std::endl;
// Output: 2011-01-20 => 50 = 20
```

✅ **We used the most recent available price (2011-01-16)**

---

## The Complete Logic Flow

```
                    START: lower_bound(date)
                              |
                              v
         ┌───────────────────────────────────────┐
         │  Where would 'date' fit in the map?   │
         └───────────────────────────────────────┘
                              |
                              v
              ┌───────────────┴───────────────┐
              |                               |
         Exact Match?                    No Match?
         it->first == date               it->first != date
              |                               |
              v                               v
         USE IT!                    ┌─────────────────┐
         it->second                 │  it points to   │
                                    │  NEXT date OR   │
                                    │  end()          │
                                    └─────────────────┘
                                              |
                                              v
                                         --it (go back)
                                              |
                                              v
                                    ┌──────────────────┐
                                    │ Check: Are we at │
                                    │ begin() AND date │
                                    │ is too early?    │
                                    └──────────────────┘
                                         |        |
                                    YES  |        | NO
                                         v        v
                                      ERROR!   USE IT!
                                               it->second
```

---

## Real Code Flow - Traced

```cpp
// Example: date = "2011-01-05", database has 2011-01-04 and 2011-01-07

std::map<std::string, float>::iterator it = _data.lower_bound("2011-01-05");
// it → points to 2011-01-07 (first element >= 2011-01-05)

if (it == _data.begin() && it->first > date)
// FALSE: it is NOT at begin (2011-01-01)
{
    // skip
}

if (it == _data.end() || it->first != date)
// TRUE: it->first is "2011-01-07" which is NOT "2011-01-05"
{
    --it;  // it → now points to 2011-01-04
}

// Now use: it->second (the price at 2011-01-04)
float price = it->second;  // 0.30
```

---

## Key Mental Model

Think of `lower_bound` as a **cursor** that always points to "where your date WOULD BE or the next higher date":

```
Your search: 2011-01-05

Database: [2011-01-01] [2011-01-04] [____?____] [2011-01-07] [2011-01-10]
                                        ↑
                                  (2011-01-05 would go here)
                                        
lower_bound points to →                             [2011-01-07]
                                                        ↑
                                            (first date >= your search)

Then you do --it to get →           [2011-01-04]
                                        ↑
                                  (the date you actually want!)
```

---

## Practice Questions

**Q1:** If database has `[2011-01-01, 2011-01-05, 2011-01-10]` and you search for `2011-01-07`, where does `lower_bound` point initially?

<details>
<summary>Answer</summary>

`lower_bound` points to `2011-01-10` (first element >= 2011-01-07).
After `--it`, it points to `2011-01-05` (which is what you want!).

</details>

**Q2:** If database has `[2011-01-05, 2011-01-10]` and you search for `2011-01-03`, what happens?

<details>
<summary>Answer</summary>

`lower_bound` points to `2011-01-05` (first element).
Since `it == _data.begin()` AND `it->first > "2011-01-03"`, you get an ERROR: no data available!

</details>

Does this make it crystal clear now?