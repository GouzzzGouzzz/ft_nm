/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:01:48 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/18 16:58:08 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trim_end(char const *s1, char const *set, int len)
{
	int	in_set;

	in_set = ft_is_in_set(s1[len - 1], set);
	while (in_set)
	{
		len--;
		in_set = ft_is_in_set(s1[len - 1], set);
	}
	return (len);
}

static int	ft_trim_start(char const *s1, char const *set, int len)
{
	int	in_set;
	int	i;

	i = 0;
	in_set = ft_is_in_set(s1[i], set);
	while (in_set)
	{
		len--;
		i++;
		in_set = ft_is_in_set(s1[i], set);
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		newlen;
	int		start;

	if (!s1 || !set)
		return (NULL);
	newlen = ft_strlen(s1);
	newlen = ft_trim_end(s1, set, newlen);
	start = newlen;
	newlen = ft_trim_start(s1, set, newlen);
	start -= newlen;
	if (newlen <= 0)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = ft_substr(s1, start, newlen);
	return (str);
}
