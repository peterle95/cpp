#!/bin/bash

# Compile the program
make re

# Define test cases
declare -A tests
tests[test1.txt]="Hello World!|Hi Universe!"
tests[test2.txt]="World|Earth"
tests[test3.txt]="|NewString"
tests[test4.txt]="NonExistent|Replacement"
tests[test5.txt]="@World|@Earth"

# Run tests
for test in "${!tests[@]}"; do
    IFS='|' read -r s1 s2 <<< "${tests[$test]}"
    echo "Running test on $test: replacing '$s1' with '$s2'"

    # Run the program
    ./sed "$test" "$s1" "$s2"

    # Check the output
    expected_output="${test}.replace"
    echo "Expected output in $expected_output:"
    cat "$expected_output"
    echo "-----------------------------------"
done