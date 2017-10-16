/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trt_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:28:40 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/11 11:07:01 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_trt_lenint(t_print *arg)
{
	if (arg->length[0] == 'h' && arg->length[1] == 'h')
		arg->sign = (signed char)va_arg(*arg->ap, int);
	else if (arg->length[0] == 'h')
		arg->sign = (short int)va_arg(*arg->ap, int);
	else if (arg->length[0] == 'l' && arg->length[1] == 'l')
		arg->sign = va_arg(*arg->ap, long long int);
	else if (arg->length[0] == 'l')
		arg->sign = va_arg(*arg->ap, long int);
	else if (arg->length[0] == 'j')
		arg->sign = va_arg(*arg->ap, intmax_t);
	else if (arg->length[0] == 'z')
		arg->sign = va_arg(*arg->ap, size_t);
	else
		arg->sign = va_arg(*arg->ap, int);
}

void	ft_prec_int(t_print *arg, t_flag *flag)
{
	flag->zero = 0;
	if (arg->precision == 0 && arg->sign == 0)
	{
		ft_strdel(&arg->res);
		arg->res = ft_strdup("\0");
		arg->len = 0;
		arg->precision = 0;
	}
}

char	*ft_trt_int(t_print *arg, t_flag *flag)
{
	char	*str;
	int		len;

	len = 0;
	str = NULL;
	if (arg->specifier == 'D')
		arg->length[0] = 'l';
	ft_trt_lenint(arg);
	if (arg->sign < 0)
	{
		flag->plus = 0;
		flag->space = 0;
		arg->precision++;
	}
	if (flag->zero == 1 && flag->space == 1)
		arg->width--;
	arg->res = ft_itoa(arg->sign);
	arg->len = ft_strlen(arg->res);
	if (arg->cprecision[0] == '.')
		ft_prec_int(arg, flag);
	str = ft_trt_pwf(arg, flag);
	return (str);
}
