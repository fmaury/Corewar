/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:08:42 by fmaury            #+#    #+#             */
/*   Updated: 2017/01/23 15:19:27 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_cjoin(char *str, char c)
{
	int		len;
	char	*cpy;

	len = 0;
	len = ft_strlen(str);
	cpy = ft_strnew(len + 1);
	ft_strcpy(cpy, str);
	cpy[len] = c;
	free(str);
	return (cpy);
}
