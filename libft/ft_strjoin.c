/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:08:47 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/19 14:13:06 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	int		temp;

	if (!s1)
		return (NULL);
	str = malloc((ft_strlen(s1) + 1 + ft_strlen(s2)) * sizeof(char));
	if (!(str))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	temp = i;
	i = 0;
	while (s2[i])
	{
		str[temp + i] = s2[i];
		i++;
	}
	str[temp + i] = '\0';
	return (str);
}
