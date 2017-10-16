/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:34:52 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/16 09:42:34 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int i;
	int flag;
	int res;

	i = 0;
	flag = 0;
	res = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
		flag = 1;
	if (flag == 1)
		i++;
	while (ft_isdigit(str[i]))
	{
		res = (res + (str[i] - 48));
		if (str[i + 1] >= 48 && str[i + 1] <= 57)
			res = res * 10;
		i++;
	}
	if (flag == 1)
		return (-res);
	return (res);
}
