/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:18:09 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/19 18:18:33 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_sep_err(t_champ *champ, int len, char **arg)
{
	champ->err = 1;
	champ->errcode = 9;
	champ->col = len;
	ft_free_strtab(arg);
	return (0);
}

int		ft_check_separator(char *param, t_champ *champ)
{
	int		i;
	int		flag;
	char	**arg;
	char	*tmp;

	i = 0;
	flag = 0;
	arg = ft_strsplitnbif(param, ft_iscom, 1);
	tmp = ft_erspace(arg[0]);
	while (tmp[i])
	{
		if (tmp[i] == SEPARATOR_CHAR)
		{
			if (flag)
				return (ft_sep_err(champ, ft_strlen(champ->op) + 1 + i, arg));
			flag++;
		}
		else
			flag = 0;
		i++;
	}
	if (tmp[ft_strlen(tmp) - 1] == SEPARATOR_CHAR)
		return (ft_sep_err(champ, ft_strlen(champ->op) + ft_strlen(tmp), arg));
	ft_free_strtab(arg);
	return (1);
}
