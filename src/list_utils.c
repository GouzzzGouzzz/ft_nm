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

static void list_split(t_list *head, t_list **first_half, t_list **second_half)
{
	t_list *slow = head;
	t_list *fast = head->next;

	//By moving 2 time faster with "*fast" than slow, we end up having slow in the middle of the list
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	*first_half = head;
	*second_half = slow->next;
	slow->next = NULL;
}

static t_list* merge_sorted(t_list *first_half, t_list *second_half)
{
	t_list *result;

	if (!first_half)
		return second_half;
	if (!second_half)
		return first_half;

	symbol_data *data_a = first_half->content;
	symbol_data *data_b = second_half->content;
	if (ft_strncmp(data_a->sym_name, data_b->sym_name, -1) < 0)
	{
		result = first_half;
		result->next = merge_sorted(first_half->next, second_half);
	}
	else
	{
		result = second_half;
		result->next = merge_sorted(first_half, second_half->next);
	}
	return result;
}

//Using a merge sort
void	merge_sortASCII(t_list **symbol_list)
{
	t_list *head = *symbol_list;
	if (!head || !head->next)
		return ;
	//split the list in two
	t_list *first_half = NULL;
	t_list *second_half = NULL;

	list_split(*symbol_list, &first_half, &second_half);

	// recursively sort the two halves
	merge_sortASCII(&first_half);
	merge_sortASCII(&second_half);

	//merge the two halves
	*symbol_list = merge_sorted(first_half, second_half);
}
