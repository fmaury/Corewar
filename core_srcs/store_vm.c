/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:33:17 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/29 10:59:22 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				del_vm(void *content, size_t size)
{
	t_vm		*vm;

	(void)size;
	vm = (t_vm *)content;
	ft_lstdel(&(vm)->procs, free_proc);
	ft_lstdel(&(vm)->blinks, free_blk);
	free(content);
}

void				store_vm(t_vm **avm)
{
	t_list		*new;
	t_vm		*new_vm;
	t_list		*lst;
	int			i;

	if (!(*avm)->ncurse || !(new = ft_lstnew(*avm, sizeof(t_vm))))
		return ;
	new_vm = (t_vm *)(new->content);
	new_vm->prec = 0;
	new_vm->procs = ft_lstcpy((*avm)->procs, sizeof(t_proc));
	new_vm->blinks = ft_lstcpy((*avm)->blinks, sizeof(t_blk));
	ft_lstadd((*avm)->store, new);
	lst = *((*avm)->store);
	i = 1;
	while (lst->next && i < MAX_STORE)
	{
		i++;
		lst = lst->next;
	}
	if (i == MAX_STORE && lst->next)
	{
		del_vm(lst->next->content, sizeof(t_vm));
		ft_memdel((void**)(&lst->next));
	}
}

int					apply_new_vm(t_vm **avm)
{
	t_list		**store;
	t_list		*tmp;

	store = (*avm)->store;
	if (!store || !*store)
		return (0);
	ft_lstdel(&(*avm)->procs, free_proc);
	ft_lstdel(&(*avm)->blinks, free_blk);
	*avm = ft_memcpy(*avm, (*store)->content, sizeof(t_vm));
	(*avm)->prec = 0;
	(*avm)->play = 0;
	(*avm)->step = -1;
	tmp = *store;
	*store = (*store)->next;
	ft_memdel((void **)&(tmp->content));
	ft_memdel((void **)&tmp);
	nc_init_arena(*avm);
	nc_init_pc(*avm);
	nc_loop(*avm);
	return (0);
}
