#include "../headers/nm.h"

void print_symbol_data(t_list *symbol_list)
{
	while (symbol_list)
	{
		symbol_data *data = symbol_list->content;
		if (data->letter != 'U' && data->letter != 'w')
			print_hexa(data->value, 1);
		else
			ft_putstr_fd("                ", 1);
				ft_putchar_fd(' ', 1);
		ft_putchar_fd(data->letter, 1);
		ft_putchar_fd(' ', 1);
		ft_putendl_fd(data->sym_name, 1);
		symbol_list = symbol_list->next;
	}
}

void free_symbol_data(t_list *symbol_list)
{
	t_list *tmp = NULL;

	while (symbol_list)
	{
		symbol_data *data = symbol_list->content;
		free(data);
		tmp = symbol_list;
		symbol_list = symbol_list->next;
		free(tmp);
	}
}
