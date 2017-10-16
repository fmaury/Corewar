/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gest_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:41:19 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/14 15:55:30 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_trt_err(t_print *arg, t_flag *flag)
{
	char *str;

	flag->plus = 0;
	flag->space = 0;
	arg->res = ft_strnew(1);
	arg->res[0] = arg->specifier;
	if (arg->res[0] != '\0')
		arg->len = 1;
	str = ft_trt_pwf(arg, flag);
	return (str);
}
