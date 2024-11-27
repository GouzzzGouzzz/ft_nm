/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:34:33 by nmorandi          #+#    #+#             */
/*   Updated: 2022/10/19 14:00:29 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	is_negative(long int n, int fd)
{
	write(fd, "-", 1);
	n *= -1;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	int			temp;
	int			arr[10];
	int			i;

	i = 0;
	nbr = n;
	if (!fd)
		return ;
	if (nbr < 0)
		nbr = is_negative(nbr, fd);
	if (nbr == 0)
		write(fd, "0", 1);
	while (nbr > 0)
	{
		arr[i] = nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	while (i > 0)
	{
		temp = arr[i - 1] + '0';
		write(fd, &temp, 1);
		i--;
	}
}
