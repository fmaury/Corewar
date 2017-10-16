/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mk_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:07:38 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/21 14:04:53 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_mk_str(char *frmt, t_print *arg, int i)
{
	int		k;
	int		j;

	j = 0;
	k = 0;
	while (ft_isflag(frmt[i + k]) == 1 || ft_isprec(frmt[i + k]) == 1 ||
			ft_islength(frmt[i + k]) == 1 || frmt[i + k] == '*')
		k++;
	arg->str = ft_strnew(k + 1);
	while (j <= k)
	{
		arg->str[j] = frmt[j + i];
		j++;
	}
	arg->str[j] = '\0';
	return (j + i);
}
