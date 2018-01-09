/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:40:56 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 17:34:37 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_champ		*ft_lst(t_asm *sfile, t_champ *champ)
{
	if (champ == NULL)
	{
		champ = ft_memalloc(sizeof(t_champ));
		champ->next = NULL;
		sfile->champ = champ;
	}
	else
	{
		while (champ->next)
			champ = champ->next;
		champ->next = ft_memalloc(sizeof(t_champ));
		champ = champ->next;
		champ->next = NULL;
	}
	return (champ);
}

int			ft_precheck_hlpr(t_champ *champ, char **op_param, t_asm *sfile)
{
	int		res;
	char	**rop_param;

	rop_param = NULL;
	rop_param = ft_strsplitnbif(op_param[1], ft_isspace, 1);
	champ->lab = 1;
	champ->label = ft_strdup(ft_erspace(op_param[0]));
	if (ft_forbidden_char(op_param[0]) != -1)
	{
		champ->err = 1;
		champ->errcode = 8;
		return (0);
	}
	if (op_param[1][0] == LABEL_CHAR)
		return (1);
	champ = ft_lst(sfile, champ);
	champ->line = ft_strdup(op_param[1]);
	res = ft_check(rop_param[0], rop_param[1], champ);
	ft_free_strtab(rop_param);
	return (res);
}

int			ft_precheck(char **op_param, t_champ *champ, t_asm *sfile)
{
	if (op_param && op_param[0] && op_param[0][ft_strlen(op_param[0]) - 1]
			== LABEL_CHAR && op_param[1])
		return (ft_precheck_hlpr(champ, op_param, sfile));
	else
		return (ft_check(op_param[0], op_param[1], champ));
}

int			ft_parse(t_asm *sfile, t_champ *champ, int i)
{
	int		ret;
	int		err;
	char	*line;
	char	*tmp;
	char	**op_param;

	err = 0;
	while ((ret = get_next_line(sfile->fd, &line)) > 0)
	{
		tmp = ft_erspace(line);
		if (tmp && tmp[0] != '\0' && tmp[0] != '\n' && tmp[0] != COMMENT_CHAR)
		{
			champ = ft_lst(sfile, champ);
			champ->line = ft_strdup(tmp);
			champ->spbf = ft_space_bef(line);
			champ->ligne = i;
			op_param = ft_strsplitnbif(tmp, ft_isspace, 1);
			err = !ft_precheck(op_param, champ, sfile) ? 1 : err;
			ft_free_strtab(op_param);
		}
		i++;
		free(line);
	}
	free(line);
	return (ret == -1 || err == 1 ? 0 : 1);
}

int			ft_asm(t_asm *sfile, t_champ *champ, int i)
{
	if (!ft_parse(sfile, champ, i))
	{
		ft_error(sfile);
		return (0);
	}
	champ = sfile->champ;
	if (!ft_instr(champ))
	{
		ft_error(sfile);
		return (0);
	}
	return (1);
}
