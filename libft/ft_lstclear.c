/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:01:43 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/18 16:57:08 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;
	t_list	*save_next;

	if (!lst || !del)
		return ;
	elem = *lst;
	while (elem)
	{
		save_next = elem->next;
		del(elem->content);
		free(elem);
		elem = save_next;
	}
	*lst = NULL;
}
