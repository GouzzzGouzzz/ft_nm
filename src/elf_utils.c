#include "../headers/nm.h"

bool is_elf(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] == ELFMAG0 &&
		header->e_ident[EI_MAG1] == ELFMAG1 &&
		header->e_ident[EI_MAG2] == ELFMAG2 &&
		header->e_ident[EI_MAG3] == ELFMAG3)
	{
		return (true);
	}
	return (false);
}

static void	print_arr_rev(int size, char *tab)
{
	int add_zero;

	add_zero = 16 - size;
	for (int i = 0; i < add_zero; i++)
		write(1, "0", 1);

	while (size > 0)
	{
		size--;
		write(1, &tab[size], 1);
	}
}

void	print_hexa(int nb, int lower_case)
{
	unsigned int		nb_cast;
	int					i;
	char				*hexa_set;
	char				hexa_arr[10];

	if (nb == 0)
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
	print_arr_rev(i, hexa_arr);
}

void list_store_sym_data(t_list **symbol_list, char letter, char *sym_name, Elf64_Addr value)
{
	if (symbol_list == NULL)
	{
		symbol_data *data = malloc(sizeof(symbol_data));
		data->letter = letter;
		data->sym_name = sym_name;
		data->value = value;
		*symbol_list = ft_lstnew(data);
	}
	else
	{
		symbol_data *data = malloc(sizeof(symbol_data));
		data->letter = letter;
		data->sym_name = sym_name;
		data->value = value;
		ft_lstadd_back(symbol_list, ft_lstnew(data));
	}
}
