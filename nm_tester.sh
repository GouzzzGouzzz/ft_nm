#!/bin/bash

# Directories for outputs
mkdir -p nm_outputs ft_nm_outputs diffs

# Process each file in the testfiles directory
for file in ./testfiles/*; do
    # Extract the base name of the file
    base_name=$(basename "$file")

    # Execute the nm command and save the result
    nm "$file" > "nm_outputs/${base_name}.nm_output"

    # Execute the ./ft_nm command and save the result
    ./ft_nm "$file" > "ft_nm_outputs/${base_name}.ft_nm_output"

	echo " "
    # Compute the diff and save the result
    diff "nm_outputs/${base_name}.nm_output" "ft_nm_outputs/${base_name}.ft_nm_output" > "diffs/${base_name}.diff"
done

echo "Processing complete. Check 'nm_outputs', 'ft_nm_outputs', and 'diffs' directories."
