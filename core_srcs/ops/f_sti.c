/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/29 11:03:40 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	nc_sti(t_vm *vm, t_proc *proc, int add)
{
	int		i;
	int		j;
	int		byte;

	byte = 0;
	wattron(vm->war, COLOR_PAIR((int)(proc->cpair)));
	while (byte < 4)
	{
		j = add / 64;
		i = add % 64;
		mvwprintw(vm->war, j + 1, 3 * i + 1, "%.2x", vm->arena[j * 64 + i].i);
		vm->colors[add] = proc->cpair;
		add = m0d(add + 1, MEM_SIZE);
		byte++;
	}
	wattroff(vm->war, COLOR_PAIR((int)(proc->cpair)));
	return (0);
}

int			f_sti(t_vm *vm, t_proc *proc)
{
	int	reg_p0;
	int	index;
	int	index2;
	int	addr;

	if (!get_param_value(vm, proc, 0, &reg_p0)
	|| !get_param_value(vm, proc, 1, &index)
	|| !get_param_value(vm, proc, 2, &index2))
		return (0);
	addr = setnbytes(vm, proc->pc + m0d(index + index2, IDX_MOD), reg_p0, 4);
	if (vm->ncurse)
		nc_sti(vm, proc, addr);
	if (vm->verbose & 4)
	{
		ft_printf("P %4d | sti r%d %d %d\n", proc->id,
				proc->param[0], index, index2);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
				index, index2, index + index2, proc->pc +
				m0d(index + index2, IDX_MOD));
	}
	return (1);
}
