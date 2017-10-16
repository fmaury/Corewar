/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfrmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:14:54 by fmaury            #+#    #+#             */
/*   Updated: 2017/02/21 14:14:34 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == '#' || c == ' ' || c == '0')
		return (1);
	else
		return (0);
}

int		ft_isprec(char c)
{
	if (c == '.' || ft_isdigit(c) == 1 || c == '*')
		return (1);
	else
		return (0);
}

int		ft_islength(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	else
		return (0);
}

int		ft_isspec(char c)
{
	if (c == 'i' || c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%' ||
			c == 'b' || c == 'B')
		return (1);
	else
		return (0);
}
