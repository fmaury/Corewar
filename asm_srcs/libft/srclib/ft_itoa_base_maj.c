/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:19:52 by fmaury            #+#    #+#             */
/*   Updated: 2017/01/27 16:34:11 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_split_nb_maj(unsigned long long unb, int k, int base)
{
	unsigned long long int	cpy;
	int						i;
	int						mod;
	char					*str;

	i = 0;
	cpy = unb;
	while (cpy > 0)
	{
		cpy = cpy / base;
		i++;
	}
	str = ft_strnew(i-- + k);
	while (i >= 0)
	{
		mod = unb % base;
		if (mod >= 10)
			mod = mod % 10 + 17;
		str[i + k] = mod + 48;
		unb = unb / base;
		i--;
	}
	if (k > 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_base_maj(unsigned long long int nb, int base)
{
	char					*str;
	unsigned long long int	unb;
	int						k;

	k = 0;
	unb = 0;
	if (nb == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	else
		unb = nb;
	str = ft_split_nb_maj(unb, k, base);
	return (str);
}
