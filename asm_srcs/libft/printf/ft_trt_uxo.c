/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trt_uxo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:37:34 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/11 11:04:05 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_trt_lenuxo(t_print *arg)
{
	if (arg->length[0] == 'h' && arg->length[1] == 'h')
		arg->usign = (unsigned char)va_arg(*arg->ap, int);
	else if (arg->length[0] == 'h')
		arg->usign = (unsigned short int)va_arg(*arg->ap, int);
	else if (arg->length[0] == 'l' && arg->length[1] == 'l')
		arg->usign = va_arg(*arg->ap, unsigned long long int);
	else if (arg->length[0] == 'l')
		arg->usign = va_arg(*arg->ap, unsigned long int);
	else if (arg->length[0] == 'j')
		arg->usign = va_arg(*arg->ap, uintmax_t);
	else if (arg->length[0] == 'z')
		arg->usign = va_arg(*arg->ap, size_t);
	else
		arg->usign = va_arg(*arg->ap, unsigned int);
}

void	ft_gest_uox(t_print *arg, t_flag *flag)
{
	if (arg->specifier == 'B' || arg->specifier == 'O' || arg->specifier == 'U')
	{
		free(arg->length);
		arg->length = ft_strdup("l");
		arg->specifier += 32;
	}
	ft_trt_lenuxo(arg);
	if (arg->specifier == 'u')
		arg->res = ft_itoa_base(arg->usign, 10);
	else if (arg->specifier == 'o')
		arg->res = ft_itoa_base(arg->usign, 8);
	else if (arg->specifier == 'x')
		arg->res = ft_itoa_base(arg->usign, 16);
	else if (arg->specifier == 'X')
		arg->res = ft_itoa_base_maj(arg->usign, 16);
	else
		arg->res = ft_itoa_base(arg->usign, 2);
	if (arg->usign == 0 && (arg->specifier == 'x' || arg->specifier == 'X' ||
		arg->specifier == 'b'))
		flag->sharp = 0;
	if (arg->usign == 0 && arg->cprecision[0] != '.' && arg->precision == 0 &&
			(arg->specifier == 'o' || arg->specifier == 'O'))
		flag->sharp = 0;
	arg->len = ft_strlen(arg->res);
}

void	ft_uox_prec(t_print *arg, t_flag *flag)
{
	if (arg->cprecision[0] == '.' && arg->precision == 0 && arg->usign == 0)
	{
		if (arg->specifier == 'x' || arg->specifier == 'X' ||
				arg->specifier == 'u' || arg->specifier == 'U' ||
				(flag->sharp == 0 && (arg->specifier == 'o'
				|| arg->specifier == 'O')))
		{
			ft_strdel(&arg->res);
			arg->res = ft_strdup("\0");
			flag->sharp = 0;
			arg->len = 0;
		}
		else
			arg->res[0] = '0';
		arg->precision = 0;
	}
	else if (flag->sharp == 1 && arg->specifier != 'u' && flag->zero == 0 &&
			arg->precision <= arg->len)
		ft_flg_shrp(arg);
}

char	*ft_trt_uxo(t_print *arg, t_flag *flag)
{
	char	*str;
	int		tmplen;
	int		tmprec;

	str = NULL;
	tmplen = 0;
	tmprec = 0;
	ft_gest_uox(arg, flag);
	tmplen = arg->len;
	tmprec = arg->precision;
	ft_uox_prec(arg, flag);
	str = ft_trt_pwf(arg, flag);
	if (flag->sharp == 1 && flag->zero == 1 && arg->width > 0 &&
			tmprec <= tmplen && (arg->specifier == 'x' ||
			arg->specifier == 'X' || arg->specifier == 'b'))
		ft_flg_shrp_es(arg, str);
	if (flag->sharp == 1 && tmprec > tmplen && (arg->specifier == 'x'
				|| arg->specifier == 'X' || arg->specifier == 'b'))
		str = ft_flg_precshrp(arg, str);
	return (str);
}
