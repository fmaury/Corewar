/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 13:16:47 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 14:56:50 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_msg_err(void)
{
	ft_printf("Usage: ./asm [-a][-o output file][-r] <sourcefile.s>\n\
	-a: print an annoted version of the code instead of creating a .cor file\n\
	-o: use the output file as name instead of the default name\n\
	-r: reverse the binary file\n");
	return (0);
}

char	*ft_pick_str(char **av, int i)
{
	if (ft_strcmp("--", av[i]))
		return (av[i]);
	else
	{
		if (av[i + 1])
			return (av[i + 1]);
	}
	return (NULL);
}

int		ft_parse_arg(int res, char **str_rnm, char **av, int i)
{
	if (res == -1)
		return (ft_msg_err());
	else if (res == 1 || res == 3)
	{
		if (av[i + 1])
		{
			if (av[i + 1][0] == '-')
				return (ft_msg_err());
			str_rnm[1] = av[i + 1];
		}
		i++;
	}
	else if (res == 0)
		str_rnm[0] = ft_pick_str(av, i);
	return (1);
}

int		main(int ac, char **av)
{
	int		i;
	int		oa;
	int		res;
	char	*str_rnm[3];

	oa = 0;
	i = 1;
	ft_bzero(str_rnm, sizeof(char*) * 3);
	if (ac < 2)
		return (ft_msg_err());
	while (av[i])
	{
		res = ft_check_main_args(av[i]);
		if (!ft_parse_arg(res, str_rnm, av, i))
			return (0);
		if (res == 0)
			break ;
		(res == 1 || res == 3) ? i += 2 : i++;
		if (oa < res)
			oa = res;
	}
	if (!str_rnm[0] || (oa == 1 && !str_rnm[1]) || av[i + 1])
		return (ft_msg_err());
	ft_launcher(str_rnm[0], str_rnm[1], oa);
	return (0);
}
