/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:23:14 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/07 14:12:31 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int flag;
	int i;

	i = 0;
	flag = ft_strlen(dest);
	while (src[i] && n > 0)
	{
		dest[flag] = src[i];
		flag++;
		i++;
		n--;
	}
	dest[flag] = '\0';
	return (dest);
}
