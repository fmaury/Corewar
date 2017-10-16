/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trt_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:37:34 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/25 17:08:43 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_trt_point(t_print *arg, t_flag *flag)
{
	char	*str;

	str = NULL;
	arg->specifier = 'x';
	arg->usign = va_arg(*arg->ap, unsigned long int);
	if (arg->cprecision[0] == '.' && arg->precision == 0 && arg->usign == 0)
		arg->res = ft_strdup("\0");
	else
		arg->res = ft_itoa_base(arg->usign, 16);
	if (arg->precision > (int)ft_strlen(arg->res))
		arg->precision = arg->precision + 2;
	arg->len = ft_strlen(arg->res);
	ft_flg_shrp(arg);
	str = ft_trt_pwf(arg, flag);
	if (arg->precision > (int)ft_strlen(arg->res) - 2)
		str = ft_frm_point(str);
	return (str);
}
