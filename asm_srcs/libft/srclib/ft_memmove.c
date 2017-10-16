/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:03:39 by fmaury            #+#    #+#             */
/*   Updated: 2016/11/16 09:34:49 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src > dest)
		ft_memcpy(dest, src, n);
	else if (dest > src)
		ft_back_memcpy(dest, src, n);
	else
		return (NULL);
	return (dest);
}
