/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:28:18 by nmorandi          #+#    #+#             */
/*   Updated: 2022/09/27 11:51:21 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	tmp;

	tmp = ft_isalpha(c);
	if (ft_isdigit(c))
		return (4);
	else if (ft_isalpha(c))
		return (tmp);
	return (0);
}
