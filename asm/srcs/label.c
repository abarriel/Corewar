/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:19:11 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/23 03:55:14 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "asm.h"

void	get_label(t_asm *a)
{
	char	*line;
	t_op	*op;
	t_lab	*l;

	l = init_lab();
	op = get_op();
	// ft_printf("{8}[%d]\n",op[5].type[0]);
	while (get_next_line(a->fd_cor, &line) > 0)
	{
		ft_printf("{8},%s\n",line);
	}
}
