/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 10:45:40 by fmaury            #+#    #+#             */
/*   Updated: 2017/03/28 14:49:49 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../srclib/libft.h"

typedef struct			s_print
{
	va_list				*ap;
	char				*flag;
	char				*cwidth;
	int					width;
	char				*cprecision;
	int					precision;
	char				*length;
	char				specifier;
	char				*str;
	char				*res;
	unsigned long long	usign;
	long long			sign;
	int					len;
	int					err;
}						t_print;

typedef struct			s_flag
{
	int					sharp;
	int					zero;
	int					plus;
	int					min;
	int					space;
}						t_flag;

int						ft_printf(char *frmt, ...);
int						ft_fdprintf(int fd, char *frmt, ...);
int						ft_check_arg(t_print *arg, t_flag *flag);
int						ft_isflag(char c);
int						ft_isprec(char c);
int						ft_islength(char c);
int						ft_isspec(char c);
int						ft_isint(char c);
int						ft_isuint(char c);
int						ft_isxo(char c);
int						ft_check_arg(t_print *arg, t_flag *flag);
int						ft_gest_err(char *str, int i);
int						ft_mk_str(char *frmt, t_print *arg, int i);
int						ft_wich_stype(t_print *arg);
void					ft_sconv_utf8(t_print *arg, int type);
void					ft_gest_arg(t_print *arg);
void					ft_flg_shrp(t_print *arg);
void					ft_flg_shrp_es(t_print *arg, char *str);
void					ft_init_arg(t_print *arg);
void					ft_init_flag(t_flag *flag);
void					ft_pm(char *str, t_print *arg);
char					*ft_flg_precshrp(t_print *arg, char *str);
char					*ft_mwpl(t_print *arg, t_flag *flag);
char					*ft_wpl(t_print *arg, t_flag *flag);
char					*ft_pw(t_print *arg, t_flag *flag);
char					*ft_frm_point(char *str);
char					*ft_wp(t_print *arg, t_flag *flag);
char					*ft_trt_pwf(t_print *arg, t_flag *flag);
char					*ft_trt_spec(t_print *arg, t_flag *flag);
char					*ft_trt_int(t_print *arg, t_flag *flag);
char					*ft_trt_uxo(t_print *arg, t_flag *flag);
char					*ft_trt_point(t_print *arg, t_flag *flag);
char					*ft_trt_percent(t_print *arg, t_flag *flag);
char					*ft_trt_char(t_print *arg, t_flag *flag);
char					*ft_trt_err(t_print *arg, t_flag *flag);
char					*ft_trt_str(t_print *arg, t_flag *flag);

#endif
