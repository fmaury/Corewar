/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:42:43 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 17:34:17 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_tab[17];

int		ft_check_args(char *arg, int itab, int i, t_champ *champ)
{
	if (arg[0] == 'r' && ft_isstrdigit(arg + 1) && (g_tab[itab].arg[i] == 3
				|| g_tab[itab].arg[i] == 5 || g_tab[itab].arg[i] == 7 ||
				g_tab[itab].arg[i] == 1))
		champ->size += REG_SIZE;
	else if (arg[0] == DIRECT_CHAR && (arg[1] == ':' || ft_isstrdigit(arg + 1))
			&& (g_tab[itab].arg[i] == 3 || g_tab[itab].arg[i] == 6 ||
			g_tab[itab].arg[i] == 7 || g_tab[itab].arg[i] == 2))
		champ->size += g_tab[itab].oind == 1 ? IND_SIZE : DIR_SIZE;
	else if (ft_isstrdigit(arg) && (g_tab[itab].arg[i] == 5 ||
				g_tab[itab].arg[i] == 6 || g_tab[itab].arg[i] == 7 ||
				g_tab[itab].arg[i] == 4))
		champ->size += IND_SIZE;
	else
	{
		champ->err = 1;
		champ->errcode = 6;
		return (0);
	}
	champ->col += ft_strlen(arg) + ft_nb_split(champ->args, ft_strlen(arg) +
			champ->col - (ft_strlen(champ->op) + 1));
	return (1);
}

int		ft_param_err(t_champ *champ, char **arg, int itab)
{
	int		nbtab;

	nbtab = 0;
	while (arg[nbtab])
		nbtab++;
	if (nbtab < g_tab[itab].nbargs || (nbtab > g_tab[itab].nbargs
				&& arg[g_tab[itab].nbargs][0] != COMMENT_CHAR))
	{
		champ->err = 1;
		champ->errcode = nbtab < g_tab[itab].nbargs ? 4 : 5;
		ft_free_strtab(arg);
		return (0);
	}
	return (1);
}

int		ft_check_param(char *param, int itab, t_champ *champ)
{
	int		i;
	char	**arg;

	i = 0;
	if (!ft_check_separator(param, champ))
		return (0);
	arg = ft_strsplitif(param, ft_split_param);
	if (!ft_param_err(champ, arg, itab))
		return (0);
	while (arg[i] && i < g_tab[itab].nbargs)
	{
		if (!ft_check_args(arg[i], itab, i, champ))
		{
			ft_free_strtab(arg);
			return (0);
		}
		champ->arg = ft_strtab(champ->arg, arg[i]);
		i++;
	}
	ft_free_strtab(arg);
	return (1);
}

int		ft_no_param(char *op, t_champ *champ)
{
	int		i;

	i = 0;
	if (op[ft_strlen(op) - 1] == LABEL_CHAR)
	{
		champ->lab = 1;
		champ->label = ft_strdup(ft_erspace(op));
		if (ft_forbidden_char(op) != -1)
		{
			champ->err = 1;
			champ->errcode = 8;
			return (0);
		}
		return (1);
	}
	else
	{
		champ->err = 1;
		champ->op = ft_strdup(ft_erspace(op));
		if ((i = ft_find_op(op)) == -1)
			champ->errcode = 3;
		else
			champ->errcode = 4;
		return (0);
	}
}

int		ft_check(char *op, char *param, t_champ *champ)
{
	int		i;

	i = 0;
	if (op == NULL)
		return (0);
	if (param == NULL)
		return (ft_no_param(op, champ));
	champ->instr = 1;
	champ->op = ft_strdup(ft_erspace(op));
	champ->args = ft_strdup(param);
	if ((i = ft_find_op(op)) == -1)
	{
		champ->err = 1;
		champ->errcode = 3;
		return (0);
	}
	else
	{
		champ->opcode = i + 1;
		champ->col = ft_strlen(champ->op) + 1;
	}
	if (!ft_check_param(param, i, champ))
		return (0);
	return (1);
}
