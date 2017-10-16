#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaury <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:00:31 by fmaury            #+#    #+#              #
#    Updated: 2017/09/21 10:13:15 by fmaury           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			= libft.a

COMPILER		= gcc

CC_FLAGS		= -Wall -Werror -Wextra -g

INC				= ./printf/printf.h ./srclib/libft.h

LIB_SRC_DIR		= ./srclib
PNTF_SRC_DIR	= ./printf

LIB_SRC		=	ft_strlen.c\
				ft_strdup.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strstr.c \
				ft_strnstr.c \
        ft_memjoin.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isstrdigit.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_atoi.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_putchar.c \
				ft_strclr.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putchar_fd.c \
				ft_itoa.c \
				ft_bzero.c \
				ft_memalloc.c \
				ft_memset.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strsplitif.c \
				ft_strsplitnbif.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strtab.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_strjoin.c \
				ft_strljoin.c \
				ft_strlf1join.c \
				ft_strlf2join.c \
				ft_strtrim.c \
				ft_memmove.c \
				ft_strsplit.c \
				ft_strsplitif.c \
				ft_strlcat.c \
				ft_back_memcpy.c \
				ft_isspace.c \
				ft_lstadd.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_sqrt.c \
				ft_range.c \
				ft_foreach.c \
				ft_sort_params.c \
				get_next_line.c \
				ft_free_strtab.c \
				ft_itoa_base.c \
				ft_itoa_base_maj.c \
				ft_cjoin.c \
				ft_cljoin.c

PNTF_SRC	=	ft_printf.c \
				ft_fdprintf.c \
				ft_mk_str.c \
				ft_isfrmt.c \
				ft_split_arg.c \
				ft_check_arg.c \
				ft_chk_conv_type.c \
				ft_trt_spec.c \
				ft_trt_int.c \
				ft_trt_uxo.c \
				ft_trt_pwf.c \
				ft_trt_point.c \
				ft_trt_char.c \
				ft_trt_str.c \
				ft_trt_percent.c \
				ft_gest_err.c \
				ft_flg_shrp.c \
				ft_sconv_utf8.c \
				ft_trt_width.c \
				ft_trt_prec.c \
				ft_trt_wdth_prec.c \
				ft_init.c

LIB_OBJ		= $(LIB_SRC:.c=.o)

PNTF_OBJ	= $(PNTF_SRC:.c=.o)

LIB_SRCS	= $(addprefix $(LIB_SRC_DIR)/, $(LIB_SRC))

PNTF_SRCS	= $(addprefix $(PNTF_SRC_DIR)/, $(PNTF_SRC))

NEWLINE		= @echo ""

all : $(NAME)

$(NAME): $(PNTF_OBJ) $(LIB_OBJ) $(INC)
	@ar rc $(NAME) $(PNTF_OBJ) $(LIB_OBJ)
	@ranlib $(NAME)

%.o: $(PNTF_SRC_DIR)/%.c
	@$(COMPILER) $(CC_FLAGS) -c $< -o $@

%.o: $(LIB_SRC_DIR)/%.c
	@$(COMPILER) $(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf $(LIB_OBJ) $(PNTF_OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean 
	@$(MAKE) all

.PHONY: all clean fclean re
