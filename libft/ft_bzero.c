/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:09:41 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/27 14:09:43 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	long unsigned int	i;
	char				*edit;

	i = 0;
	edit = s;
	while (i < n)
	{
		edit[i] = '\0';
		i++;
	}
}
