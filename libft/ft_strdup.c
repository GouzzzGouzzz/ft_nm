/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:03:36 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/29 17:23:36 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		slen;

	slen = ft_strlen(s);
	dup = malloc(slen * sizeof(char) + 1);
	if (!(dup))
		return (NULL);
	ft_strlcpy(dup, s, slen + 1);
	return ((char *)dup);
}
