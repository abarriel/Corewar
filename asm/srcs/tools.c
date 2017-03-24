/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 08:51:24 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/24 03:55:45 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void print_label(t_lab *lab)
{
	while (lab)
	{
		ft_printf("{8} %s:  line: %d\n",lab->label, lab->count_line);
		while(lab->cmd)
		{
			ft_printf("{9}\t%s - ",lab->cmd->op);
			ft_printf("{5}%s\n",lab->cmd->args);
			lab->cmd = lab->cmd->next;
		}
		lab = lab->next;
	}
}
