# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseccia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 22:04:14 by cseccia           #+#    #+#              #
#    Updated: 2017/03/22 22:04:52 by cseccia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECK	= checker
NAME_PUSH	= push_swap

SRC_CHECK		= checker.c tolls.c
SRC_COMMON		= common.c add_to_pile.c push_swap_func.c rotate_func.c double_func.c
SRC_PUSH		= push_swap.c go_to_nearest.c resolve.c pile_func.c algo_2.c

OBJ_CHECK		= $(addprefix checker_src/,$(SRC_CHECK:.c=.o))
OBJ_PUSH		= $(addprefix push_swap_src/,$(SRC_PUSH:.c=.o))
OBJ_COMMON		= $(addprefix common/,$(SRC_COMMON:.c=.o))

CFLAGS	=  -Wall -Wextra -Werror

all: makefile libft $(NAME_CHECK) $(NAME_PUSH)

libft:
	@make -C libft/

$(NAME_CHECK): $(OBJ_CHECK) $(OBJ_COMMON) libft
	@gcc $(OBJ_CHECK) $(OBJ_COMMON) -o $(NAME_CHECK)  libft/libft.a

$(NAME_PUSH): $(OBJ_PUSH) $(OBJ_COMMON) libft
	@gcc $(OBJ_PUSH) $(OBJ_COMMON) -o $(NAME_PUSH)  -Llibft/ -lft

clean:
	@make clean -C libft/
	@rm -rf $(OBJ_CHECK)
	@rm -rf $(OBJ_PUSH)
	@rm -rf $(OBJ_COMMON)

fclean: clean
	@rm -rf $(NAME_CHECK) $(NAME_PUSH)
	@make fclean -C libft/

re: fclean all

.PHONY: clean fclean re libft all
