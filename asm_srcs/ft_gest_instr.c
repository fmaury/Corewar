/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gest_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:11:19 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/27 18:03:03 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_gest_reg(t_champ *champ, int size, int i)
{
	size += REG_SIZE;
	champ->param[size] = ft_atoi(champ->arg[i] + 1);
	champ->codage |= REG_CODE;
	return (size);
}

int		ft_gest_ind(t_champ *champ, int size, int i)
{
	int		res;

	res = 0;
	size += IND_SIZE;
	champ->codage |= IND_CODE;
	res = ft_atoi(champ->arg[i]);
	ft_fill_param(champ, res, size, 1);
	return (size);
}

int		ft_gest_index(t_champ *champ, int size, int i)
{
	int		res;

	res = 0;
	if (ft_strcmp(champ->op, "live") == 0)
	{
		size += 3;
		res = ft_atoi(champ->arg[i] + 1);
		ft_fill_param(champ, res, size, 3);
	}
	else if (ft_strcmp(champ->op, "zjmp") == 0 ||
			ft_strcmp(champ->op, "sti") == 0 || ft_strcmp(champ->op,
				"fork") == 0 || ft_strcmp(champ->op, "lfork") == 0)
	{
		size += IND_SIZE;
		res = ft_atoi(champ->arg[i] + 1);
		ft_fill_param(champ, res, size, 1);
	}
	else
	{
		size += DIR_SIZE;
		res = ft_atoi(champ->arg[i] + 1);
		ft_fill_param(champ, res, size, 3);
	}
	return (size);
}

int		ft_gest_dir(t_champ *champ, t_champ *save, int size, int i)
{
	int		res;

	res = 0;
	if (champ->arg[i][1] == LABEL_CHAR)
	{
		if (!ft_strcmp(champ->op, "live"))
			size += 3;
		else
			size += IND_SIZE;
		if ((res = ft_label(champ->arg[i] + 2, champ, save)) == -1)
		{
			champ->err = 1;
			champ->errcode = 7;
			ft_col(champ);
			return (0);
		}
		if (!ft_strcmp(champ->op, "live"))
			ft_fill_param(champ, res, size, 3);
		else
			ft_fill_param(champ, res, size, 1);
	}
	else
		size = ft_gest_index(champ, size, i);
	champ->codage |= DIR_CODE;
	return (size);
}
