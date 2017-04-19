# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/19 11:33:06 by abarriel          #+#    #+#              #
#    Updated: 2017/03/24 08:52:12 by abarriel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= asm

SRC		=  main.c \
init/header.c \
init/header_.c \
init/setup.c \
init/setup_.c \
 \
lexer/lexer.c \
lexer/lexer_.c \
\
printing/final_write.c \
printing/write_args.c \
printing/write_label.c \
\
syntax/syntax.c \
syntax/syntax_.c \
syntax/syntax__.c \
\
tools/messages_error.c \
tools/messages_error_.c \
\
fun/bonus.c \
fun/bonus_.c \

OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

INCLUDES = ../includes/asm.h ../includes/op.h

ALL_FLAGS = -Wall -Wextra -Werror
CFLAGS	=  $(ALL_FLAGS) -I../includes/ -I../libft/includes/

all:  makefile libft  $(INCLUDES) $(NAME)

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
