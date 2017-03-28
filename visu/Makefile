# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/04 10:13:27 by lcharvol          #+#    #+#              #
#    Updated: 2017/02/04 10:13:29 by lcharvol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= visualisateur

SRC		= aff.c draw.c print.c main.c other.c other2.c 

OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

INCLUDES = includes/visualisateur.h

INIB_FLAGS = -Wno-error=unused-parameter -Wno-error=unused-variable
ALL_FLAGS = -Wall -Wextra -Werror
CFLAGS	=  -Iincludes/ -Ilibft/includes/

all:  makefile libft minilx $(NAME) $(INCLUDES)

libft:
	@make -C ../libft

minilx:
	@make -C ./includes/mlx

$(NAME): libft minilx $(OBJ) $(INCLUDES)
	@gcc $(OBJ) -o $(NAME)  -L../libft -lft  -framework OpenGL -framework AppKit -L./includes/mlx -lm -lmlx

clean:
	@make clean -C ../libft
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make fclean -C ../libft

re: fclean all

.PHONY: clean fclean re libft all
