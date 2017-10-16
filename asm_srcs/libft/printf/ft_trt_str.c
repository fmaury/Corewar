/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trt_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:37:34 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/10 17:00:34 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_str_nnull(t_print *arg, char *save)
{
	if (ft_strlen(save) > 0)
	{
		if (arg->precision > 0)
		{
			arg->res = ft_strnew(arg->precision);
			ft_strncpy(arg->res, save, arg->precision);
		}
		else if (arg->cprecision[0] == '.' && arg->precision == 0)
			arg->res = ft_strdup("\0");
		else
			arg->res = ft_strdup(save);
	}
	else
	{
		arg->precision = 0;
		arg->res = ft_strdup("\0");
	}
}

char		*ft_utc(wchar_t *wsave, char *save, t_print *arg)
{
	int			type;
	int			i;
	int			tmp;
	int			total;

	i = 0;
	type = 0;
	total = 0;
	save = ft_strdup("\0");
	while (wsave[i])
	{
		tmp = total;
		arg->usign = wsave[i];
		type = ft_wich_stype(arg);
		ft_sconv_utf8(arg, type);
		save = ft_strlf1join(save, arg->res, total, type);
		total = total + type;
		if (total > arg->precision && arg->cprecision[0] == '.')
		{
			arg->precision = tmp;
			break ;
		}
		i++;
	}
	return (save);
}

char		*ft_trt_wchr(char *save, t_print *arg)
{
	wchar_t		*wsave;

	wsave = va_arg(*arg->ap, wchar_t*);
	if (wsave != NULL)
		save = ft_utc(wsave, save, arg);
	return (save);
}

void		ft_save_null(t_print *arg, t_flag *flag, char *save)
{
	flag->plus = 0;
	flag->space = 0;
	if (arg->precision > 0 || (arg->cprecision[0] == '.' &&
				arg->precision == 0))
	{
		save = ft_strdup("(null)");
		arg->res = ft_strnew(arg->precision);
		ft_strncpy(arg->res, save, arg->precision);
		free(save);
	}
	else
		arg->res = ft_strdup("(null)");
}

char		*ft_trt_str(t_print *arg, t_flag *flag)
{
	char		*str;
	char		*save;

	str = NULL;
	save = NULL;
	if (arg->specifier == 's' && arg->length[0] != 'l')
		save = va_arg(*arg->ap, char*);
	else
		save = ft_trt_wchr(save, arg);
	if (save != NULL)
		ft_str_nnull(arg, save);
	else
		ft_save_null(arg, flag, save);
	arg->precision = 0;
	arg->len = ft_strlen(arg->res);
	str = ft_trt_pwf(arg, flag);
	if (arg->specifier == 'S' || arg->length[0] == 'l')
		free(save);
	return (str);
}
