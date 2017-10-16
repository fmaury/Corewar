/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:29:09 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/26 11:02:31 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "asm_op.h"
# include "../asm_srcs/libft/printf/printf.h"
# include "../asm_srcs/libft/srclib/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_champ
{
	int				instr;
	int				lab;
	int				err;
	char			*line;
	char			*label;
	char			*op;
	int				opcode;
	unsigned char	codage;
	char			*args;
	char			**arg;
	unsigned char	*param;
	int				size;
	struct s_champ	*next;
	int				errcode;
	int				ligne;
	int				col;
}					t_champ;

typedef struct		s_asm
{
	int				fd;
	char			*origin;
	char			*file;
	char			*name;
	char			*comment;
	char			header[16 + PROG_NAME_LENGTH + COMMENT_LENGTH];
	t_champ			*champ;
}					t_asm;

typedef struct		s_op
{
	char			*param;
	int				nbargs;
	int				*arg;
	int				opcode;
	int				cycle;
	char			*name;
	int				ocod;
	int				oind;
}					t_op;

int					ft_launcher(char *file);
int					ft_head(t_asm *sfile);
int					ft_set_header(t_asm *sfile);
int					ft_asm(t_asm *sfile, t_champ *champ, int i);
int					ft_isspe(char *op);
int					ft_label(char *label, t_champ *champ, t_champ *save);
int					ft_instr(t_champ *champ);
int					ft_check(char *op, char *param, t_champ *champ);
int					ft_split_param(char c);
int					ft_nb_split(char *str, int i);
int					ft_find_op(char *op);
int					ft_forbidden_char(char *str);
int					ft_iscom(char c);
int					ft_check_separator(char *param, t_champ *champ);
int					ft_gest_dir(t_champ *champ, t_champ *save, int size, int i);
int					ft_gest_ind(t_champ *champ, int size, int i);
int					ft_gest_reg(t_champ *champ, int size, int i);
char				*ft_erspace(char *str);
char				*ft_erase_dc(char *str);
void				ft_fill_codage(t_champ *champ, int i);
void				ft_fill_param(t_champ *champ, int res, int size, int i);
void				ft_write(t_asm *sfile, t_champ *champ);
void				ft_error(t_asm *sfile);
void				ft_col(t_champ *champ);

#endif
