/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trt_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:37:34 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/27 10:48:08 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_wich_type(t_print *arg)
{
	int		res;

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

void		ft_mask(t_print *arg, int type)
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

void		ft_conv_utf8(t_print *arg, int type)
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
		ft_mask(arg, type);
	}
	else if (type == 3)
	{
		tmp = (arg->usign >> 12) & 0xF;
		arg->res[0] = 0xE0 | tmp;
		ft_mask(arg, type);
	}
	else if (type == 4)
	{
		tmp = (arg->usign >> 18) & 0x7;
		arg->res[0] = 0xF0 | tmp;
		ft_mask(arg, type);
	}
}

char		*ft_trt_char(t_print *arg, t_flag *flag)
{
	char		*str;
	int			type;

	type = 0;
	str = NULL;
	if (arg->length[0] == 'l' || arg->specifier == 'C')
		arg->usign = va_arg(*arg->ap, wchar_t);
	else
		arg->sign = va_arg(*arg->ap, int);
	arg->len = 1;
	if (arg->length[0] == 'l' || arg->specifier == 'C')
	{
		type = ft_wich_type(arg);
		ft_conv_utf8(arg, type);
		arg->len = type;
	}
	else
	{
		arg->res = ft_strnew(1);
		arg->res[0] = arg->sign;
	}
	if (arg->sign == 0 || arg->usign == 0)
		arg->precision = 0;
	str = ft_trt_pwf(arg, flag);
	return (str);
}
