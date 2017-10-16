/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cljoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:08:42 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/22 17:22:01 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_cljoin(char *str, char c, int len)
{
	char	*cpy;

	cpy = ft_strnew(len + 1);
	ft_memcpy(cpy, str, len);
	cpy[len] = c;
	free(str);
	return (cpy);
}
