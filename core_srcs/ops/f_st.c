/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/27 08:12:00 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	nc_st(t_vm *vm, t_proc *proc, int add)
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

int			f_st(t_vm *vm, t_proc *proc)
{
	int	reg_p0;
	int	index;
	int	add;

	if (!get_param_value(vm, proc, 0, &reg_p0)
			|| !get_param_value(vm, proc, 1, &index))
		return (0);
	if (proc->ptype[1] == T_IND)
	{
		index = proc->param[1];
		add = m0d(proc->pc + m0d(index, IDX_MOD), MEM_SIZE);
		while (add < 0)
			add += MEM_SIZE;
		setnbytes(vm, add, reg_p0, 4);
	}
	else if (is_reg(proc->param[1]))
		proc->reg[proc->param[1] - 1] = reg_p0;
	if (vm->ncurse)
		nc_st(vm, proc, add);
	if (vm->verbose & 4)
		ft_printf("P %4d | st r%d %d\n", proc->id, proc->param[0],
				proc->param[1]);
	return (1);
}
