/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:25:18 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/29 13:11:20 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char				*dest_edit;
	const char			*src_edit;
	unsigned long int	i;

	src_edit = src;
	dest_edit = dest;
	if (!dest && !src)
		return (dest);
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			dest_edit[n] = src_edit[n];
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		dest_edit[i] = src_edit[i];
		i++;
	}
	return (dest);
}
