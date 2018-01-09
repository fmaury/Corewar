/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/05 17:38:21 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	kill_proc(void *arg_proc, void *arg_vm)
{
	t_proc		*proc;
	t_vm		*vm;
	int			tmp;

	proc = (t_proc*)(arg_proc);
	vm = (t_vm *)arg_vm;
	tmp = proc->alive;
	if (vm->ctd <= 0 || !tmp)
	{
		if (vm->sound)
			system("afplay ./sounds/process_kill.mp3& 2> /dev/null");
		if (vm->verbose & 8)
		{
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					proc->id, vm->cycle - proc->last_live_cycle, vm->ctd);
		}
	}
	proc->alive = 0;
	if (!tmp)
		nc_put_pc(vm, proc, 0);
	if (vm->ctd <= 0)
		return (1);
	return (!tmp);
}

static int	vm_rules(t_vm *vm)
{
	int			nb_pl;

	nb_pl = vm->nb_players;
	if (vm->ctd_cycle == vm->ctd || vm->ctd <= 0)
	{
		ft_lstfilter(&(vm->procs), free_proc, kill_proc, vm);
		if (vm->live_in_ctd >= NBR_LIVE || vm->check == MAX_CHECKS - 1)
		{
			vm->ctd -= CYCLE_DELTA;
			vm->check = 0;
			if (vm->verbose & 2)
				ft_printf("Cycle to die is now %d\n", vm->ctd);
		}
		else
			vm->check++;
		vm->live_in_ctd = 0;
		vm->ctd_cycle = 0;
		while (nb_pl--)
			vm->players[nb_pl].live_in_ctd = 0;
	}
	return (vm->procs ? 1 : 0);
}

static int	reset_proc(t_list *e, void *d)
{
	t_proc		*p;
	t_vm		*vm;

	p = (t_proc *)(e->content);
	vm = (t_vm *)d;
	if (!p->exec_in)
		init_proc(vm, p, p->ipc);
	return (1);
}

static int	vm_play(t_vm *vm)
{
	t_list	*elm;
	t_proc	*proc;

	elm = vm->procs;
	while (elm)
	{
		proc = (t_proc*)(elm->content);
		if (!--proc->exec_in)
		{
			if (parse_pcb_n_param(vm, proc))
				g_tab[proc->op_code].f(vm, proc);
			if (proc->op_code != -1)
				vb_pc_movement(vm, proc);
		}
		elm = elm->next;
	}
	ft_lstany(vm->procs, reset_proc, vm);
	return (1);
}

int			vm_core(t_vm **avm)
{
	while (!(*avm)->quit && (*avm)->dump != (*avm)->cycle && (*avm)->procs)
	{
		nc_event_handling(avm);
		if ((*avm)->ncurse && (!(*avm)->play || (*avm)->step == (*avm)->cycle))
		{
			if ((*avm)->prec)
				apply_new_vm(avm);
			continue;
		}
		store_vm(avm);
		(*avm)->cycle++;
		(*avm)->ctd_cycle++;
		vb_cycles(*avm);
		vm_play(*avm);
		vm_rules(*avm);
		ft_lstfilter(&((*avm)->blinks), free_blk, reset_blk, *avm);
		nc_loop(*avm);
	}
	(*avm)->play = -1;
	return (1);
}
