#include "../headers/nm.h"

void parse_elf32(void *file_map){
	Elf32_Ehdr *header = (Elf32_Ehdr *)file_map;

	(void) header;
}
