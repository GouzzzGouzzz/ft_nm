#!/bin/bash

mkdir -p nm_outputs ft_nm_outputs diffs

GREEN="\e[32m"
RED="\e[31m"
RESET="\e[0m"
ORANGE="\e[33m"

for file in ./testfiles/*; do
    base_name=$(basename "$file")

    nm "$file" > "nm_outputs/${base_name}" 2> "nm_outputs/${base_name}"

    ./ft_nm "$file" > "ft_nm_outputs/${base_name}" 2> "ft_nm_outputs/${base_name}"

    diff "nm_outputs/${base_name}" "ft_nm_outputs/${base_name}" > "diffs/${base_name}.diff"
	if [ -s "diffs/${base_name}.diff" ]; then
		echo -e "${RED}[KO]${RESET} : $base_name"
		echo -n -e "${ORANGE}Expected:${RESET}"
		cat "nm_outputs/${base_name}" | head -n 5
		echo -e "${ORANGE}see diffs/${base_name}.diff for info.${RESET}"
	else
		echo -e "${GREEN}[OK]${RESET} : $base_name"
	fi

done

rm -rf nm_outputs ft_nm_outputs
