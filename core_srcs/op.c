/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2017/07/26 15:12:02 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

const t_op g_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 1, f_live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 1, f_ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 1, f_st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 0, f_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 0, f_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and)  r1, r2, r3   r1&r2 -> r3", 1, 0, 1, f_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or)   r1, r2, r3   r1 | r2 -> r3", 1, 0, 1, f_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor)  r1, r2, r3   r1^r2 -> r3", 1, 0, 1, f_xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 1, f_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 1, f_ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 1, f_sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 1, f_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 0, f_lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 0, f_lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 0, f_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 0, f_aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0, 0}
};
