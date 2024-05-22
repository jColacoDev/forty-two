#!/bin/bash

# Use the current directory as the root directory
root_dir=$(pwd)

# Find all .git directories except the one in the root directory
find "$root_dir" -type d -name ".git" | while read git_dir; do
  if [ "$git_dir" != "$root_dir/.git" ]; then
    echo "Removing $git_dir"
    rm -rf "$git_dir"
  fi
done

echo "All nested .git directories removed, except from the root directory."
