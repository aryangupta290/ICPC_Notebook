#!/bin/bash

# Traverse all subdirectories and format .h files
find . -type f -name "*.h" -exec bash -c '
  # Get the directory path and filename
  dir=$(dirname "$1")
  file=$(basename "$1")

  # copy ./a.out to the directory
  cp ./a.out "$dir"

  # Go to the directory
  cd "$dir"

  # Run the formatting code on the file
  ./a.out "$file"

  # Go back to the original directory
  cd - >/dev/null 2>&1
' bash {} \;
