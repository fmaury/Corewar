/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trt_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:19:01 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/10 17:02:29 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_pm(char *str, t_print *arg)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (arg->sign < 0)
	{
		while (str[i] != '0' && flag == 0 && str[i])
		{
			if (str[i] == '-')
				flag++;
			i++;
		}
		if (str[i] == '0')
		{
			str[i] = '-';
			i++;
			while (str[i] != '-' && str[i])
				i++;
			if (str[i] == '-')
				str[i] = '0';
		}
	}
}

char	*ft_pw(t_print *arg, t_flag *flag)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	str = ft_strnew(arg->precision - arg->len);
	if ((flag->plus == 1 && arg->sign >= 0) || flag->space)
	{
		str[0] = flag->space == 1 ? ' ' : '+';
		i++;
	}
	while (arg->precision - arg->len > 0)
	{
		str[i++] = '0';
		arg->precision--;
	}
	len = ft_strlen(str);
	str = ft_strlf1join(str, arg->res, len, arg->len);
	arg->len += len;
	ft_pm(str, arg);
	return (str);
}
