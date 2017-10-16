/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:58:36 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/26 12:26:43 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "signal.h"

int			m0d(int offset, int mod)
{
	int				sign;
	unsigned int	res;

	sign = offset < 0 ? -1 : 1;
	res = (offset < 0 ? -offset : offset) % mod;
	return (sign * res);
}

static int	put_arena(t_vm *vm)
{
	int		i;
	int		j;

	j = 0;
	while (j < 64)
	{
		ft_printf("0x%.4x :", j * 64);
		i = 0;
		while (i < 64)
			ft_printf(" %.2x", vm->arena[64 * j + i++].i);
		j++;
		write(1, "\n", 1);
	}
	return (1);
}

static void	sigint_handler(int sig)
{
	(void)sig;
	system("killall afplay 2&>/dev/null >/dev/null\n");
	system("reset\n");
	exit(0);
}

int			main(int argc, char **argv)
{
	t_vm		vm;

	g_resize = 0;
	if (!init_vm(&vm, argc, argv))
		return (put_usage(argv));
	signal(SIGINT, sigint_handler);
	vb_introduce(&vm);
	nc_init(&vm);
	vm_core(&vm);
	nc_winner(&vm);
	if (vm.dump == vm.cycle)
		put_arena(&vm);
	else if (!vm.ncurse)
		vb_winner(&vm);
	free_vm(&vm);
	return (0);
}

int			put_usage(char **argv)
{
	ft_fprintf(2, "Usage: {red}%s{no} [-d N -v N -ncurse] ", argv[0]);
	ft_fprintf(2, "< [-n N] champion1.cor> <...>{1, 4}\n");
	ft_fprintf(2, "#### TEXT OUTPUT MODE ##############################");
	ft_fprintf(2, "############################\n");
	ft_fprintf(2, "-{grn}d{no} N  : Dumps memory after N cycles then ");
	ft_fprintf(2, "exits\n");
	ft_fprintf(2, "-{grn}n{no} N  : Gives the given id to the following");
	ft_fprintf(2, " champion (file .cor)\n");
	ft_fprintf(2, "-{grn}v{no} N  : Verbosity levels, can be added ");
	ft_fprintf(2, "together to enable several\n");
	ft_fprintf(2, " - {yel}0{no}  : Show only essentials\n");
	ft_fprintf(2, " - {yel}1{no}  : Show lives\n");
	ft_fprintf(2, " - {yel}2{no}  : Show cycles\n");
	ft_fprintf(2, " - {yel}4{no}  : Show operations ");
	ft_fprintf(2, "(Params are NOT litteral ...)\n");
	ft_fprintf(2, " - {yel}8{no}  : Show deaths\n");
	ft_fprintf(2, " - {yel}16{no} : Show PC movements (Except for jumps)\n");
	ft_fprintf(2, "#### NCURSES OUTPUT MODE ##############################");
	ft_fprintf(2, "##########################\n");
	ft_fprintf(2, "-{blu}ncurse{no} : Ncurses output mode with some ");
	ft_fprintf(2, "cool features\n");
	return (1);
}
