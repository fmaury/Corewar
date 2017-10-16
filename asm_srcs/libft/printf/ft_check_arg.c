/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:01:12 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/27 09:50:09 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_struct_flag(t_print *arg, t_flag *flag)
{
	int i;

	i = 0;
	ft_init_flag(flag);
	while (arg->flag[i])
	{
		if (arg->flag[i] == '#')
			flag->sharp = 1;
		else if (arg->flag[i] == '0')
			flag->zero = 1;
		else if (arg->flag[i] == '+')
			flag->plus = 1;
		else if (arg->flag[i] == '-')
			flag->min = 1;
		else if (arg->flag[i] == ' ')
			flag->space = 1;
		i++;
	}
}

void	ft_check_flag(t_print *arg, t_flag *flag)
{
	ft_struct_flag(arg, flag);
	if (flag->zero == 1 && flag->min == 1)
		flag->zero = 0;
	if (flag->sharp == 1 && ft_isxo(arg->specifier) == 0)
		flag->sharp = 0;
	if (flag->space == 1 && (flag->plus == 1 || arg->specifier == 'p' ||
				arg->specifier == '%' || arg->specifier == 'u' ||
				arg->specifier == 'x' || arg->specifier == 'X' ||
				arg->specifier == 'o' || arg->specifier == 'O' ||
				arg->specifier == 'c' || arg->specifier == 'C' ||
				arg->specifier == 's' || arg->specifier == 'S'))
		flag->space = 0;
	if (flag->plus == 1 && (arg->specifier == 'x' || arg->specifier == 'X'
				|| arg->specifier == 'o' || arg->specifier == 'O' ||
				arg->specifier == 'p' || arg->specifier == '%' ||
				arg->specifier == 'u' || arg->specifier == 'c' ||
				arg->specifier == 'C' || arg->specifier == 's' ||
				arg->specifier == 'S'))
		flag->plus = 0;
	if (arg->width < 0)
	{
		flag->min = 1;
		arg->width = -arg->width;
	}
}

int		ft_check_arg(t_print *arg, t_flag *flag)
{
	ft_check_flag(arg, flag);
	return (0);
}
