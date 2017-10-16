/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:50:40 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/20 14:44:37 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_aff(int argc, char **argv)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

int			ft_sort_params(int argc, char **argv)
{
	int		i;
	char	*c;

	i = 1;
	if (argc == 1)
		return (0);
	while (i != argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) <= 0)
		{
			i++;
		}
		else
		{
			c = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = c;
			i = 0;
		}
	}
	ft_aff(argc, argv);
	return (0);
}
