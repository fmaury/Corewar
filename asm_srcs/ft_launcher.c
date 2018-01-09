/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:20:45 by agiulian          #+#    #+#             */
/*   Updated: 2017/10/05 17:33:38 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_check_error(char *file, t_asm *sfile, char *rnm, int oa)
{
	int		len;

	len = ft_strlen(file);
	if (len < 2 || file[len - 1] != 's' || file[len - 2] != '.')
	{
		ft_putstr("Error: Bad file extension, should be a '.s'\n");
		return (0);
	}
	else if ((sfile->fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Error: Can't open the file\n");
		return (0);
	}
	if (file)
	{
		sfile->origin = ft_strdup(file);
		file[ft_strlen(file) - 1] = '\0';
	}
	if (oa == 1)
		sfile->file = ft_strjoin(rnm, ".cor");
	else
		sfile->file = ft_strjoin(file, "cor");
	return (1);
}

void			ft_free_lst(t_champ *champ)
{
	t_champ *tmp;

	while (champ)
	{
		tmp = champ->next;
		if (champ->line)
			free(champ->line);
		if (champ->label)
			free(champ->label);
		if (champ->op)
			free(champ->op);
		if (champ->args)
			free(champ->args);
		if (champ->arg)
			ft_free_strtab(champ->arg);
		if (champ->param)
			free(champ->param);
		free(champ);
		champ = tmp;
	}
}

void			ft_free_struct(t_asm *sfile)
{
	if (sfile->origin)
		free(sfile->origin);
	if (sfile->name)
		free(sfile->name);
	if (sfile->file)
		free(sfile->file);
	if (sfile->comment)
		free(sfile->comment);
	if (sfile->code)
		free(sfile->code);
}

int				ft_launcher(char *file, char *rnm, int oa)
{
	t_asm	sfile;
	t_champ	*champ;
	int		i;

	i = 0;
	champ = NULL;
	ft_bzero(&sfile, sizeof(t_asm));
	if (oa < 4)
	{
		if (ft_check_error(file, &sfile, rnm, oa) && (i = ft_head(&sfile)) &&
				ft_asm(&sfile, champ, i))
		{
			if (oa > 1)
				ft_aff(&sfile, sfile.champ);
			else
				ft_write(&sfile, sfile.champ);
		}
	}
	else
		ft_reverse(file, &sfile);
	ft_free_lst(sfile.champ);
	ft_free_struct(&sfile);
	return (0);
}
