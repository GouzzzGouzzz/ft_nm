/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:41:54 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/18 17:02:26 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*is_zero(void)
{
	char	*str;

	str = malloc(2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int	nb_len(long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*int_to_char(char *s, long int nbr, int lennbr)
{
	while (nbr > 0)
	{
		--lennbr;
		s[lennbr] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				nblen;
	int				negative;
	long int		copy_n;

	nblen = 0;
	negative = 0;
	copy_n = n;
	if (n == 0)
		str = is_zero();
	if (n == 0)
		return (str);
	if (copy_n < 0)
		negative = 1;
	if (copy_n < 0)
		copy_n *= -1;
	nblen = nb_len(copy_n) + negative;
	str = malloc(sizeof(char) * nblen + 1);
	if (!str)
		return (0);
	str[nblen] = '\0';
	str = int_to_char(str, copy_n, nblen);
	if (negative)
		str[0] = '-';
	return (str);
}
