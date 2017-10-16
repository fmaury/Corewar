/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:10:15 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/18 16:41:43 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int	range;
	int *tab;
	int i;

	i = 0;
	range = max - min;
	if (min >= max)
		return (0);
	tab = (int*)malloc(sizeof(int) * range);
	while (min != max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
