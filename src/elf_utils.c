#include "../headers/nm.h"

bool is_elf(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] == ELFMAG0 &&
		header->e_ident[EI_MAG1] == ELFMAG1 &&
		header->e_ident[EI_MAG2] == ELFMAG2 &&
		header->e_ident[EI_MAG3] == ELFMAG3)
		{
			return true;
		}
	return false;
}

static void	print_arr_rev(int size, char *tab, int type)
{
	int add_zero;

	if (type == 1)
		add_zero = 8 - size;
	else
		add_zero = 16 - size;
	for (int i = 0; i < add_zero; i++)
		write(1, "0", 1);

	while (size > 0)
	{
		size--;
		write(1, &tab[size], 1);
	}
}

void	print_hexa(int nb, int lower_case, int type)
{
	unsigned int		nb_cast;
	int					i;
	char				*hexa_set;
	char				hexa_arr[10];
	if (type == 1 && nb == 0)
	{
		write(1, "00000000", 8);
		return ;
	}
	else if (nb == 0)
	{
		write(1, "0000000000000000", 16);
		return ;
	}
	hexa_set = "0123456789ABCDEF";
	i = 0;
	nb_cast = nb;
	while (nb_cast > 0)
	{
		if (nb_cast % 16 > 9 && lower_case)
			hexa_arr[i] = hexa_set[(nb_cast % 16)] + 32;
		else
			hexa_arr[i] = hexa_set[(nb_cast % 16)];
		nb_cast = nb_cast / 16;
		i++;
	}
	print_arr_rev(i, hexa_arr, type);
}

void list_store_sym_data(t_list **symbol_list, char letter, char *sym_name, Elf64_Addr addr)
{
	if (symbol_list == NULL)
	{
		symbol_data *data = malloc(sizeof(symbol_data));
		data->letter = letter;
		data->sym_name = sym_name;
		data->addr = addr;
		*symbol_list = ft_lstnew(data);
	}
	else
	{
		symbol_data *data = malloc(sizeof(symbol_data));
		data->letter = letter;
		data->sym_name = sym_name;
		data->addr = addr;
		ft_lstadd_back(symbol_list, ft_lstnew(data));
	}
}

void error(char *filename, char *msg)
{
	ft_putstr_fd("nm: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

bool check_file_format(int type, void *ptr, unsigned long file_size, char *filename)
{
	if (type == ELFCLASS64)
	{
		Elf64_Ehdr	*header = (Elf64_Ehdr *)ptr;
		//there is an offset but no entry or entry size
		if (header->e_shoff != 0){
			if (header->e_shnum == 0 || header->e_shentsize == 0) {
				error(filename, "file format not recognized");
				return false;
			}
		}
		//check secion header offset and program header offset
		// (are in bound the file, and small enough to contain all the headers entries)
		if (header->e_shoff >= file_size || (file_size - header->e_shoff) < (header->e_shnum * header->e_shentsize))
		{
			error(filename, "file format not recognized");
			return false;
		}
		if (header->e_phoff >= file_size || (file_size - header->e_phoff) < (header->e_phnum * header->e_phentsize))
		{
			error(filename, "file format not recognized");
			return false;
		}
		//Invalid endianess
		if (header->e_ident[EI_DATA] != ELFDATA2LSB && header->e_ident[EI_DATA] != ELFDATA2MSB)
		{
			error(filename, "file format not recognized");
			return false;
		}
	}
	else if (type == ELFCLASS32)
	{
		Elf32_Ehdr	*header = (Elf32_Ehdr *)ptr;
		if (header->e_shoff != 0){
			if (header->e_shnum == 0 || header->e_shentsize == 0) {
				error(filename, "file format not recognized");
				return false;
			}
		}
		if (header->e_shoff >= file_size || (file_size - header->e_shoff) < (header->e_shnum * header->e_shentsize))
		{
			error(filename, "file format not recognized");
			return false;
		}
		if (header->e_phoff >= file_size || (file_size - header->e_phoff) < (header->e_phnum * header->e_phentsize))
		{
			error(filename, "file format not recognized");
			return false;
		}
		if (header->e_ident[EI_DATA] != ELFDATA2LSB && header->e_ident[EI_DATA] != ELFDATA2MSB)
		{
			error(filename, "file format not recognized");
			return false;
		}
	}
	return true;
}
