/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:26:16 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/18 14:53:43 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmps;
	unsigned char	tmpc;
	size_t			i;

	i = 0;
	tmps = (unsigned char *)s;
	tmpc = (unsigned char)c;
	while (i < n)
	{
		if (tmps[i] == tmpc)
			return (tmps + i);
		i++;
	}
	if (tmps[i] == '\0')
		return (tmps + i);
	return (NULL);
}
