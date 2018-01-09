/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_print_res.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:12:18 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/29 16:13:11 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_tab[17];

int		ft_tmp_to_i(int tmp, t_champ *champ)
{
	int			i;

	i = 0;
	if (tmp == 1)
		i = 1;
	else if (tmp == 2)
	{
		if (g_tab[ft_find_op(champ->op)].oind)
			i = 2;
		else
			i = 4;
	}
	else if (tmp == 3)
		i = 2;
	return (i);
}

int		ft_print_res(unsigned char tmp, t_champ *champ, int arg, int size)
{
	int				i;
	int				j;
	unsigned int	res;

	i = 0;
	j = 0;
	res = 0;
	i = ft_tmp_to_i(tmp, champ);
	while (j < i)
	{
		res <<= 8;
		res |= champ->param[size + j];
		j++;
	}
	tmp == 2 && champ->arg[arg][1] != LABEL_CHAR ?
		ft_printf("%s", champ->arg[arg] + 1) : ft_printf("%d", res);
	(tmp < 3) ? ft_putstr("\t\t\t") : ft_putstr("\t\t");
	return (i);
}

void	ft_aff_res(t_champ *champ)
{
	int				j;
	int				size;
	unsigned char	tmp;
	int				k;

	j = 3;
	size = 2;
	k = 0;
	while (j > 0 && k < g_tab[ft_find_op(champ->op)].nbargs)
	{
		tmp = champ->param[1] >> 2 * j;
		tmp = tmp & 0x03;
		size += ft_print_res(tmp, champ, k, size);
		j--;
		k++;
	}
}

int		ft_print_instr(unsigned char tmp, t_champ *champ, int size)
{
	int				i;
	int				j;
	unsigned int	res;

	i = 0;
	j = 0;
	res = 0;
	i = ft_tmp_to_i(tmp, champ);
	while (j < i)
	{
		ft_printf("%d ", champ->param[size + j]);
		j++;
	}
	(j < 3) ? ft_putstr("\t\t\t") : ft_putstr("\t\t");
	return (i);
}

void	ft_aff_param(t_champ *champ)
{
	int				j;
	int				size;
	unsigned char	tmp;

	j = 3;
	size = 2;
	while (j > 0)
	{
		tmp = champ->param[1] >> 2 * j;
		tmp = tmp & 0x03;
		size += ft_print_instr(tmp, champ, size);
		j--;
	}
}
