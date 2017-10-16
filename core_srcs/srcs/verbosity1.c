/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbosity1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/21 18:14:24 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			vb_introduce(t_vm *vm)
{
	int			i;
	int			id_p;
	t_header	*h;

	if (vm->ncurse)
		return (0);
	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < vm->nb_players)
	{
		id_p = vm->players[i].index;
		h = &(vm->players[i].header);
		ft_printf("* Player %d, weighing %d bytes, ", id_p, h->prog_size);
		ft_printf("\"%s\" (\"%s\") !\n", h->prog_name, h->comment);
		i++;
	}
	return (1);
}

int			vb_cycles(t_vm *vm)
{
	if (!vm->procs || !(vm->verbose & 2))
		return (0);
	ft_printf("It is now cycle %d\n", vm->cycle);
	return (1);
}

int			vb_winner(t_vm *vm)
{
	int			win;
	t_player	*p;

	p = vm->last_player_live;
	win = p->index;
	ft_printf("Contestant %d, \"%s\", has won !\n", win, p->header.prog_name);
	return (1);
}

int			vb_pc_movement(t_vm *vm, t_proc *proc)
{
	int			i;
	int			tmp;

	if (!(vm->verbose & 16))
		return (0);
	i = 0;
	tmp = (proc->pc + proc->adv);
	ft_printf("ADV %d (0x%.4x -> 0x%.4x)", proc->adv, proc->pc, tmp);
	while (i < proc->adv)
	{
		tmp = (proc->pc + i) % MEM_SIZE;
		ft_printf(" %.2x", vm->arena[tmp].i);
		i++;
	}
	ft_printf(" \n");
	return (1);
}
