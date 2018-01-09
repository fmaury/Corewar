ASM					= asm

COREWAR				= corewar

COMPILER			= gcc

CC_FLAGS			= -Wall -Werror -Wextra

LIBFT				= libft/libft.a

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
					  ft_tools3.c \
					  ft_label.c \
					  ft_separator.c \
					  ft_gest_instr.c \
					  ft_head.c \
					  ft_check.c \
					  ft_check_main_args.c \
					  ft_write.c \
					  ft_aff.c \
					  ft_aff_print_res.c \
					  ft_instr.c \
					  ft_reverse.c \
					  ft_reverse_code.c \
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
					  store_vm.c \
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


ASM_SRCS			= $(addprefix $(ASM_SRC_DIR)/, $(ASM_SRC))

CORE_SRCS			= $(addprefix $(CORE_SRC_DIR)/, $(CORE_SRC))

ASM_OBJ				= $(ASM_SRC:.c=.o)

CORE_OBJ			= $(CORE_SRC:.c=.o)

ASM_OBJS_DIR		= .asm_objs

CORE_OBJS_DIR		= .core_objs

ASM_OBJS			= $(addprefix $(ASM_OBJS_DIR)/, $(ASM_OBJ))

CORE_OBJS			= $(addprefix $(CORE_OBJS_DIR)/, $(CORE_OBJ))

all : visu $(LIBFT) $(ASM) $(COREWAR)

visu:
ifneq ($(shell test -e corewar && test -e asm;echo $$?), 0)
	@echo ""
	@echo " / \   / \   / \   / \   / \   / \   / \ "
	@echo "( \033[32;1mc\033[0m ) ( \033[32;1mo\033[0m ) ( \033[32;1mr\033[0m ) ( \033[32;1me\033[0m ) ( \033[32;1mw\033[0m ) ( \033[32;1ma\033[0m ) ( \033[32;1mr\033[0m )"
	@echo " \_/   \_/   \_/   \_/   \_/   \_/   \_/ "
	@echo "                             \033[1m© team Dinosaurus\033[0m\n\n"
endif

.asm_objs/%.o:asm_srcs/%.c $(ASM_INC)
	@mkdir -p .asm_objs
	@$(COMPILER) $(CC_FLAGS) -Iasm_includes -c $< -o $@ || (echo "\033[K \033[36mASM :      \033[0m [\033[31m $(notdir $<)\033[0m ] \033[31m✕\033[0m")
	@echo "\033[K \033[36mASM :      \033[0m [ compiling :\033[33m $(notdir $<)\033[0m ]\033[1A"

.core_objs/%.o:core_srcs/%.c $(CORE_INC)
	@mkdir -p .core_objs/ops
	@$(COMPILER) $(CC_FLAGS) -Icore_includes -c $< -o $@ || (echo "\033[K \033[36mCORE :      \033[0m[\033[31m $(notdir $<)\033[0m ] \033[31m✕\033[0m")
	@echo "\033[K \033[36mCORE :      \033[0m[ compiling :\033[33m $(notdir $<)\033[0m ]\033[1A"


$(ASM): $(ASM_OBJS) $(ASM_INC) $(LIBFT)
	@$(COMPILER) $(CC_FLAGS) $(ASM_OBJS) -L libft/ -lft -o $(ASM) || (echo "\033[1A\033[K \033[36mCompilation\033[0m" "[\033[31m  " $(ASM) "\033[0m  ]" "\033[31m✕\033[0m"; exit 1)
	@echo " \033[36mCompilation\033[0m" "[\033[32;1m  " $(ASM) "\033[0m  ]" "\033[K\033[0;32;1m✓\033[0m"
 
$(COREWAR): $(CORE_OBJS) $(CORE_INC) $(LIBFT)
	@$(COMPILER) $(CC_FLAGS) $(NCURSES) $(CORE_OBJS) -L libft/ -lft -o $(COREWAR) || (echo "\033[1A\033[K \033[36mCompilation\033[0m" ["\033[31m" $(COREWAR)"\033[0m" ] "\033[31m✕\033[0m"; exit 1)
	@echo " \033[36mCompilation\033[0m" ["\033[32;1m" $(COREWAR)"\033[0m" ] "\033[K\033[0;32;1m✓\033[0m"

ifneq ($(shell make -q -C libft/;echo $$?), 0)
.PHONY: $(LIBFT)
$(VISU)
endif

$(LIBFT):
	@Make -C libft/

clean:
	@echo " \033[36mDeletion    \033[0m[\033[33m objects  \033[0m]"  "\033[K\033[0;32;1m✓\033[0m"
	@rm -rf $(CORE_OBJS)
	@rm -rf $(ASM_OBJS)
	@Make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@echo " \033[36mDeletion    \033[0m[\033[33m binaries \033[0m]"  "\033[K\033[0;32;1m✓\033[0m"
	@rm -rf $(LIBFT)
	@rm -rf $(ASM)
	@rm -rf $(COREWAR)

re: fclean
	@make all	

.PHONY: all clean fclean re
