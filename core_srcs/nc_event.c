/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/04 10:37:22 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		nc_update_cps(t_vm *vm, int key, int *p_cps)
{
	int		cps;

	cps = *p_cps;
	if (key == 'q' && cps - 10 > 0)
		*p_cps = cps - 10;
	else if (key == 'w' && cps - 1 > 0)
		*p_cps = cps - 1;
	else if (key == 'e' && cps + 1 <= 1000)
		*p_cps = cps + 1;
	else if (key == 'r' && cps + 10 <= 1000)
		*p_cps = cps + 10;
	mvwprintw(vm->winfo, 17 + 4 * vm->nb_players, 18, "% 10d", vm->cps);
	return (1);
}

int				nc_event_handling(t_vm **avm)
{
	t_vm			*vm;
	int				key;

	vm = *avm;
	if (!vm->ncurse)
		return (0);
	if ((key = getch()) == ERR)
		return (0);
	if (key == 97 && vm->cycle > 0 && (!vm->play || vm->step > 0))
		(*avm)->prec = 1;
	else if (key == 27 || vm->play == -1)
		vm->quit = 1;
	else if (key == ' ')
	{
		vm->play = (vm->play && vm->step != vm->cycle ? 0 : 1);
		if (vm->sound)
			system(vm->play ? "killall -CONT afplay 2> /dev/null" :
					"killall -STOP afplay 2> /dev/null");
		vm->step = -1;
	}
	else if (ft_strchr("qwer", key))
		nc_update_cps(vm, key, &(vm->cps));
	else if (key == 's' && (vm->play = 1))
		vm->step = vm->cycle + 1;
	return (1);
}
