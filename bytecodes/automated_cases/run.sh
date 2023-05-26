#!/bin/bash

for file in bytecodes/*.m; do
    echo "Running $file"
    ./monty "$file"
    echo "Exit status: $?"
    if [ $? -eq 0 ]; then
        echo "-------------"
    fi
done
