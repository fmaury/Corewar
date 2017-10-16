/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_blink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/08 11:29:17 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			make_it_blink(t_vm *vm, t_proc *proc)
{
	t_list	*elm;
	t_blk	blk;

	blk.pc = proc->pc;
	blk.i = proc->pc % 64;
	blk.j = proc->pc / 64;
	blk.until = vm->cycle + 50;
	if (!(elm = ft_lstnew(&blk, sizeof(t_blk))))
		return (0);
	ft_lstadd(&(vm->blinks), elm);
	wattron(vm->war, COLOR_PAIR(proc->cpair + 11) | A_STANDOUT);
	mvwprintw(vm->war, blk.j + 1, 3 * blk.i + 1, "%.2x",
			vm->arena[proc->pc].i);
	wattroff(vm->war, COLOR_PAIR(proc->cpair + 11) | A_STANDOUT);
	return (1);
}

void		free_blk(void *e, size_t size)
{
	(void)size;
	free(e);
}

int			is_blk(t_list *e, void *apc)
{
	t_blk		*blk;

	blk = (t_blk*)(e->content);
	if (*((int*)apc) == blk->pc)
		return (1);
	return (0);
}

static int	reset_blk_helper(t_vm *vm, t_blk *blk, int cpair)
{
	cpair += vm->cycle % 5 ? 4 : 11;
	wattron(vm->war, COLOR_PAIR(cpair));
	mvwprintw(vm->war, blk->j + 1, 3 * blk->i + 1, "%.2x",
			vm->arena[blk->pc].i);
	wattroff(vm->war, COLOR_PAIR(cpair));
	return (0);
}

int			reset_blk(void *e, void *arg_vm)
{
	t_vm		*vm;
	t_blk		*blk;
	int			cpair;

	vm = (t_vm*)arg_vm;
	blk = (t_blk*)e;
	cpair = vm->colors[64 * blk->j + blk->i];
	if (blk->until != vm->cycle)
		return (reset_blk_helper(vm, blk, cpair));
	wattron(vm->war, COLOR_PAIR(cpair));
	mvwprintw(vm->war, blk->j + 1, 3 * blk->i + 1, "%.2x",
			vm->arena[blk->pc].i);
	wattroff(vm->war, COLOR_PAIR(cpair));
	return (1);
}
