/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:46:23 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/16 09:35:24 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*ssrc;
	unsigned char	cc;

	i = 0;
	cdst = (unsigned char*)dst;
	ssrc = (unsigned char*)src;
	cc = (unsigned char)c;
	while (i < n)
	{
		cdst[i] = ssrc[i];
		if (ssrc[i] == cc)
			return (&cdst[i + 1]);
		i++;
	}
	return (NULL);
}
