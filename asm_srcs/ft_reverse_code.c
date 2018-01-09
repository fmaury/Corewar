/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_code.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:31:11 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 14:59:16 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern t_op g_tab[17];

int		ft_rev_tmp_to_i(int tmp, int op)
{
	int			i;

	i = 0;
	if (tmp == 1)
		i = 1;
	else if (tmp == 2)
	{
		if (g_tab[op].oind)
			i = 2;
		else
			i = 4;
	}
	else if (tmp == 3)
		i = 2;
	return (i);
}

int		ft_rev_res(int i, t_asm *sfile, char *str, int size)
{
	int				j;
	int				res;
	char			*sres;

	j = 0;
	res = 0;
	while (j < i)
	{
		res <<= 8;
		res |= (unsigned char)str[j + size];
		j++;
	}
	sres = ft_itoa(i == 2 ? (short)res : res);
	sfile->code = ft_strjoinzfree(sfile->code, sres, 3);
	return (i);
}

int		ft_rev_param(t_asm *sfile, int op, char *str)
{
	int		i;
	int		j;
	int		size;
	char	*cop;
	int		tmp;

	j = 3;
	i = 0;
	size = 2;
	while (j > 0 && i < g_tab[op].nbargs)
	{
		tmp = str[1] >> (2 * j);
		tmp = tmp & 0x03;
		cop = tmp == 1 ? "r" : "%";
		sfile->code = ft_strjoinzfree(sfile->code, cop, 1);
		size += ft_rev_res(ft_rev_tmp_to_i(tmp, op), sfile, str, size);
		if (j - 1 > 0 && i < g_tab[op].nbargs - 1)
			sfile->code = ft_strjoinzfree(sfile->code, ", ", 1);
		j--;
		i++;
	}
	return (size);
}

int		ft_rev_nopcb(t_asm *sfile, char *str, int op)
{
	int		i;
	int		size;
	char	*sres;
	int		res;

	i = 0;
	res = 0;
	size = op == 0 ? 4 : 2;
	while (i < size)
	{
		res <<= 8;
		res |= (unsigned char)str[i + 1];
		i++;
	}
	sfile->code = ft_strjoinzfree(sfile->code, "%", 1);
	sres = ft_itoa(size == 2 ? (short)res : res);
	sfile->code = ft_strjoinzfree(sfile->code, sres, 3);
	return (size + 1);
}

void	ft_reverse_code(t_asm *sfile)
{
	char	*str;
	int		i;
	int		total;
	int		size;
	int		tmpsize;

	size = 0;
	tmpsize = 0;
	total = ft_get_size(sfile->bin);
	str = sfile->bin + (16 + PROG_NAME_LENGTH + COMMENT_LENGTH);
	while (size < total)
	{
		i = ft_rev_find_op(str[0]);
		sfile->code = ft_strjoinzfree(sfile->code, g_tab[i].param, 1);
		sfile->code = ft_strjoinzfree(sfile->code, "\t", 1);
		if (g_tab[i].ocod)
			tmpsize = ft_rev_param(sfile, i, str);
		else
			tmpsize = ft_rev_nopcb(sfile, str, i);
		str += tmpsize;
		size += tmpsize;
		sfile->code = ft_strjoinzfree(sfile->code, "\n", 1);
	}
}
