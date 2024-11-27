/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:45:28 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/18 17:03:25 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_to_next(const char *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] != sep && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_create_word(char const *s, char sep, int skip_sep)
{
	char	*str;
	int		i;
	int		found;
	int		len;

	found = 0;
	i = 0;
	while (0 < skip_sep && s[i])
	{
		if (s[i] != sep && !found)
		{
			skip_sep--;
			found = 1;
		}
		else if (s[i] == sep)
			found = 0;
		i++;
	}
	len = ft_len_to_next(&s[i - 1], sep) + 1;
	str = malloc(sizeof(char) * (len));
	if (!str)
		return (NULL);
	ft_memcpy(str, &s[i - 1], len);
	str[len - 1] = '\0';
	return (str);
}

static int	ft_count_word(const char *s, char sep)
{
	int	i;
	int	count_word;

	count_word = 0;
	i = 0;
	if (s[0] != '\0' && s[0] != sep)
		count_word++;
	while (s[i])
	{
		if (s[i] == sep && s[i + 1] != sep && s[i + 1] != '\0')
			count_word++;
		i++;
	}
	return (count_word);
}

static void	ft_malloc_error(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		index_word;
	int		nb_word;

	if (!s)
		return (NULL);
	nb_word = ft_count_word(s, c);
	index_word = 0;
	str_arr = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!str_arr)
		return (NULL);
	while (index_word < nb_word)
	{
		str_arr[index_word] = ft_create_word(s, c, index_word + 1);
		if (!str_arr[index_word])
		{
			ft_malloc_error(str_arr);
			return (NULL);
		}
		index_word++;
	}
	str_arr[index_word] = NULL;
	return (str_arr);
}
