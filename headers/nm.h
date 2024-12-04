#ifndef NM_H
# define NM_H

#include "../libft/libft.h"
#include <sys/mman.h>
#include <stdbool.h>
#include <elf.h>

// DEBUG
void print_info_section(char *section_name, char *sym_name, Elf64_Shdr *section, int bind, char letter);

#endif
