/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:35:23 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/20 11:38:37 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_prelabel(t_champ *node, char *label)
{
	int		size;

	size = 0;
	while (node)
	{
		if (node->instr == 1)
		{
			if (ft_isspe(node->op))
				size += node->size + 1;
			else
				size += node->size + 2;
		}
		if (node->lab == 1 && ft_strcmp(node->label, label) == 0)
			return (size);
		node = node->next;
	}
	return (-1);
}

int		ft_postlabel(t_champ *champ, t_champ *node)
{
	int		size;

	size = 0;
	while (node)
	{
		if (champ == node)
			return (-size);
		if (node->instr == 1)
		{
			if (ft_isspe(node->op))
				size += node->size + 1;
			else
				size += node->size + 2;
		}
		node = node->next;
	}
	return (-1);
}

int		ft_label(char *label, t_champ *champ, t_champ *save)
{
	char	*lab;
	int		size;

	lab = ft_strjoin(label, ":", 0);
	while (save)
	{
		if (save == champ)
		{
			size = ft_prelabel(save, lab);
			free(lab);
			return (size);
		}
		if (save->lab == 1 && ft_strcmp(lab, save->label) == 0)
		{
			size = ft_postlabel(champ, save);
			free(lab);
			return (size);
		}
		save = save->next;
	}
	free(lab);
	return (-1);
}
