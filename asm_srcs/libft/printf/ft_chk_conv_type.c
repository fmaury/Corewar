/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_conv_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:30:04 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/21 11:56:48 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isint(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	else
		return (0);
}

int		ft_isuint(char c)
{
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'O' || c == 'U'
			|| c == 'b' || c == 'B')
		return (1);
	else
		return (0);
}

int		ft_isxo(char c)
{
	if (c == 'o' || c == 'x' || c == 'X' || c == 'O' || c == 'b' || c == 'B')
		return (1);
	else
		return (0);
}
