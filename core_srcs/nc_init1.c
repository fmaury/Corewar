/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_init1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/27 08:58:25 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	nc_init_colors(t_vm *vm)
{
	t_list		*elm;
	t_proc		*p;
	int			i;

	i = vm->nb_players;
	elm = vm->procs;
	ft_memset(vm->colors, 9, MEM_SIZE);
	while (elm)
	{
		p = (t_proc*)(elm->content);
		ft_memset(vm->colors + p->pc, p->cpair,
				(int)(vm->players[--i].header.prog_size));
		elm = elm->next;
	}
	return (1);
}

int			nc_init_pc(t_vm *vm)
{
	t_list		*elm;
	t_proc		*p;

	elm = vm->procs;
	while (elm)
	{
		p = (t_proc*)(elm->content);
		nc_put_pc(vm, p, 1);
		elm = elm->next;
	}
	return (1);
}

int			nc_init_arena(t_vm *vm)
{
	int		i;
	int		j;

	if (!vm->cycle)
		nc_init_colors(vm);
	j = 0;
	while (j < 64)
	{
		i = 0;
		while (i < 64)
		{
			wattron(vm->war, COLOR_PAIR((int)(vm->colors[j * 64 + i])));
			mvwprintw(vm->war, j + 1, 3 * i + 1, "%.2x",
					vm->arena[j * 64 + i].i);
			wattroff(vm->war, COLOR_PAIR((int)(vm->colors[j * 64 + i])));
			i++;
		}
		j++;
	}
	if (!vm->cycle)
		nc_init_pc(vm);
	wrefresh(vm->win);
	wrefresh(vm->war);
	nc_init_info(vm);
	return (1);
}

static int	nc_init_helper(t_vm *vm)
{
	if (!vm->cycle)
		signal(SIGWINCH, resize_handler);
	init_pair(9, COLOR_YELLOW, COLOR_BLACK);
	init_pair(10, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(12, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(13, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(14, COLOR_RED, COLOR_MAGENTA);
	init_pair(15, COLOR_CYAN, COLOR_MAGENTA);
	vm->win = newwin(68, 260, 0, 0);
	vm->war = newwin(66, 194, 1, 2);
	vm->winfo = newwin(68, 67, 0, 196);
	wattron(vm->win, COLOR_PAIR(10));
	wattron(vm->winfo, COLOR_PAIR(10));
	wborder(vm->win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wborder(vm->winfo, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	refresh();
	return (nc_init_arena(vm));
}

int			nc_init(t_vm *vm)
{
	if (!vm->ncurse)
		return (1);
	if (vm->sound)
		system("killall afplay 2&>/dev/null >/dev/null\n afplay \
			./sounds/soundtrack.mp3&");
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	start_color();
	init_color(COLOR_YELLOW, 420, 420, 420);
	init_color(COLOR_MAGENTA, 1000, 1000, 1000);
	assume_default_colors(COLOR_YELLOW, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	return (nc_init_helper(vm));
}
