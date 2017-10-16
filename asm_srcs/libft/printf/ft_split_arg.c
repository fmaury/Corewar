/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:24:30 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/22 15:34:05 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_gest_prec(t_print *arg)
{
	char	pre[11];

	if (arg->cprecision[1] == '*')
	{
		arg->precision = va_arg(*arg->ap, int);
		if (arg->precision < 0)
		{
			arg->cprecision[0] = '\0';
			arg->precision = 0;
		}
	}
	else
	{
		ft_strcpy(pre, arg->cprecision);
		pre[0] = '0';
		arg->precision = ft_atoi(pre);
	}
}

void		ft_conv_arg(t_print *arg)
{
	int		i;

	i = 0;
	while (arg->cwidth[i] != '*' && arg->cwidth[i])
		i++;
	if (arg->cwidth[i] == '*' && (i > 0 ||
				ft_isdigit(arg->cwidth[i + 1]) == 0))
		arg->width = va_arg(*arg->ap, int);
	else
	{
		if (arg->cwidth[0] == '*')
		{
			va_arg(*arg->ap, int);
			arg->cwidth[0] = '0';
		}
		arg->width = ft_atoi(arg->cwidth);
	}
	ft_gest_prec(arg);
}

int			ft_alloc_cpy(int i, int k, char *str, char *cpy)
{
	int		l;

	l = 0;
	if (k > 0)
	{
		while (i + l < i + k)
		{
			cpy[l] = str[i + l];
			l++;
		}
		cpy[l] = '\0';
	}
	return (i + l);
}

void		ft_split_arg(t_print *arg)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (ft_isflag(arg->str[i + k]))
		k++;
	arg->flag = ft_strnew(k);
	i = ft_alloc_cpy(i, k, arg->str, arg->flag);
	k = 0;
	while (ft_isdigit(arg->str[i + k]) == 1 || arg->str[i + k] == '*')
		k++;
	arg->cwidth = ft_strnew(k);
	i = ft_alloc_cpy(i, k, arg->str, arg->cwidth);
	k = 0;
	while (ft_isprec(arg->str[i + k]))
		k++;
	arg->cprecision = ft_strnew(k);
	i = ft_alloc_cpy(i, k, arg->str, arg->cprecision);
	k = 0;
	arg->length = ft_strnew(k);
	while (ft_islength(arg->str[i + k]) == 1)
		k++;
	i = ft_alloc_cpy(i, k, arg->str, arg->length);
	arg->specifier = arg->str[i];
}

void		ft_gest_arg(t_print *arg)
{
	ft_init_arg(arg);
	ft_split_arg(arg);
	ft_conv_arg(arg);
}
