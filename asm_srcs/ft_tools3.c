/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:34:29 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 15:17:05 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_tab[17];

int		ft_size(t_champ *node)
{
	int		size;

	size = 0;
	if (node->instr == 1)
	{
		if (node->op && (ft_strcmp(node->op, "zjmp") == 0 || ft_strcmp(
				node->op, "live") == 0 || ft_strcmp(node->op, "fork") == 0 ||
				ft_strcmp(node->op, "lfork") == 0))
			size += node->size + 1;
		else
			size += node->size + 2;
	}
	node = node->next;
	return (size);
}

int		ft_total_size(t_champ *champ)
{
	int				total;

	total = 0;
	while (champ)
	{
		if (champ->instr == 1)
			total += ft_size(champ);
		champ = champ->next;
	}
	return (total);
}

int		ft_get_size(char *str)
{
	int		res;

	res = (unsigned char)str[PROG_NAME_LENGTH + 10];
	res <<= 8;
	res |= (unsigned char)str[PROG_NAME_LENGTH + 11];
	return (res);
}

int		ft_rev_find_op(int op)
{
	int		i;

	i = 0;
	while (g_tab[i].nbargs)
	{
		if (g_tab[i].opcode == op)
			return (i);
		i++;
	}
	return (i);
}
