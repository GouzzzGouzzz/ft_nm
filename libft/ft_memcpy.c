/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:49:53 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/29 13:10:00 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long unsigned int	i;
	const char			*src_edit;
	char				*dest_edit;

	if (!src && !dest)
		return (dest);
	src_edit = src;
	dest_edit = dest;
	i = 0;
	while (i < n)
	{
		dest_edit[i] = src_edit[i];
		i++;
	}
	return (dest);
}
