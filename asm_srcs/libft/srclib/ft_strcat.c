/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:13:15 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/07 14:13:24 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
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
