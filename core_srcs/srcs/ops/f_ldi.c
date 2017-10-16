/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ldi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/25 17:18:16 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		f_ldi(t_vm *vm, t_proc *proc)
{
	int	p0;
	int	p1;
	int	i_reg;
	int	addr;

	if (!get_param_value(vm, proc, 0, &p0)
	|| !get_param_value(vm, proc, 1, &p1)
	|| !is_reg(proc->param[2]))
		return (0);
	i_reg = proc->param[2] - 1;
	proc->reg[i_reg] = getnbytes(vm,
			proc->pc + m0d((p0 + p1), IDX_MOD), 4, &addr);
	if (vm->verbose & 4)
	{
		ft_printf("P %4d | ldi %d %d r%d\n", proc->id,
				p0, p1, proc->param[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
				p0, p1, p0 + p1, proc->pc + m0d(p0 + p1, IDX_MOD));
	}
	return (1);
}
