/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/05 18:50:52 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_comment(t_player *p)
{
	int		ret;

	if ((ret = read(p->fd, p->header.comment, COMMENT_LENGTH)) <= 0
		|| ret != COMMENT_LENGTH)
	{
		ft_fprintf(2, "Error: invalid header\n");
		return (0);
	}
	if ((ret = lseek(p->fd, 4, SEEK_CUR)) < 0)
	{
		ft_fprintf(2, "Error: lseek failed ret = %d\n", ret);
		return (0);
	}
	return (1);
}

static int	get_size(t_player *p)
{
	unsigned int	size;
	int				ret;
	t_mem			mem;

	if ((ret = read(p->fd, mem.c, 4)) != 4)
	{
		ft_fprintf(2, "Error: read failed ret = %d\n", ret);
		return (0);
	}
	size = mem.i[0];
	size = (size << 8) + mem.i[1];
	size = (size << 8) + mem.i[2];
	size = (size << 8) + mem.i[3];
	if (size > CHAMP_MAX_SIZE)
		return (0);
	p->header.prog_size = size;
	return (get_comment(p));
}

static int	get_name(t_player *p)
{
	int		ret;

	if ((ret = read(p->fd, p->header.prog_name, PROG_NAME_LENGTH)) <= 0
		|| ret != PROG_NAME_LENGTH)
	{
		ft_fprintf(2, "Error: invalid header\n");
		return (0);
	}
	if ((ret = lseek(p->fd, 4, SEEK_CUR)) < 0)
	{
		ft_fprintf(2, "Error: lseek failed ret = %d\n", ret);
		return (0);
	}
	return (get_size(p));
}

static int	get_magik(t_player *p)
{
	unsigned int	majik;
	int				ret;
	t_mem			mem;

	if ((ret = read(p->fd, mem.c, 4)) != 4)
	{
		ft_fprintf(2, "Error: read failed ret = %d\n", ret);
		return (0);
	}
	majik = mem.i[0];
	majik = (majik << 8) + mem.i[1];
	majik = (majik << 8) + mem.i[2];
	majik = (majik << 8) + mem.i[3];
	if (majik != COREWAR_EXEC_MAGIC)
	{
		ft_fprintf(2, "Error: wrong magic number : 0x%x", majik);
		return (0);
	}
	p->header.magic = majik;
	return (get_name(p));
}

int			parse_player(t_player *p)
{
	int		ret;

	if (!get_magik(p))
		return (0);
	if ((ret = read(p->fd, p->prog, CHAMP_MAX_SIZE + 1)) <= 0)
	{
		ft_fprintf(2, "Error: read failed ret = %d\n", ret);
		return (0);
	}
	if (ret > CHAMP_MAX_SIZE)
	{
		ft_fprintf(2, "Error: champ is too big\n");
		return (0);
	}
	if ((unsigned int)ret != p->header.prog_size)
	{
		ft_fprintf(2, "Error: sizes does not match\n");
		return (0);
	}
	return (1);
}
