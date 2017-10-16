/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:11:31 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/18 13:19:36 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ligne(const char *big, const char *little,
							int lenlittle, size_t len)
{
	size_t		i;
	int			j;
	int			flag;

	i = 0;
	flag = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[i] != little[j]) && big[i] && i < len)
		{
			i++;
		}
		flag = i;
		while (big[i] == little[j] && big[i] && little[j] && i < len)
		{
			i++;
			j++;
		}
		if (j > 0 && j < lenlittle)
			i = flag + 1;
		else if (j == lenlittle)
			return ((char*)&big[flag]);
	}
	return (NULL);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			lenlittle;

	lenlittle = ft_strlen(little);
	if (len == 0)
		return (NULL);
	if (lenlittle == 0)
		return ((char*)big);
	return (ft_ligne(big, little, lenlittle, len));
}
