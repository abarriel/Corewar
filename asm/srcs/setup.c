/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:36:08 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/25 23:12:27 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** RID RDI FOR SILENCE WARNING
*/
#include "asm.h"

t_asm		*init_asm(void)
{
	t_asm		*a;

	if (!(a = (t_asm*)malloc(sizeof(t_asm))))
		ft_exit("Failed to Malloc Asm/Struct");
	a->champ_name = NULL;
	a->cor = NULL;
	a->fd_champ = -1;
	a->len_line = 0;
	a->line_ = 0;
	a->nb_label = 1;
	a->count_line = 0;
	a->header_passage = 0;
	a->fd_cor = -1;
	return (a);
}

t_header	*init_header(void)
{
	t_header	*h;

	if (!(h = (t_header*)malloc(sizeof(t_header))))
		ft_exit("Failed to Malloc Asm/Struct");
	return (h);
}

t_lab		*init_lab(char *label, t_asm *a)
{
	t_lab	*l;

	if (!(l = (t_lab*)malloc(sizeof(t_lab))))
		ft_exit("Failed to Malloc Asm/Struct");
	l->label = label;
	l->count_line = a->count_line;
	l->next = NULL;
	l->cmd = NULL;
	l->colon = 0;
	l->line = 0;
	return (l);
}

void		add_back_lab(t_lab **l_t, char *label, t_asm *a)
{
	t_lab *l;

	l = *l_t;
	if (!l)
	{
		(*l_t) = init_lab(label, a);
		return ;
	}
	while (l->next)
		l = l->next;
	l->next = init_lab(label, a);
}
