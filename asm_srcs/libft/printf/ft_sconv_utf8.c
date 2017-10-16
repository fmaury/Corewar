/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sconv_utf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 13:29:17 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/27 10:51:38 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_wich_stype(t_print *arg)
{
	int			res;

	res = 0;
	if (arg->usign <= 0x7F)
		res = 1;
	else if (arg->usign <= 0x7FF)
		res = 2;
	else if (arg->usign <= 0xFFFF)
		res = 3;
	else if (arg->usign <= 0x10FFFF)
		res = 4;
	else
		res = 0;
	if (MB_CUR_MAX < 4 && res != 1)
		arg->err++;
	return (res);
}

void	ft_smask(t_print *arg, int type)
{
	wchar_t		tmp;
	int			i;

	i = 1;
	tmp = arg->usign;
	while (type > 1)
	{
		tmp = tmp & 0x3F;
		arg->res[type - 1] = 0x80 | tmp;
		tmp = arg->usign >> 6 * i;
		type--;
		i++;
	}
}

void	ft_sconv_utf8(t_print *arg, int type)
{
	wchar_t		tmp;

	tmp = 0;
	arg->res = ft_strnew(type);
	if (type == 1)
		arg->res[0] = arg->usign;
	else if (type == 2)
	{
		tmp = (arg->usign >> 6) & 0x1F;
		arg->res[0] = 0xC0 | tmp;
		ft_smask(arg, type);
	}
	else if (type == 3)
	{
		tmp = (arg->usign >> 12) & 0xF;
		arg->res[0] = 0xE0 | tmp;
		ft_smask(arg, type);
	}
	else if (type == 4)
	{
		tmp = (arg->usign >> 18) & 0x7;
		arg->res[0] = 0xF0 | tmp;
		ft_smask(arg, type);
	}
}
