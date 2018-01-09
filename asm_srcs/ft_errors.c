/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:43:41 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 17:33:57 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_col_cursor(t_champ *champ)
{
	int		postop;
	int		i;

	i = 0;
	if (champ->lab)
		champ->col = ft_forbidden_char(champ->label);
	postop = !champ->lab ? ft_strlen(champ->op) + 1 : 0;
	while (ft_isspace(champ->line[postop + i]))
		i++;
	return (champ->col + i + 1 + champ->spbf);
}

void	ft_printf_errcode(int err)
{
	if (err == 1)
		ft_printf("Error: .name wrong format\n");
	else if (err == 2)
		ft_printf("Error: .comment wrong format\n");
	else if (err == 3)
		ft_printf("Error: Unknown mnemonic\n");
	else if (err == 4)
		ft_printf("Error: Parameter missing\n");
	else if (err == 5)
		ft_printf("Error: Too many parameters\n");
	else if (err == 6)
		ft_printf("Error: Wrong parameters\n");
	else if (err == 7)
		ft_printf("Error: Unknown label\n");
	else if (err == 8)
		ft_printf("Error: Unauthorized character in label\n");
	else if (err == 9)
		ft_printf("Error: Separator syntax\n");
}

void	ft_error(t_asm *sfile)
{
	t_champ		*champ;
	char		*op;

	champ = sfile->champ;
	while (champ)
	{
		if (champ->err == 1)
		{
			if (champ->lab == 1)
				op = champ->label;
			else
				op = champ->op;
			if (!champ->args)
				champ->args = ft_strdup("");
			ft_printf("\033[1m\033[37m%s:%d:%d: \033[1m\033[31merror:\x1b[0m ",
					sfile->origin, champ->ligne + 1, ft_col_cursor(champ));
			ft_printf_errcode(champ->errcode);
			ft_printf("   %s %s\n%*c\n", op, champ->args, champ->col + 4,
					'^');
		}
		champ = champ->next;
	}
}
