/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trt_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:11:19 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/10 16:57:25 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_wp_flag(t_print *arg, t_flag *flag)
{
	char	*tmp;

	if ((flag->plus == 1 && arg->sign > 0) || flag->space == 1)
	{
		if (flag->plus == 1)
			tmp = ft_strdup("+");
		else
			tmp = ft_strdup(" ");
		arg->width++;
		arg->res = ft_strlf1join(tmp, arg->res, 1, arg->len);
	}
}

char	*ft_wp(t_print *arg, t_flag *flag)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = ft_strnew(arg->width - arg->len);
	if (flag->min == 1 && ((flag->plus == 1 && arg->sign > 0)
				|| flag->space == 1))
		arg->len++;
	while (arg->width-- - arg->len > 0)
		str[i++] = ' ';
	len = ft_strlen(str);
	if (flag->min == 0)
	{
		if (flag->plus == 1)
			str[i - 1] = '+';
		str = ft_strlf1join(str, arg->res, len, arg->len);
	}
	else
	{
		ft_wp_flag(arg, flag);
		str = ft_strlf2join(arg->res, str, arg->len, len);
	}
	arg->len += len;
	return (str);
}
