/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 13:16:47 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/10 17:34:53 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_launcher(argv[1]);
	else
		ft_printf("Usage: ./asm [-a] <sourcefile.s>\n");
	return (0);
}
