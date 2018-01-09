/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pcb_n_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/29 13:40:00 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			init_proc(t_vm *vm, t_proc *proc, int pc)
{
	ft_bzero(proc->param, 3 * sizeof(int));
	ft_bzero(proc->psize, 3 * sizeof(int));
	ft_bzero(proc->ptype, 3 * sizeof(int));
	if (!ft_lstany(vm->blinks, is_blk, &(proc->pc)))
		nc_put_pc(vm, proc, 0);
	proc->op_code = getnbytes(vm, pc, 1, 0);
	proc->pc = pc;
	nc_put_pc(vm, proc, 1);
	proc->ipc = proc->pc;
	proc->adv = 1;
	proc->error_pcb = 0;
	if (!(proc->op_code > 0 && proc->op_code < 17))
	{
		proc->op_code = -1;
		inc_pc(proc, 1);
		proc->exec_in = 1;
		return (0);
	}
	proc->op_code--;
	proc->exec_in = g_tab[proc->op_code].cycle_to_wait;
	if (g_tab[proc->op_code].pcb)
		proc->adv = 2;
	inc_pc(proc, 1);
	return (1);
}

static int	set_types(t_proc *proc, int i, int type_code)
{
	if (type_code == REG_CODE)
	{
		proc->error_pcb = g_tab[proc->op_code].param[i] & T_REG ?
			proc->error_pcb : 1;
		proc->ptype[i] = T_REG;
		proc->psize[i] = 1;
	}
	else if (type_code == IND_CODE)
	{
		proc->error_pcb = g_tab[proc->op_code].param[i] & T_IND ?
			proc->error_pcb : 1;
		proc->ptype[i] = T_IND;
		proc->psize[i] = IND_SIZE;
	}
	else if (type_code == DIR_CODE)
	{
		proc->error_pcb = g_tab[proc->op_code].param[i] & T_DIR ?
			proc->error_pcb : 1;
		proc->ptype[i] = T_DIR;
		proc->psize[i] = g_tab[proc->op_code].var ? 2 : DIR_SIZE;
	}
	return (1);
}

static int	get_param(t_vm *vm, t_proc *proc, int i, int t)
{
	if (!set_types(proc, i, t))
	{
		proc->error_pcb = 1;
		return (0);
	}
	proc->param[i] = getnbytes(vm, proc->ipc, proc->psize[i], 0);
	if (proc->psize[i] == 2)
		proc->param[i] = (short int)(proc->param[i]);
	inc_pc(proc, proc->psize[i]);
	return (proc->psize[i]);
}

int			parse_pcb_n_param(t_vm *vm, t_proc *proc)
{
	int		pcb;
	int		i;
	int		t;

	if (proc->op_code < 0)
		return (0);
	if (g_tab[proc->op_code].pcb)
	{
		pcb = getnbytes(vm, proc->ipc, 1, 0);
		inc_pc(proc, 1);
	}
	else
		pcb = 0b10000000;
	i = 0;
	while (i < g_tab[proc->op_code].nb_params)
	{
		t = (pcb >> (6 - 2 * i)) & 0x03;
		proc->adv += get_param(vm, proc, i, t);
		i++;
	}
	return (!proc->error_pcb);
}
