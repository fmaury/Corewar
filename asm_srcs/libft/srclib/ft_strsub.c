/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:03:28 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/15 16:30:41 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cpy;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (i < start)
		i++;
	if (!(cpy = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (j < len)
	{
		cpy[j] = s[i];
		i++;
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
