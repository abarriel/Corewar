# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/25 03:28:37 by lcharvol          #+#    #+#              #
#    Updated: 2017/04/20 17:59:12 by cseccia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= corewar

SRC		= vm.c  \
	parser.c \
	parser_.c \
	\
	debug/messages.c \
	debug/vm_map_.c \
	debug/vm_map.c \
	debug/tools.c \
	\
	init/init_core.c \
	init/sort_process.c \
	\
	run/checker.c \
	run/exec_op.c \
	run/exec_op_.c \
	run/exec_op_bin.c \
	run/exec_op_l.c \
	run/get_n_arg.c\
	run/get_tools.c \
	run/get_tools_.c \
	run/run.c \
	run/run_.c \
	run/run_check.c \
	\
	visu/aff.c \
	visu/modifcolors.c\
	visu/draw.c \
	visu/visu.c \
	visu/draw2.c \
	visu/other.c \
	visu/other2.c \
	visu/print.c \


OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

INCLUDES = ../includes/vm.h ../includes/op.h

INIB_FLAGS = -Wno-error=unused-parameter -Wno-error=unused-variable
ALL_FLAGS = -Wall -Wextra -Werror
CFLAGS	=  $(ALL_FLAGS) -I../includes/ -I../libft/includes/

all: $(INCLUDES) makefile libft $(NAME)

libft:
	@make -C ../libft

$(NAME): libft $(OBJ) $(INCLUDES)
	@gcc $(OBJ) -o $(NAME)  -L../libft -lft -framework OpenGL -framework AppKit -L../includes/mlx -lm -lmlx

clean:
	@make clean -C ../libft
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make fclean -C ../libft

re: fclean all

.PHONY: clean fclean re libft all
