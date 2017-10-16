/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:08:12 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/18 16:40:51 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int i;
	int res;

	i = 1;
	res = 0;
	if (nb <= 0)
		return (0);
	while (res != nb)
	{
		if ((res / nb) != 1)
		{
			res = i * i;
			i++;
		}
		else
			return (0);
	}
	if ((res / nb) == 1)
	{
		i--;
		return (i);
	}
	else
		return (0);
}
