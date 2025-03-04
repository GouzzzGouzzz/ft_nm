#ifndef NM_H
# define NM_H

#include "../libft/libft.h"
#include <sys/mman.h>
#include <stdbool.h>
#include <elf.h>

//Simple structure to store symbol data for each symbol, this is used inside a linked list
typedef struct s_symbol_data
{
	char letter;
	char *sym_name;
	Elf64_Addr addr;
} symbol_data;


//Main functions
t_list	*parse_elf64(void *file_map, unsigned long file_size, char *filename);
t_list	*parse_elf32(void *file_map, unsigned long file_size, char *filename);


//Utils linked list functions
void	free_symbol_data(t_list *symbol_list);
void	print_symbol_data(t_list *symbol_list, int type);
void	list_store_sym_data(t_list **symbol_list, char letter, char *sym_name, Elf64_Addr value);
void	merge_sortASCII(t_list **symbol_list);

//Utils functions
bool	is_elf(Elf64_Ehdr *header);
void	print_hexa(int nb, int lower_case, int type);
void	error(char *filename, char *msg);
bool	check_file_format(int type, void *ptr, unsigned long file_size, char *filename);
uint64_t	to_little_endian_64(uint64_t value);
uint32_t	to_little_endian_32(uint32_t value);
uint16_t	to_little_endian_16(uint16_t value);

#endif
