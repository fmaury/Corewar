/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/21 13:56:33 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		f_zjmp(t_vm *vm, t_proc *proc)
{
	int	p0;

	if (!get_param_value(vm, proc, 0, &p0))
		return (0);
	if (proc->carry)
	{
		proc->ipc = (proc->pc + m0d(p0, IDX_MOD));
		while (proc->ipc < 0)
			proc->ipc += MEM_SIZE;
		proc->ipc %= MEM_SIZE;
	}
	else
		proc->ipc = (proc->pc + 3) % MEM_SIZE;
	if (vm->verbose & 4)
		ft_printf("P %4d | zjmp %d %s\n",
				proc->id, p0, (proc->carry ? "OK" : "FAILED"));
	if (proc->carry)
		proc->op_code = -1;
	return (1);
}
