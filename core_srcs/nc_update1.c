/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_update1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/27 09:05:07 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			nc_put_pc(t_vm *vm, t_proc *proc, int put)
{
	int		j;
	int		i;
	int		cp;

	if (!vm->ncurse)
		return (0);
	j = proc->pc / 64;
	i = proc->pc % 64;
	if (put)
		cp = proc->cpair + 4;
	else
		cp = (int)(vm->colors[proc->pc]);
	wattron(vm->war, COLOR_PAIR(cp));
	mvwprintw(vm->war, j + 1, 3 * i + 1, "%.2x", vm->arena[proc->pc].i);
	wattroff(vm->war, COLOR_PAIR(cp));
	return (1);
}

static int	nc_update_info(t_vm *vm)
{
	int		j;
	int		i;
	int		cp;

	mvwprintw(vm->winfo, 5, 10, "%-10d", vm->cycle);
	j = 10;
	i = -1;
	mvwprintw(vm->winfo, 7, 14, "%d", ft_lstlen(vm->procs));
	while (++i < vm->nb_players)
	{
		cp = i + 1;
		wattron(vm->winfo, COLOR_PAIR(cp));
		mvwprintw(vm->winfo, j, 18, "% 5d", vm->players[i].last_live_cycle);
		mvwprintw(vm->winfo, j + 1, 18, "% 5d", vm->players[i].live_in_ctd);
		j += 4;
	}
	wattron(vm->winfo, COLOR_PAIR(10));
	mvwprintw(vm->winfo, j, 18, "% 10d", vm->ctd);
	return (1);
}

int			nc_loop(t_vm *vm)
{
	if (!vm->ncurse)
		return (0);
	if (g_resize)
	{
		endwin();
		nc_init(vm);
		g_resize = 0;
	}
	nc_update_info(vm);
	wrefresh(vm->win);
	wrefresh(vm->war);
	wrefresh(vm->winfo);
	usleep(1000000 / vm->cps);
	return (1);
}

static void	nc_winner_helper(t_vm *vm, t_player *p, int i, int loop)
{
	int		l;

	l = 60;
	wattron(vm->war, COLOR_PAIR(loop % 2 ? 11 : 9));
	mvwprintw(vm->war, i - 2, 50, "%*c", l, ' ');
	mvwprintw(vm->war, i - 1, 50, "%*c", l, ' ');
	mvwprintw(vm->war, i, 50, "%*c", l, ' ');
	mvwprintw(vm->war, i, 50,
			"   THE WINNER IS %.10s", p->header.prog_name);
	mvwprintw(vm->war, i + 1, 50, "%*c", l, ' ');
	mvwprintw(vm->war, i + 2, 50, "%*c", l, ' ');
	mvwprintw(vm->war, i + 3, 50, "%*c", l, ' ');
	mvwprintw(vm->war, i + 3, 50, "press ESC to quit.");
	mvwprintw(vm->war, i + 4, 50, "%*c", l, ' ');
	mvwprintw(vm->war, i + 4, 50, "%60s", "created by TEAM Dinosaurus");
	wattroff(vm->war, COLOR_PAIR(loop % 2 ? 11 : 9));
	wrefresh(vm->war);
}

int			nc_winner(t_vm **avm)
{
	t_player	*p;
	int			i;
	static int	loop = 0;
	t_vm		*vm;

	vm = *avm;
	if (!vm->ncurse || vm->quit)
		return (0);
	if (vm->sound)
		system("killall afplay 2&>/dev/null >/dev/null\n afplay \
				./sounds/endgame.mp3&");
	i = 30;
	p = vm->last_player_live;
	init_pair(11, COLOR_BLACK, COLOR_MAGENTA);
	while (!vm->quit)
	{
		nc_event_handling(avm);
		nc_winner_helper(vm, p, i, loop);
		loop = loop ? 0 : 1;
	}
	return (1);
}
