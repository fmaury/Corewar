/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/26 21:59:20 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			resize_handler(int s)
{
	(void)s;
	g_resize = 1;
}

static int		nc_put_info_players(t_vm *vm)
{
	int		i;
	int		j;
	char	*name;

	j = 9;
	i = 0;
	while (i < vm->nb_players)
	{
		wattron(vm->winfo, COLOR_PAIR(i + 1));
		name = vm->players[i].header.prog_name;
		mvwprintw(vm->winfo, j, 3, "Player % d : ", vm->players[i].id);
		mvwprintw(vm->winfo, j, 18, "%.10s", name);
		mvwprintw(vm->winfo, j + 1, 3, "Last live :");
		mvwprintw(vm->winfo, j + 1, 18, "%d", vm->players[i].last_live_cycle);
		mvwprintw(vm->winfo, j + 2, 3, "Lives in ctd :");
		mvwprintw(vm->winfo, j + 2, 18, "%d", vm->players[i].live_in_ctd);
		wattron(vm->winfo, COLOR_PAIR(10));
		j += 4;
		i++;
	}
	return (1);
}

static int		nc_put_info_const(t_vm *vm)
{
	int		j;

	j = 10 + 4 * vm->nb_players;
	mvwprintw(vm->winfo, j++, 3, "CYCLE_TO_DIE : % 10d", vm->ctd);
	mvwprintw(vm->winfo, j++, 3, "CYCLE_DELTA :  % 10d", CYCLE_DELTA);
	mvwprintw(vm->winfo, j++, 3, "NBR_LIVE :     % 10d", NBR_LIVE);
	mvwprintw(vm->winfo, j++, 3, "MAX_CHECKS :   % 10d", MAX_CHECKS);
	mvwprintw(vm->winfo, j + 3, 3, "Cycle/second : % 10d", vm->cps);
	return (1);
}

int				nc_init_info(t_vm *vm)
{
	mvwprintw(vm->winfo, 3, 3, "COREWAR by team Dinosaurus");
	mvwprintw(vm->winfo, 5, 3, "Cycle: %-10d", vm->cycle);
	mvwprintw(vm->winfo, 7, 3, "Processes: %d", ft_lstlen(vm->procs));
	nc_put_info_players(vm);
	nc_put_info_const(vm);
	wrefresh(vm->winfo);
	return (1);
}
