/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:45:47 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/20 14:16:15 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_tab[17];

void	ft_fill_param(t_champ *champ, int res, int size, int i)
{
	while (i >= 0)
	{
		champ->param[size - i] = res >> (i * 8);
		i--;
	}
}

void	ft_fill_codage(t_champ *champ, int i)
{
	while (i < 4)
	{
		champ->codage <<= 2;
		i++;
	}
}

int		ft_set_instr(t_champ *champ, t_champ *save)
{
	int		i;
	int		size;

	i = 0;
	size = !ft_isspe(champ->op) || !ft_strcmp("live", champ->op) ? 1 : 0;
	while (champ->arg[i])
	{
		champ->codage <<= 2;
		if (champ->arg[i][0] == 'r')
			size = ft_gest_reg(champ, size, i);
		else if (champ->arg[i][0] == DIRECT_CHAR)
		{
			if (!(size = ft_gest_dir(champ, save, size, i)))
				return (0);
		}
		else
			size = ft_gest_ind(champ, size, i);
		i++;
	}
	ft_fill_codage(champ, i);
	return (1);
}

int		ft_instr(t_champ *champ)
{
	int		i;
	int		err;
	t_champ	*save;

	err = 0;
	save = champ;
	while (champ)
	{
		i = 0;
		if (champ->instr == 1)
		{
			champ->param = ft_memalloc(champ->size + 2);
			champ->param[0] = champ->opcode;
			if (!ft_set_instr(champ, save))
				err = 1;
			if (!ft_isspe(champ->op))
				champ->param[1] = champ->codage;
		}
		champ = champ->next;
	}
	if (err == 1)
		return (0);
	return (1);
}
