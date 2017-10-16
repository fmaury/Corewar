/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trt_wdth_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:25:12 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/10 16:59:22 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_wpl(t_print *arg, t_flag *flag)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = ft_strnew(arg->width - arg->len);
	while (arg->width - arg->precision > 0)
	{
		str[i] = ' ';
		i++;
		arg->width--;
	}
	if (flag->plus == 1 && (arg->sign >= 0))
		str[i - 1] = '+';
	while (arg->precision - arg->len > 0)
	{
		str[i] = '0';
		i++;
		arg->precision--;
	}
	len = ft_strlen(str);
	str = ft_strlf1join(str, arg->res, len, arg->len);
	arg->len += len;
	ft_pm(str, arg);
	return (str);
}

int		ft_mwpl_flg(char *str, t_flag *flag, t_print *arg)
{
	int		i;

	i = 0;
	if (flag->plus == 1 && arg->sign > 0)
	{
		str[i] = '+';
		arg->width--;
		i++;
	}
	else if (flag->space == 1)
	{
		str[i] = ' ';
		arg->width--;
		i++;
	}
	return (i);
}

char	*ft_mwpl(t_print *arg, t_flag *flag)
{
	int		i;
	int		prec;
	int		len;
	char	*str;
	char	*tmp;

	str = ft_strnew(arg->precision);
	tmp = ft_strnew(arg->width - arg->precision);
	prec = arg->precision;
	i = ft_mwpl_flg(str, flag, arg);
	while (arg->precision-- - arg->len > 0)
		str[i++] = '0';
	len = ft_strlen(str);
	str = ft_strlf1join(str, arg->res, len, arg->len);
	arg->len = arg->len + len;
	i = 0;
	while (arg->width-- - prec > 0)
		tmp[i++] = ' ';
	len = ft_strlen(tmp);
	str = ft_strlf2join(str, tmp, arg->len, len);
	arg->len += len;
	ft_pm(str, arg);
	return (str);
}
