/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:05:09 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/20 14:16:22 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_iscom(char c)
{
	if (c == COMMENT_CHAR)
		return (1);
	return (0);
}

char	*ft_erase_dc(char *str)
{
	char	*tmp;

	tmp = str + 1;
	tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

int		ft_isspe(char *op)
{
	if (op && (ft_strcmp(op, "zjmp") == 0 || ft_strcmp(op, "live") == 0 ||
				ft_strcmp(op, "fork") == 0 || ft_strcmp(op, "lfork") == 0))
		return (1);
	return (0);
}

void	ft_col(t_champ *champ)
{
	int		i;

	i = 0;
	while (champ->line[i] != LABEL_CHAR)
		i++;
	champ->col = i - 1;
}
