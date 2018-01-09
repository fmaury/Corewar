/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:44:23 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 14:54:21 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_flagor_header(t_asm *sfile, int flag)
{
	if (flag != -2)
	{
		if (!sfile->name)
			ft_printf("Error: Name missing\n");
		else if (!sfile->comment)
			ft_printf("Error: Comment missing\n");
	}
	else if (flag == -2)
	{
		if (!sfile->name)
			ft_printf("Error: Name wrong format\n");
		else if (!sfile->comment)
			ft_printf("Error: Comment wrong format\n");
	}
	return (0);
}

int			ft_isgood_fmt(char *str)
{
	int		i;

	i = 1;
	if (str && str[0] == '"')
	{
		while (str[i] && str[i] != '"')
			i++;
		if (str[i] != '"')
			return (0);
		if (str[i + 1] == '\0')
			return (1);
		while (ft_isspace(str[i + 1]))
			i++;
		if (str[i + 1] == '\0' || str[i + 1] == COMMENT_CHAR)
			return (1);
	}
	return (0);
}

int			ft_chk_name_com(t_asm *sfile, char **tab, int flag)
{
	if (flag == 0 && tab && tab[0] && ft_strcmp(tab[0],
				NAME_CMD_STRING) == 0)
	{
		if (ft_isgood_fmt(tab[1]))
			sfile->name = ft_strdup(ft_erase_dc(tab[1]));
		else
			flag = -2;
	}
	else if (flag == 1 && tab && tab[0] && ft_strcmp(tab[0],
				COMMENT_CMD_STRING) == 0)
	{
		if (ft_isgood_fmt(tab[1]))
			sfile->comment = ft_strdup(ft_erase_dc(tab[1]));
		else
			flag = -2;
	}
	else
		flag = -1;
	return (flag);
}

int			ft_parse_head(t_asm *sfile, char *line, int flag)
{
	char	**tab;

	if (line && line[0] != '\0' && line[0] != '\n' && line[0] != COMMENT_CHAR)
	{
		tab = ft_strsplitnbif(line, ft_isspace, 1);
		flag = ft_chk_name_com(sfile, tab, flag);
		ft_free_strtab(tab);
		if (flag < 0)
			return (flag);
		flag++;
	}
	return (flag);
}

int			ft_head(t_asm *sfile)
{
	int		i;
	int		ret;
	int		flag;
	char	*line;

	i = 0;
	flag = 0;
	while (flag >= 0 && flag < 2 && (ret = get_next_line(sfile->fd, &line) > 0))
	{
		flag = ft_parse_head(sfile, ft_erspace(line), flag);
		ft_strdel(&line);
		i++;
	}
	if (ret < 0 || !sfile->name || !sfile->comment)
		return (ft_flagor_header(sfile, flag));
	if (ft_strlen(sfile->name) > PROG_NAME_LENGTH ||
			ft_strlen(sfile->comment) > COMMENT_LENGTH)
	{
		ft_strlen(sfile->name) > PROG_NAME_LENGTH ?
ft_printf("Error: Name too long\n") : ft_printf("Error: Comment too long\n");
		return (0);
	}
	ft_set_header(sfile);
	return (i);
}
