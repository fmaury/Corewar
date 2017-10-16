/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:42:25 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/16 09:16:58 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	int				j;

	j = 0;
	i = 0;
	if (s == NULL || (*f) == NULL)
		return ;
	while (s[j])
	{
		(*f)(i, &s[j]);
		j++;
		i++;
	}
}
