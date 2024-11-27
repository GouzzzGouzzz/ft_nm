/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:49:08 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/27 16:49:19 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	converted;
	int			sign;
	int			i;
	int			is_digit;

	converted = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	is_digit = ft_isdigit(nptr[i]);
	while (is_digit)
	{
		converted = converted * 10 + (nptr[i] - '0');
		i++;
		is_digit = ft_isdigit(nptr[i]);
	}
	return (converted * sign);
}
