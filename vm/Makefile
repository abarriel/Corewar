# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/25 03:28:37 by lcharvol          #+#    #+#              #
#    Updated: 2017/03/25 03:28:38 by lcharvol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= vm

SRC		= vm.c messages.c parcing_entry.c  init/init_core.c visu/aff.c visu/draw.c visu/visu.c visu/other.c visu/other2.c visu/print.c

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
