/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 23:24:39 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/25 23:24:40 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	lexical_error(int line, int character)
{
	ft_dprintf(2, "Lexical error at [%d:%d]\n", line, character);
	exit(0);
}

void	token_error(char *str, int line, int character)
{
	ft_printf("Invalid instruction at token [TOKEN]");
	ft_printf("[%03d:%03d] INSTRUCTION \"%s\"\n", line, character, str);
	exit(0);
}
