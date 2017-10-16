/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flg_shrp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:00:26 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/11 11:06:21 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_flg_precshrp(t_print *arg, char *str)
{
	int			i;
	int			j;
	char		*cpy;

	i = 0;
	j = 0;
	cpy = ft_strnew(ft_strlen(str) + 2);
	while (ft_isspace(str[i]) == 1)
		cpy[i++] = str[j++];
	if (i > 1)
		i -= 2;
	cpy[i] = '0';
	if (arg->specifier == 'x' || arg->specifier == 'X')
		cpy[i + 1] = (arg->specifier == 'x' ? 'x' : 'X');
	else
		cpy[i + 1] = 'b';
	i = i + 2;
	while (str[j])
		cpy[i++] = str[j++];
	arg->len += 2;
	free(str);
	return (cpy);
}

char		*ft_frm_point(char *str)
{
	int			i;
	char		*cpy;

	i = 0;
	cpy = ft_strdup(str);
	free(str);
	while (ft_isspace(cpy[i]) == 1)
		i++;
	cpy[i + 1] = 'x';
	i = i + 2;
	while (cpy[i] && cpy[i] != 'x')
		i++;
	cpy[i] = '0';
	return (cpy);
}

void		ft_flg_shrp_es(t_print *arg, char *str)
{
	if (arg->specifier == 'x')
		str[1] = 'x';
	else if (arg->specifier == 'X')
		str[1] = 'X';
	else if (arg->specifier == 'b')
		str[1] = 'b';
}

void		ft_flg_shrp(t_print *arg)
{
	char		*strd;

	if (arg->specifier == 'o' || arg->specifier == 'O')
	{
		strd = ft_strnew(arg->len + 1);
		strd[0] = '0';
		arg->len++;
	}
	else
	{
		strd = ft_strnew(arg->len + 2);
		strd[0] = '0';
		if (arg->specifier == 'x')
			strd[1] = 'x';
		else if (arg->specifier == 'X')
			strd[1] = 'X';
		else if (arg->specifier == 'b')
			strd[1] = 'b';
		arg->len += 2;
	}
	ft_strcat(strd, arg->res);
	ft_strdel(&arg->res);
	arg->res = strd;
}
