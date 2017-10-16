/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:39:43 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/11 11:14:24 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_frees(t_print *arg, int *tab)
{
	if (arg->err > 0)
		tab[3]++;
	free(arg->str);
	free(arg->cprecision);
	free(arg->cwidth);
	free(arg->flag);
	free(arg->length);
	ft_strdel(&arg->res);
}

static int		ft_trt_printf(t_print *arg, t_flag *flag, char **buf, int *tab)
{
	char		*str;

	ft_gest_arg(arg);
	ft_check_arg(arg, flag);
	str = ft_trt_spec(arg, flag);
	*buf = ft_strlf1join(*buf, str, tab[2], arg->len);
	free(str);
	tab[2] += arg->len;
	return (tab[1]);
}

static void		ft_init_printf(t_print *arg, t_flag *flag, int *tab, char **buf)
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	*buf = ft_strnew(1);
	ft_bzero(arg, sizeof(t_print));
	ft_bzero(flag, sizeof(t_flag));
}

static int		ft_end(char **buf, int *tab)
{
	if (tab[3] > 0)
	{
		free(*buf);
		return (-1);
	}
	write(1, *buf, tab[2]);
	free(*buf);
	return (tab[2]);
}

int				ft_printf(char *frmt, ...)
{
	va_list		ap;
	char		*buf;
	t_flag		flag;
	t_print		arg;
	int			tab[4];

	va_start(ap, frmt);
	ft_init_printf(&arg, &flag, tab, &buf);
	arg.ap = &ap;
	while (frmt[tab[0]])
	{
		if (frmt[tab[0]] == '%' && frmt[tab[0] + 1] != '\0')
		{
			tab[1] = ft_mk_str(frmt, &arg, tab[0] + 1);
			tab[0] = ft_trt_printf(&arg, &flag, &buf, tab);
			ft_frees(&arg, tab);
		}
		if (frmt[tab[0]] != '\0' && frmt[tab[0]] != '%')
			buf = ft_cljoin(buf, frmt[tab[0]++], tab[2]++);
		else if (frmt[tab[0]] == '%' && frmt[tab[0] + 1] == '\0')
			break ;
	}
	va_end(ap);
	return (ft_end(&buf, tab));
}
