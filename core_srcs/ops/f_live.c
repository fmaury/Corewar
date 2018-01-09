/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/27 08:13:15 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		vb_operation_live(t_vm *vm, t_proc *proc, int id)
{
	if (!(vm->verbose & 4))
		return (0);
	ft_printf("P %4d | live %d\n", proc->id, id);
	return (1);
}

static t_player	*get_player_by_id(t_vm *vm, int id)
{
	int		i;

	i = 0;
	while (i < vm->nb_players)
	{
		if (vm->players[i].id == id)
			return (vm->players + i);
		i++;
	}
	return (0);
}

int				f_live(t_vm *vm, t_proc *proc)
{
	int			id;
	t_player	*pl;

	id = proc->param[0];
	if ((pl = get_player_by_id(vm, id)))
	{
		if (vm->ncurse)
			make_it_blink(vm, proc);
		vm->last_player_live = pl;
		pl->last_live_cycle = vm->cycle;
		pl->live_in_ctd++;
	}
	vm->live_in_ctd++;
	proc->last_live_cycle = vm->cycle;
	proc->alive++;
	vb_operation_live(vm, proc, id);
	if (pl && (vm->verbose & 1))
		ft_printf("Player %d (%s) is said to be alive\n",
				pl->index, pl->header.prog_name);
	return (1);
}
