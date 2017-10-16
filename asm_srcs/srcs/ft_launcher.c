/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:51:57 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/19 13:26:23 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_check_error(char *file, t_asm *sfile)
{
	int		len;
	char	**tab;

	len = ft_strlen(file);
	if (len < 2 || file[len - 1] != 's' || file[len - 2] != '.')
	{
		ft_printf("Mauvaise extension de fichier\n");
		return (0);
	}
	else if ((sfile->fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Erreur lors de l'ouverture du fichier\n");
		return (0);
	}
	tab = ft_strsplit(file, '.');
	sfile->origin = ft_strdup(file);
	sfile->file = ft_strjoin(tab[0], ".cor", 0);
	ft_free_strtab(tab);
	return (1);
}

void	ft_free_lst(t_champ *champ)
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

void	ft_free_struct(t_asm *sfile)
{
	if (sfile->origin)
		free(sfile->origin);
	if (sfile->name)
		free(sfile->name);
	if (sfile->file)
		free(sfile->file);
	if (sfile->comment)
		free(sfile->comment);
}

int		ft_launcher(char *file)
{
	t_asm	sfile;
	t_champ	*champ;
	int		i;

	i = 0;
	champ = NULL;
	ft_bzero(&sfile, sizeof(t_asm));
	if (ft_check_error(file, &sfile) && (i = ft_head(&sfile)) &&
			ft_asm(&sfile, champ, i))
		ft_write(&sfile, sfile.champ);
	ft_free_lst(sfile.champ);
	ft_free_struct(&sfile);
	return (0);
}
