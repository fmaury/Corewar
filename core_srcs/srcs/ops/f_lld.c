/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/21 13:55:33 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		f_lld(t_vm *vm, t_proc *proc)
{
	int	val;
	int	i_reg;
	int	addr;

	if (!is_reg(proc->param[1]))
		return (0);
	i_reg = proc->param[1] - 1;
	if (!get_param_value(vm, proc, 0, &val))
		return (0);
	addr = m0d(proc->pc + val, MEM_SIZE);
	while (addr < 0)
		addr += MEM_SIZE;
	proc->reg[i_reg] = getnbytes(vm, addr, 4, 0);
	proc->carry = !proc->reg[i_reg];
	if (vm->verbose & 4)
		ft_printf("P %4d | lld %d r%d\n", proc->id, val, i_reg + 1);
	return (1);
}
