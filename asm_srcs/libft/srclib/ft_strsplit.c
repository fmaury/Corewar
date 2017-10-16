/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:02:38 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/18 10:20:46 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmpt_mot(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			j++;
		}
	}
	return (j);
}

static int	ft_cmpt_lettres(char const *s, char c, int curs)
{
	int		i;

	i = 0;
	while (s[curs] != c && s[curs] != '\0')
	{
		curs++;
		i++;
	}
	return (i);
}

static int	ft_curs(char const *s, char c, int curs)
{
	while (s[curs] == c && s[curs])
		curs++;
	return (curs);
}

static char	**ft_write(char const *s, char c, char **tab)
{
	int		tabint[4];

	tabint[0] = 0;
	tabint[1] = 0;
	tabint[2] = 0;
	while (tabint[0] < ft_cmpt_mot(s, c))
	{
		tabint[2] = ft_curs(s, c, tabint[2]);
		tabint[1] = ft_cmpt_lettres(s, c, tabint[2]);
		if (!(tab[tabint[0]] = (char *)malloc(sizeof(char) * tabint[1] + 1)))
			return (NULL);
		tabint[3] = 0;
		while (tabint[3] < tabint[1])
		{
			tab[tabint[0]][tabint[3]] = s[tabint[2]];
			tabint[2]++;
			tabint[3]++;
		}
		tab[tabint[0]][tabint[3]] = '\0';
		tabint[0]++;
	}
	tab[tabint[0]] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(tab) * ft_cmpt_mot(s, c) + 1)))
		return (NULL);
	return (ft_write(s, c, tab));
}
