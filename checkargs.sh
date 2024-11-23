#!/bin/bash

# Capture -> command; expected output
program=$1
expected_output=$2

# Run program; capture output
output=$($program)

# Compare -> actual output to expected output
if [ "$output" == "$expected_output" ]; then
  exit 0
else
  exit 1
fi
