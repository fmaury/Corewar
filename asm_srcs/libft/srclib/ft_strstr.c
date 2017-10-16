/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:11:31 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/17 15:38:20 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ligne(const char *big, const char *little, int lenlittle)
{
	int		j;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (big[i])
	{
		j = 0;
		while ((big[i] != little[j]) && big[i])
			i++;
		flag = i;
		while (big[i] == little[j] && big[i] && little[j])
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

char		*ft_strstr(const char *big, const char *little)
{
	int		lenlittle;

	lenlittle = ft_strlen(little);
	if (lenlittle == 0)
		return ((char*)big);
	return (ft_ligne(big, little, lenlittle));
}
