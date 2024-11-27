/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:06:35 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/27 11:06:35 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	long unsigned int	i;
	char				*edit;

	i = 0;
	edit = s;
	while (i < n)
	{
		edit[i] = c;
		i++;
	}
	return ((void *)s);
}
