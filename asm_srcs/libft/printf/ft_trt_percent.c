/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trt_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:28:40 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/10 13:01:06 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_trt_percent(t_print *arg, t_flag *flag)
{
	char	*str;

	str = NULL;
	if (flag->zero == 1)
		arg->precision = arg->width;
	else
		arg->precision = 0;
	arg->res = ft_strnew(1);
	arg->res[0] = '%';
	arg->len = 1;
	str = ft_trt_pwf(arg, flag);
	return (str);
}
