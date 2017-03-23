/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 02:15:32 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/23 02:15:55 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			lexical_error(int line, int character)
{
	ft_dprintf(2, "Lexical error at [%d:%d]\n", line, character);
	exit(0);
}

void			syntax_error(char *str, int line, int character)
{
	ft_printf("Syntax error at token [TOKEN][%d:%d] LABEL ''%s''\n",
		line ,character ,str);
	exit(0);
}

void			length_error(int i)
{
	if (i == 1)
		ft_printf("Comment too long (Max length %d)\n", COMMENT_LENGTH);
	if (i == 2)
		ft_printf("Champion name too long (Max length %d)\n", PROG_NAME_LENGTH);
	exit(0);
}
