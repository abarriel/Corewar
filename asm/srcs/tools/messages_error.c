/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 02:15:32 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/25 23:08:15 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** ERREUR DOIVE ETRE CHANGER CAR ISNTRUCTION PEUT ETRE ALBEL
*/

void	no_label_error(char *arg, char *str, int line, int cha)
{
	ft_dprintf(2, "No such label %3s while attempting to dereference", arg);
	ft_dprintf(2, " token[TOKEN][%03d:%03d] ", line, cha);
	ft_dprintf(2, "DIRECT_LABEL \"%s\"\n", str);
	exit(0);
}

void	invalid_error(char *str, int nb)
{
	ft_dprintf(2, "Invalid parameter %d for instruction %s\n", nb, str);
	exit(0);
}

void	syntax_error(char *str, int line, int character)
{
	ft_dprintf(2, "Syntax error at token [TOKEN]");
	ft_dprintf(2, "[%03d:%03d]", line, character);
	ft_dprintf(2, " INSTRUCTION \"%s\"\n", str);
	exit(0);
}

void	length_error(int i)
{
	if (i == 1)
		ft_dprintf(2, "Comment too long (Max length %d)\n", COMMENT_LENGTH);
	if (i == 2)
		ft_dprintf(2, "Champion name too long (Max length %d)\n", PROG_NAME_LENGTH);
	exit(0);
}
