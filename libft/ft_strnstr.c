/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:48:44 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/28 14:26:19 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	long unsigned int	i;
	int					temp;
	int					littlelen;

	if (little[0] == '\0' || !little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	littlelen = ft_strlen(little);
	temp = 0;
	i = 0;
	while (i < len)
	{
		while (little[temp] == big[i + temp] && temp + i < len)
		{
			temp++;
			if (temp == littlelen)
				return ((char *) &big[i]);
		}
		temp = 0;
		i++;
	}
	return (NULL);
}
