/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:58:34 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/18 17:02:21 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*to_add;

	if (!f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		to_add = ft_lstnew(tmp);
		if (!to_add)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, to_add);
		lst = lst->next;
	}
	return (new_lst);
}
