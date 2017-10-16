/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strljoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:20:00 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/25 12:03:18 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memjoin(void *s1, void *s2, int len1, int len2)
{
	int				j;
	unsigned char	*str;
	unsigned char	*s2b;

	s2b = (unsigned char*)s2;
	j = 0;
	if (!(str = ft_memalloc(len1 + len2)))
		return (NULL);
	str = ft_memcpy(str, (unsigned char*)s1, len1);
	while (j < len2)
	{
		str[len1 + j] = s2b[j];
		j++;
	}
	return (str);
}
