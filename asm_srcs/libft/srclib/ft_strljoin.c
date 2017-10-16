/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strljoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:20:00 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/22 17:22:11 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strljoin(char *s1, char *s2, int len1, int len2)
{
	int		j;
	char	*str;

	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = ft_strnew(len1 + len2)))
		return (NULL);
	str = ft_memcpy(str, s1, len1);
	while (j < len2)
	{
		str[len1 + j] = s2[j];
		j++;
	}
	return (str);
}
