/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:13:15 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/07 15:59:18 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmcat(char *dest, const char *srci, int len)
{
	int flag;
	int i;

	i = 0;
	flag = ft_strlen(dest);
	while (src[i])
	{
		dest[flag] = src[i];
		flag++;
		i++;
	}
	dest[flag] = '\0';
	return (dest);
}
