/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_or.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/27 08:13:56 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_type(t_proc *proc, int val, int i)
{
	if (proc->ptype[i] == T_REG)
		ft_printf("%d ", proc->reg[proc->param[i] - 1]);
	else
		ft_printf("%d ", val);
}

static void	print(t_proc *proc, int i_reg, int p0, int p1)
{
	ft_printf("P %4d | or ", proc->id);
	put_type(proc, p0, 0);
	put_type(proc, p1, 1);
	ft_printf("r%d\n", i_reg + 1);
}

int			f_or(t_vm *vm, t_proc *proc)
{
	int	p0;
	int	p1;
	int	i_reg;

	if (!get_param_value(vm, proc, 0, &p0)
	|| !get_param_value(vm, proc, 1, &p1)
	|| !is_reg(proc->param[2]))
		return (0);
	i_reg = proc->param[2] - 1;
	if (vm->verbose & 4)
		print(proc, i_reg, p0, p1);
	proc->reg[i_reg] = p0 | p1;
	proc->carry = !(proc->reg[i_reg]);
	return (1);
}
