/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:49:32 by fmaury            #+#    #+#             */
/*   Updated: 2017/03/14 18:48:51 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2, int fr)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	if (!(str = ft_strnew(i + ft_strlen(s2))))
		return (NULL);
	str = ft_strcpy(str, s1);
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	if (fr == 1 || fr == 3)
		free((char *)s1);
	if (fr == 2 || fr == 3)
		free((char *)s2);
	return (str);
}
