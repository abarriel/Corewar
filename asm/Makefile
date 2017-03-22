# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/19 11:33:06 by abarriel          #+#    #+#              #
#    Updated: 2017/03/22 22:55:28 by lcharvol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm

SRC		= asm.c setup.c header.c header2.c label.c

OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

INCLUDES = ../includes/asm.h ../includes/op.h

CFLAGS	=  -Wall -Wextra  -I../includes/ -I../libft/includes/

all: $(INCLUDES) makefile libft $(NAME)

libft:
	@make -C ../libft

$(NAME): libft $(OBJ) $(INCLUDES)
	@gcc $(OBJ) -o $(NAME)  -L../libft -lft

clean:
	@make clean -C ../libft
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make fclean -C ../libft

re: fclean all

.PHONY: clean fclean re libft all
