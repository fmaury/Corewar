/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_main_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:49:54 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/03 13:54:56 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_isopt(char c)
{
	if (c == 'o')
		return (1);
	if (c == 'a')
		return (2);
	if (c == '-')
		return (3);
	if (c == 'r')
		return (4);
	return (0);
}

int				ft_res(int flag, int res)
{
	if (flag == 1)
	{
		if (res == 0 || res == 2)
			return (1);
	}
	else if (flag == 2)
	{
		if (res < 2)
			return (2);
	}
	else if (flag == 4)
	{
		if (res < 4)
			return (4);
	}
	return (0);
}

int				ft_check_main_args(char *str)
{
	int i;
	int	flag;
	int dash;
	int	res;

	i = 0;
	res = 0;
	dash = 0;
	if (str[0] != '-' || !ft_strcmp(str, "--"))
		return (0);
	while (str[i])
	{
		flag = 0;
		if (str[i] == '-')
			dash++;
		if (dash > 1 || !(flag = ft_isopt(str[i])))
		{
			ft_printf("asm: illegal option -- %c\n", str[i]);
			return (-1);
		}
		else
			res += ft_res(flag, res);
		i++;
	}
	return (res);
}
