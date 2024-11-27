/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:42:14 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/30 12:24:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	temp;
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	temp = -1;
	if (c == '\0')
		return ((char *)&s[len]);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			temp = i;
		i++;
	}
	if (temp < 0)
		return (NULL);
	return ((char *) &s[temp]);
}
