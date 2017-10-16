/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:30:20 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/18 15:10:20 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_esp(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static int	ft_esp_b(char const *s, int i)
{
	i--;
	if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	int		l;
	int		j;
	char	*str1;

	if (s == NULL)
		return (NULL);
	l = 0;
	i = ft_esp(s);
	k = ft_esp_b(s, ft_strlen(s));
	j = k - i;
	if (j < 0)
		j = 0;
	if (!(str1 = (char*)malloc(sizeof(char) * (j + 2))))
		return (NULL);
	str1[k - i + 1] = '\0';
	while (l <= j)
	{
		str1[l] = s[i];
		i++;
		l++;
	}
	return (str1);
}
