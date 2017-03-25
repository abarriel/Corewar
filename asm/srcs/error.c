/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 02:15:32 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/24 10:12:07 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/* 
**ERREYR DOIVE ETRE CHANGER CAR ISNTRUCTION PEUT ETRE ALBEL
*/
void			lexical_error(int line, int character)
{
	ft_dprintf(2, "Lexical error at [%d:%d]\n", line, character);
	exit(0);
}

void			token_error(char *str, int line, int character)
{
	ft_printf("Invalid instruction at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n",
		line ,character ,str);
	exit(0);
}

void		no_label_error(char *arg,char *str, int line, int character)
{
	ft_printf("No such label %3s while attempting to dereference token [TOKEN][%03d:%03d] DIRECT_LABEL \"%s\"\n",
		arg ,line, character ,str);
	exit(0);
}

void			invalid_error(char *str, int nb)
{
	ft_printf("Invalid parameter %d for instruction %s\n", nb , str);
	exit(0);
}

void			syntax_error(char *str, int line, int character)
{
	ft_printf("Syntax error at token [TOKEN][%03d:%03d] INSTRUCTION \"%s\"\n",
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
