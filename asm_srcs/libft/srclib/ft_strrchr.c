/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:07:39 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/18 15:51:46 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int k;
	int flag;

	i = 0;
	k = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			flag++;
			k = i;
		}
		i++;
	}
	if (s[i] == '\0' && (char)c == '\0')
	{
		k = i;
		flag++;
	}
	if (flag > 0)
		return ((char*)s + k);
	else
		return (NULL);
}
