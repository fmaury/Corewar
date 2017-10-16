/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:38:54 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/16 09:24:07 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char *)s2;
	while (tmp1[i] || tmp2[i])
	{
		if (tmp1[i] - tmp2[i] == 0)
			i++;
		else
			return (tmp1[i] - tmp2[i]);
	}
	return (0);
}
