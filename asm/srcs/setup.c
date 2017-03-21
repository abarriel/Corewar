/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:36:08 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/21 09:30:02 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void 		lexical_error(int line, int character)
{
	ft_dprintf(2, "Lexical error at [%d:%d]\n", line, character);
	exit(0);
}

int 		skip_space(char **s)
{
	while ((**s) == ' ' || (**s) == '\t')
		(*s)++;
	return (0);
}

t_asm		*init_asm(void)
{
	t_asm		*a;

	if (!(a = (t_asm*)malloc(sizeof(t_asm))))
		ft_exit("Failed to Malloc Asm/Struct");
	a->champ_name = NULL;
	a->cor = NULL;
	a->fd_champ = -1;
	a->len_line = 0;
	a->count_line = 0;
	a->fd_cor = -1;
	return (a);
}

t_header	*init_header(void)
{
	t_header		*h;

	if (!(h = (t_header*)malloc(sizeof(t_header))))
		ft_exit("Failed to Malloc Asm/Struct");
	return (h);
}

