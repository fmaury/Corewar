/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:27:01 by fmaury            #+#    #+#             */
/*   Updated: 2017/05/10 18:35:58 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_realloc(char **tab, char *str)
{
	char	**cpytab;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if (!(cpytab = ft_memalloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		cpytab[i] = ft_strdup(tab[i]);
		i++;
	}
	cpytab[i] = ft_strdup(str);
	cpytab[i + 1] = NULL;
	ft_free_strtab(tab);
	return (cpytab);
}

char	**ft_newtab(char *str)
{
	char	**tab;

	if (!(tab = ft_memalloc(sizeof(char*) * 2)))
		return (NULL);
	tab[0] = ft_strdup(str);
	tab[1] = NULL;
	return (tab);
}

char	**ft_strtab(char **tab, char *str)
{
	if (!tab)
		return (ft_newtab(str));
	else
		return (ft_tab_realloc(tab, str));
}
