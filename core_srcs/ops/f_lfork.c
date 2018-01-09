/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lfork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/21 22:21:40 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		f_lfork(t_vm *vm, t_proc *proc)
{
	t_list		*elm;
	int			p0;
	t_proc		*new;
	int			id;

	if (!get_param_value(vm, proc, 0, &p0)
	|| !(elm = ft_lstnew(proc, sizeof(t_proc))))
		return (0);
	id = ++vm->proc_cnt;
	ft_lstadd(&(vm->procs), elm);
	new = (t_proc*)(vm->procs->content);
	new->id = id;
	if (vm->verbose & 4)
		ft_printf("P %4d | lfork %d (%d)\n", proc->id, p0, new->pc + p0);
	new->pc = proc->pc + m0d(p0, MEM_SIZE);
	while (new->pc < 0)
		new->pc += MEM_SIZE;
	new->pc %= MEM_SIZE;
	init_proc(vm, new, new->pc);
	return (1);
}
