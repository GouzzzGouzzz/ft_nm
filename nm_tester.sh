#!/bin/bash

rm -rf ko_files diffs
mkdir -p nm_outputs ft_nm_outputs diffs ko_files

GREEN="\e[32m"
RED="\e[31m"
RESET="\e[0m"
ORANGE="\e[33m"

for file in ./testfiles/mytest/*; do
    base_name=$(basename "$file")

    nm "$file" > "nm_outputs/${base_name}" 2> "nm_outputs/${base_name}"

    ./ft_nm "$file" > "ft_nm_outputs/${base_name}" 2> "ft_nm_outputs/${base_name}"

    diff "nm_outputs/${base_name}" "ft_nm_outputs/${base_name}" > "diffs/${base_name}.diff"
	if [ -s "diffs/${base_name}.diff" ]; then
		mv "diffs/${base_name}.diff" "ko_files/${base_name}.diff"
		echo -e "${RED}[KO]${RESET} : $base_name (dir:mytest)"
		echo -n -e "${ORANGE}Expected:${RESET}"
		cat "nm_outputs/${base_name}" | head -n 5
		echo -e "${ORANGE}see diffs/${base_name}.diff for info.${RESET}"
	else
		echo -e "${GREEN}[OK]${RESET} : $base_name (dir:mytest)"
	fi

done

for file in ./testfiles/mandatory/*; do
    base_name=$(basename "$file")

    nm "$file" > "nm_outputs/${base_name}" 2> "nm_outputs/${base_name}"

    ./ft_nm "$file" > "ft_nm_outputs/${base_name}" 2> "ft_nm_outputs/${base_name}"

    diff "nm_outputs/${base_name}" "ft_nm_outputs/${base_name}" > "diffs/${base_name}.diff"
	if [ -s "diffs/${base_name}.diff" ]; then
		mv "diffs/${base_name}.diff" "ko_files/${base_name}.diff"
		echo -e "${RED}[KO]${RESET} : $base_name (dir:mandatory)"
		echo -n -e "${ORANGE}Expected:${RESET}"
		cat "nm_outputs/${base_name}" | head -n 5
		echo -e "${ORANGE}see diffs/${base_name}.diff for info.${RESET}"
	else
		echo -e "${GREEN}[OK]${RESET} : $base_name (dir:mandatory)"
	fi

done


for file in ./testfiles/test_bad_file/*; do
    base_name=$(basename "$file")

    nm "$file" > "nm_outputs/${base_name}" 2> "nm_outputs/${base_name}"

    ./ft_nm "$file" > "ft_nm_outputs/${base_name}" 2> "ft_nm_outputs/${base_name}"

    diff "nm_outputs/${base_name}" "ft_nm_outputs/${base_name}" > "diffs/${base_name}.diff"
	if [ -s "diffs/${base_name}.diff" ]; then
		mv "diffs/${base_name}.diff" "ko_files/${base_name}.diff"
		echo -e "${RED}[KO]${RESET} : $base_name (dir:test_bad_file)"
		echo -n -e "${ORANGE}Expected:${RESET}"
		cat "nm_outputs/${base_name}" | head -n 5
		echo -e "${ORANGE}see diffs/${base_name}.diff for info.${RESET}"
	else
		echo -e "${GREEN}[OK]${RESET} : $base_name (dir:test_bad_file)"
	fi

done


for file in ./testfiles/good_files/*; do
    base_name=$(basename "$file")

    nm "$file" > "nm_outputs/${base_name}" 2> "nm_outputs/${base_name}"

    ./ft_nm "$file" > "ft_nm_outputs/${base_name}" 2> "ft_nm_outputs/${base_name}"

    diff "nm_outputs/${base_name}" "ft_nm_outputs/${base_name}" > "diffs/${base_name}.diff"
	if [ -s "diffs/${base_name}.diff" ]; then
		mv "diffs/${base_name}.diff" "ko_files/${base_name}.diff"
		echo -e "${RED}[KO]${RESET} : $base_name (dir:good_files)"
		echo -n -e "${ORANGE}Expected:${RESET}"
		cat "nm_outputs/${base_name}" | head -n 5
		echo -e "${ORANGE}see diffs/${base_name}.diff for info.${RESET}"
	else
		echo -e "${GREEN}[OK]${RESET} : $base_name (dir:good_files)"
	fi

done

for file in ./testfiles/bad_files/*; do
    base_name=$(basename "$file")

    nm "$file" > "nm_outputs/${base_name}" 2> "nm_outputs/${base_name}"

    ./ft_nm "$file" > "ft_nm_outputs/${base_name}" 2> "ft_nm_outputs/${base_name}"

    diff "nm_outputs/${base_name}" "ft_nm_outputs/${base_name}" > "diffs/${base_name}.diff"
	if [ -s "diffs/${base_name}.diff" ]; then
		mv "diffs/${base_name}.diff" "ko_files/${base_name}.diff"
		echo -e "${RED}[KO]${RESET} : $base_name (dir:bad_files)"
		echo -n -e "${ORANGE}Expected:${RESET}"
		cat "nm_outputs/${base_name}" | head -n 1
		echo -e "${ORANGE}see diffs/${base_name}.diff for info.${RESET}"
	else
		echo -e "${GREEN}[OK]${RESET} : $base_name (dir:bad_files)"
	fi

done

rm -rf nm_outputs ft_nm_outputs
