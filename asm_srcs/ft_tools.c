/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:49:13 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 17:32:37 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_tab[17];

int		ft_nb_split(char *str, int i)
{
	int		nb;

	nb = 0;
	while (ft_split_param(str[i + nb]))
		nb++;
	return (nb);
}

int		ft_split_param(char c)
{
	if (ft_isspace(c) || c == SEPARATOR_CHAR)
		return (1);
	return (0);
}

int		ft_find_op(char *op)
{
	int		i;

	i = 0;
	while (g_tab[i].param && ft_strcmp(g_tab[i].param, op) != 0)
		i++;
	if (g_tab[i].param == 0)
		return (-1);
	return (i);
}

char	*ft_erspace(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	tmp = NULL;
	i = ft_strlen(str) - 1;
	while (i > 0 && ft_isspace(str[i]))
	{
		if (ft_isspace(str[i]))
			str[i] = '\0';
		i--;
	}
	while (str[j] && ft_isspace(str[j]))
		j++;
	tmp = str + j;
	return (tmp);
}

int		ft_forbidden_char(char *str)
{
	int		i;

	i = 0;
	while (str[i] && i < (int)ft_strlen(str) - 1)
	{
		if (ft_strchr(LABEL_CHARS, str[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}
