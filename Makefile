ASM					= asm

COREWAR				= corewar

COMPILER			= gcc

CC_FLAGS			= -Wall -Werror -Wextra

LIBFT				= libft

NCURSES				= -lncurses

ASM_INC				= asm_includes/asm.h \
					  asm_includes/asm_op.h

CORE_INC			= core_includes/core_op.h \
					  core_includes/corewar.h

ASM_SRC_DIR			= asm_srcs

CORE_SRC_DIR		= core_srcs

ASM_SRC				= main.c \
					  ft_asm.c \
					  ft_tools.c \
					  ft_tools2.c \
					  ft_label.c \
					  ft_separator.c \
					  ft_gest_instr.c \
					  ft_head.c \
					  ft_check.c \
					  ft_write.c \
					  ft_instr.c \
					  ft_errors.c \
					  ft_header.c \
					  op.c \
					  ft_launcher.c

CORE_SRC			= main.c \
					  op.c \
					  parse_argv.c \
					  parse_player.c \
					  parse_pcb_n_param.c \
					  init_vm.c \
					  vm_core.c \
					  tools.c \
					  fr33.c \
					  verbosity1.c \
					  nc_init1.c \
					  nc_init2.c \
					  nc_update1.c \
					  nc_event.c \
					  nc_blink.c \
					  ops/f_live.c \
					  ops/f_ld.c \
					  ops/f_add.c \
					  ops/f_sub.c \
					  ops/f_and.c \
					  ops/f_st.c \
					  ops/f_or.c \
					  ops/f_xor.c \
					  ops/f_sti.c \
					  ops/f_ldi.c \
					  ops/f_zjmp.c \
					  ops/f_fork.c \
					  ops/f_lld.c \
					  ops/f_lldi.c \
					  ops/f_lfork.c \
					  ops/f_aff.c


ASM_SRCS			= $(addprefix $(ASM_SRC_DIR)/srcs/, $(ASM_SRC))

CORE_SRCS			= $(addprefix $(CORE_SRC_DIR)/srcs/, $(CORE_SRC))

ASM_LIBFT			= $(addprefix $(ASM_SRC_DIR)/, $(LIBFT))

CORE_LIBFT			= $(addprefix $(CORE_SRC_DIR)/, $(LIBFT))

ASM_OBJ				= $(ASM_SRC:.c=.o)

CORE_OBJ			= $(CORE_SRC:.c=.o)

ASM_OBJS_DIR		= .asm_objs

CORE_OBJS_DIR		= .core_objs

ASM_OBJS			= $(addprefix $(ASM_OBJS_DIR)/, $(ASM_OBJ))

CORE_OBJS			= $(addprefix $(CORE_OBJS_DIR)/, $(CORE_OBJ))

all : $(ASM) $(COREWAR)

.asm_objs/%.o:asm_srcs/srcs/%.c
	@mkdir -p .asm_objs
	@$(COMPILER) $(CC_FLAGS) -Iasm_includes -c $< -o $@

.core_objs/%.o:core_srcs/srcs/%.c
	@mkdir -p .core_objs/ops
	@$(COMPILER) $(CC_FLAGS) -Icore_includes -c $< -o $@

$(ASM): $(ASM_OBJS) $(ASM_INC) $(ASM_LIBFT)/libft.a
	@$(COMPILER) $(CC_FLAGS) $(ASM_OBJS) -L $(ASM_LIBFT) -lft -o $(ASM)
	@echo "asm created !"

$(COREWAR): $(CORE_OBJS) $(CORE_INC) $(CORE_LIBFT)/libft.a
	@$(COMPILER) $(CC_FLAGS) $(NCURSES) $(CORE_OBJS) -L $(CORE_LIBFT) -lft -o $(COREWAR)
	@echo "corewar created !"

ifneq ($(shell make -q -C asm_srcs/libft;echo $$?), 0)
.PHONY: asm_srcs/libft/libft.a
endif

ifneq ($(shell make -q -C core_srcs/libft;echo $$?), 0)
.PHONY: core_srcs/libft/libft.a
endif

$(ASM_LIBFT)/libft.a:
	Make -C $(ASM_LIBFT)

$(CORE_LIBFT)/libft.a:
	Make -C $(CORE_LIBFT)

clean:
	@echo "Removing objects"
	@rm -rf $(CORE_OBJS)
	@rm -rf $(ASM_OBJS)
	Make clean -C $(CORE_LIBFT)
	Make clean -C $(ASM_LIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@echo "Removing exe"
	@rm -rf $(CORE_LIBFT)/libft.a
	@rm -rf $(ASM_LIBFT)/libft.a
	@rm -rf $(ASM)
	@rm -rf $(COREWAR)

re: fclean all

.PHONY: all clean fclean re
