/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:44:53 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/08 13:16:04 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_magik_nbr(char *str)
{
	int		i;
	int		exe;

	i = 3;
	exe = COREWAR_EXEC_MAGIC;
	while (i >= 0)
	{
		str[i] = exe;
		exe >>= 8;
		i--;
	}
}

void		ft_dump_name(t_asm *sfile, int i)
{
	int		j;

	j = 0;
	while (sfile->name[j])
	{
		sfile->header[i + j] = sfile->name[j];
		j++;
	}
}

void		ft_dump_comment(t_asm *sfile, int i)
{
	int		j;

	j = 0;
	while (sfile->comment[j])
	{
		sfile->header[i + j] = sfile->comment[j];
		j++;
	}
}

int			ft_set_header(t_asm *sfile)
{
	ft_magik_nbr(sfile->header);
	ft_dump_name(sfile, 4);
	ft_dump_comment(sfile, PROG_NAME_LENGTH + 12);
	return (1);
}
