# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/25 03:28:37 by lcharvol          #+#    #+#              #
#    Updated: 2017/03/29 04:48:57 by cseccia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= vm

SRC		= vm.c messages.c parcing_entry.c tools.c \
			init/init_core.c run/run.c run/exec_op.c visu/aff.c visu/modifcolors.c visu/draw.c \
		 visu/visu.c visu/draw2.c visu/other.c visu/other2.c visu/print.c \
		 run/checker.c run/exec_op_.c run/get_n_arg.c

OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

INCLUDES = ../includes/vm.h ../includes/op.h

INIB_FLAGS = -Wno-error=unused-parameter -Wno-error=unused-variable
ALL_FLAGS = -Wall -Wextra -Werror
CFLAGS	=  -I../includes/ -I../libft/includes/

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
