/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:31:15 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/17 14:53:55 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tmp1;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	tmp1 = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!((tmp1->next = ft_lstnew(tmp->content, tmp->content_size))))
			return (NULL);
		tmp1 = tmp1->next;
		lst = lst->next;
	}
	return (new);
}
