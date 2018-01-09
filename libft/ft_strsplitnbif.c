/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitnbif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:03:49 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/25 12:11:33 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				nb_words(char **aptr, int (*f)(char))
{
	unsigned int	nbwords;
	char			*ptr;

	ptr = *aptr;
	nbwords = 0;
	while (*ptr)
	{
		if (!f(*ptr))
		{
			if (!nbwords)
				*aptr = ptr;
			while (*ptr && !f(*ptr))
				ptr++;
			nbwords++;
		}
		else
			ptr++;
	}
	return (nbwords);
}

static	unsigned int	add_word(char *ptr, char **res, int (*f)(char))
{
	unsigned int	index;

	index = 0;
	while (!f(ptr[index]) && ptr[index])
		index++;
	*res = ft_strsub(ptr, 0, index);
	while (ptr[index] && f(ptr[index]))
		index++;
	return (index);
}

char					**ft_strsplitnbif(char const *s, int (*f)(char), int n)
{
	char			**res;
	char			*ptr;
	int				i_res;
	int				nb;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	nb = nb_words(&ptr, f);
	n = n >= nb ? nb - 1 : n;
	res = ft_memalloc((n + 2) * sizeof(char *));
	if (!res)
		return (NULL);
	i_res = 0;
	while (i_res < n)
	{
		ptr += add_word(ptr, &res[i_res], f);
		i_res++;
	}
	res[n] = ft_strdup(ptr);
	return (res);
}
