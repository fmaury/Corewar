/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:50:17 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/26 18:35:02 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_size_header(char *str, int size)
{
	if (size > 682)
	{
		ft_printf("Champion too big\n");
		return (0);
	}
	str[PROG_NAME_LENGTH + 10] = size >> 8;
	str[PROG_NAME_LENGTH + 11] = size & 0xff;
	return (1);
}

void			ft_fill_bin(t_asm *sfile, t_champ *champ)
{
	int				binlen;
	int				fd;
	int				size;
	unsigned char	*bin;
	unsigned char	*tmp;

	binlen = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	bin = ft_memalloc(binlen + ft_total_size(champ));
	ft_memcpy(bin, sfile->header, binlen);
	tmp = bin + binlen;
	while (champ)
	{
		if (champ->instr == 1)
		{
			size = ft_size(champ);
			ft_memcpy(tmp, champ->param, size);
			tmp += size;
			binlen += size;
		}
		champ = champ->next;
	}
	fd = open(sfile->file, O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
	write(fd, bin, binlen);
	free(bin);
	close(fd);
}

void			ft_write(t_asm *sfile, t_champ *champ)
{
	if (!ft_size_header(sfile->header, ft_total_size(champ)))
		return ;
	ft_fill_bin(sfile, champ);
	ft_printf("   Compilation succeeded.\n");
}
