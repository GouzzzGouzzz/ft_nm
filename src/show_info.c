#include "../headers/nm.h"

static void	print_arr_rev(int size, char *tab)
{
	int add_zero;

	add_zero = 16 - size;
	for (int i =0; i < add_zero; i++)
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
		write(1, "0", 1);
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
