/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:04:13 by cbarbier          #+#    #+#             */
/*   Updated: 2017/09/26 17:18:33 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstshift(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;

	if (!alst || !del || !*alst)
		return ;
	lst = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
	*alst = lst;
}
