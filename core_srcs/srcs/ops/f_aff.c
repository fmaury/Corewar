/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/07/26 14:23:39 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		f_aff(t_vm *vm, t_proc *proc)
{
	int	val;

	if (!get_param_value(vm, proc, 0, &val))
		return (0);
	if (vm->aff)
		ft_printf("Aff: %c\n", val % 256);
	return (1);
}
