/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:48:53 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/29 16:14:31 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_tab[17];

void	ft_byte_instr(t_champ *champ)
{
	int				i;
	int				res;

	res = 0;
	i = ft_find_op(champ->op);
	if (!g_tab[i].ocod)
	{
		i = 0;
		ft_putstr("\t\t");
		while (i < champ->size)
		{
			ft_printf("%d  ", champ->param[i + 1]);
			res <<= 8;
			res |= champ->param[i + 1];
			i++;
		}
		champ->size == 4 ? ft_printf("\n\t\t\t\t\t%d\n", res)
			: ft_printf("\n\t\t\t\t\t%hd\n", res);
		return ;
	}
	ft_printf("  %d\t\t", champ->codage);
	ft_aff_param(champ);
	ft_printf("\n\t\t\t%d  %d\t\t", champ->opcode, champ->codage);
	ft_aff_res(champ);
}

void	ft_aff_instr(t_champ *champ, int size)
{
	int		i;

	i = 0;
	ft_printf("%d	(%d):		%s", size, ft_size(champ), champ->op);
	while (champ->arg[i])
	{
		ft_printf("\t\t%s\t", champ->arg[i]);
		i++;
	}
	ft_printf("\n\t\t\t%d", champ->opcode);
	ft_byte_instr(champ);
	ft_putstr("\n\n");
}

void	ft_aff(t_asm *sfile, t_champ *champ)
{
	int		size;
	int		i;

	size = 0;
	ft_printf("Progam size: %d bytes\nName: %s\nComment: %s\n\n",
			ft_total_size(champ), sfile->name, sfile->comment);
	while (champ)
	{
		i = 0;
		if (champ->lab)
			ft_printf("%d	   :	%s\n", size, champ->label);
		else if (champ->instr)
		{
			ft_aff_instr(champ, size);
		}
		size += ft_size(champ);
		champ = champ->next;
	}
}
