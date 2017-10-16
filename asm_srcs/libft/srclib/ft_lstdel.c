/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:07:02 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/17 14:50:49 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *nxtmp;

	tmp = *alst;
	while (tmp)
	{
		nxtmp = tmp->next;
		(*del)((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = nxtmp;
	}
	*alst = NULL;
}
