/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:19:11 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/22 22:56:28 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_label(t_asm *a, t_header *h)
{
	char	*line;

	while (get_next_line(a->fd_cor, &line))
		ft_printf("{8},%s\n",line);
}
