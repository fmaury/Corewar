/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/27 08:13:36 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		f_lldi(t_vm *vm, t_proc *proc)
{
	int	p0;
	int	p1;
	int	i_reg;

	if (!get_param_value(vm, proc, 0, &p0)
	|| !get_param_value(vm, proc, 1, &p1)
	|| !is_reg(proc->param[2]))
		return (0);
	i_reg = proc->param[2] - 1;
	proc->reg[i_reg] = getnbytes(vm, proc->pc + m0d(p0 & p1, MEM_SIZE), 4, 0);
	proc->carry = !proc->reg[i_reg];
	if (vm->verbose & 4)
	{
		ft_printf("P %4d | lldi %d %d r%d\n", proc->id,
				p0, p1, proc->param[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
				p0, p1, p0 + p1, proc->pc + p0 + p1);
	}
	return (1);
}
