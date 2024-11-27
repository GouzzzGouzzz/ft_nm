/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:06:24 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/27 11:06:24 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	long unsigned int	i;
	const unsigned char	*s1_edit;
	const unsigned char	*s2_edit;

	s1_edit = s1;
	s2_edit = s2;
	i = 0;
	while (i < n)
	{
		if (s1_edit[i] != s2_edit[i])
			return (s1_edit[i] - s2_edit[i]);
		i++;
	}
	return (0);
}
