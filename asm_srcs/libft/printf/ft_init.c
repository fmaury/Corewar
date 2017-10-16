/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:08:09 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/25 17:24:27 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_init_arg(t_print *arg)
{
	arg->cprecision = NULL;
	arg->cwidth = NULL;
	arg->precision = 0;
	arg->width = 0;
	arg->flag = NULL;
	arg->length = NULL;
	arg->len = 0;
	arg->err = 0;
	arg->specifier = '\0';
}

void	ft_init_flag(t_flag *flag)
{
	flag->sharp = 0;
	flag->zero = 0;
	flag->plus = 0;
	flag->min = 0;
	flag->space = 0;
}
