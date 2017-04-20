# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarriel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 00:48:21 by abarriel          #+#    #+#              #
#    Updated: 2017/04/20 16:59:59 by abarriel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C ./asm
	@make -C ./vm

clean:
	@make clean -C ./asm
	@make clean -C ./vm

fclean:
	@make fclean -C ./asm
	@make fclean -C ./vm

re:
	@make re -C ./asm
	@make re -C ./vm

.PHONY: all clean fclean re
