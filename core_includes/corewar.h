/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/05 17:41:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/includes/libft.h"
# include "core_op.h"
# include <ncurses.h>
# include <signal.h>
# define DEBUG		1
# define MAX_STORE	1000

int				g_resize;
typedef union	u_byte
{
	unsigned char	c;
	uint8_t			i;
}				t_byte;
typedef struct	s_blk
{
	int		pc;
	int		i;
	int		j;
	int		until;
}				t_blk;
typedef struct	s_proc
{
	int		id;
	int		cpair;
	int		player_id;
	int		reg[REG_NUMBER];
	int		pc;
	int		ipc;
	int		carry;
	int		last_live_cycle;
	int		op_code;
	int		exec_in;
	int		adv;
	int		error_pcb;
	int		ptype[3];
	int		psize[3];
	int		param[3];
	int		alive;
}				t_proc;

typedef struct	s_player
{
	int				id;
	int				index;
	int				fd;
	int				live_in_ctd;
	int				last_live_cycle;
	t_header		header;
	unsigned char	prog[CHAMP_MAX_SIZE + 2];
}				t_player;

typedef struct	s_vm
{
	WINDOW		*win;
	WINDOW		*winfo;
	WINDOW		*war;
	t_player	players[MAX_PLAYERS];
	int			nb_players;
	t_byte		arena[MEM_SIZE];
	char		colors[MEM_SIZE];
	t_list		*procs;
	t_list		*blinks;
	int			live_in_ctd;
	t_player	*last_player_live;
	int			cycle;
	int			check;
	int			ctd;
	int			ctd_cycle;
	int			dump;
	int			verbose;
	int			ncurse;
	int			aff;
	int			cps;
	int			play;
	int			step;
	int			quit;
	int			proc_cnt;
	t_list		**store;
	int			prec;
	int			sound;
}				t_vm;
typedef union	u_mem
{
	uint8_t		i[4];
	char		c[4];
}				t_mem;
extern const t_op	g_tab[17];
/*
** 	CORE FUNCTIONS
*/
int				parse_argv(t_vm *vm, int argc, char **argv);
int				parse_player(t_player *p);
int				parse_pcb_n_param(t_vm *vm, t_proc *proc);
int				init_vm(t_vm *vm, int argc, char **argv);
int				init_proc(t_vm *vm, t_proc *proc, int pc);
int				vm_core(t_vm **avm);
int				is_reg(int reg);
int				inc_pc(t_proc *proc, int n);
int				getnbytes(t_vm *vm, int addr, int n, int *new_addr);
int				setnbytes(t_vm *vm, int addr, int val, int n);
int				get_param_value(t_vm *vm, t_proc *proc, int i, int *val);
int				m0d(int offset, int mod);
void			free_proc(void *e, size_t size);
int				free_vm(t_vm *vm);
/*
** 	VERBOSITY FUNCTIONS
*/
int				put_usage(char **argv);
int				vb_introduce(t_vm *vm);
int				vb_cycles(t_vm *vm);
int				vb_pc_movement(t_vm *vm, t_proc *proc);
int				vb_winner(t_vm *vm);
/*
** 	NCURSES FUNCTIONS
*/
int				nc_init_arena(t_vm *vm);
int				nc_init_pc(t_vm *vm);
int				nc_init(t_vm *vm);
int				nc_init_info(t_vm *vm);
int				nc_loop(t_vm *vm);
int				nc_put_pc(t_vm *vm, t_proc *proc, int put);
int				nc_event_handling(t_vm **avm);
int				nc_winner(t_vm **avm);
int				make_it_blink(t_vm *vm, t_proc *proc);
void			free_blk(void *e, size_t size);
void			del_vm(void *e, size_t size);
int				reset_blk(void *e, void *vm);
int				is_blk(t_list *e, void *apc);
void			resize_handler(int s);
/*
** 	INSTRUCTIONS FUNCTIONS
*/
int				f_live(t_vm *vm, t_proc *proc);
int				f_ld(t_vm *vm, t_proc *proc);
int				f_st(t_vm *vm, t_proc *proc);
int				f_add(t_vm *vm, t_proc *proc);
int				f_sub(t_vm *vm, t_proc *proc);
int				f_and(t_vm *vm, t_proc *proc);
int				f_or(t_vm *vm, t_proc *proc);
int				f_xor(t_vm *vm, t_proc *proc);
int				f_zjmp(t_vm *vm, t_proc *proc);
int				f_ldi(t_vm *vm, t_proc *proc);
int				f_sti(t_vm *vm, t_proc *proc);
int				f_fork(t_vm *vm, t_proc *proc);
int				f_lld(t_vm *vm, t_proc *proc);
int				f_lldi(t_vm *vm, t_proc *proc);
int				f_lfork(t_vm *vm, t_proc *proc);
int				f_aff(t_vm *vm, t_proc *proc);
/*
** 	STORE FUNCTIONS
*/
void			store_vm(t_vm **avm);
int				apply_new_vm(t_vm **avm);
#endif
