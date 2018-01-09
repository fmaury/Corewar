/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/20 19:18:33 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_reg(int reg)
{
	if (reg < 1 || reg > 17)
		return (0);
	return (1);
}

int		getnbytes(t_vm *vm, int addr, int n, int *new_addr)
{
	int	i;
	int	val;
	int	tmp;

	i = 0;
	val = 0;
	while (addr < 0)
		addr += MEM_SIZE;
	addr %= MEM_SIZE;
	while (i < n)
	{
		tmp = (addr + i) % MEM_SIZE;
		val = (val << 8) + vm->arena[tmp].i;
		i++;
	}
	if (new_addr)
		*new_addr = addr;
	return (val);
}

int		setnbytes(t_vm *vm, int addr, int val, int n)
{
	int	i;
	int	tmp;

	i = 0;
	while (addr < 0)
		addr += MEM_SIZE;
	addr %= MEM_SIZE;
	while (i < n)
	{
		tmp = (addr + i) % MEM_SIZE;
		vm->arena[tmp].i = (val >> (8 * (n - i - 1))) & 0xff;
		i++;
	}
	return (addr);
}

int		inc_pc(t_proc *proc, int n)
{
	proc->ipc = (proc->ipc + n) % MEM_SIZE;
	return (1);
}

int		get_param_value(t_vm *vm, t_proc *prc, int i, int *val)
{
	int		addr;

	if (prc->ptype[i] == T_REG)
	{
		if (!is_reg(prc->param[i]))
			return (0);
		*val = prc->reg[prc->param[i] - 1];
	}
	else if (prc->ptype[i] == T_DIR)
		*val = prc->psize[i] == 2 ? (short int)(prc->param[i]) : prc->param[i];
	else if (prc->ptype[i] == T_IND)
	{
		addr = m0d(prc->pc + m0d(prc->param[i], IDX_MOD), MEM_SIZE);
		while (addr < 0)
			addr += MEM_SIZE;
		*val = getnbytes(vm, addr, 4, 0);
	}
	else
		return (0);
	return (1);
}
