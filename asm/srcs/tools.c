/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 08:51:24 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/23 08:56:07 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void print_label(t_lab *lab)
{
	if (lab)
		ft_printf("{8} %s:  Recup ligne : %d\n","Label Vide", lab->count_line);
	lab = lab->next;
	while (lab)
	{
		ft_printf("{8} %s:  Recup ligne : %d\n",lab->label, lab->count_line);
		// while(lab->cmd)
		// {
			// ft_printf("{9}\e %s\n",lab->cmd->op);
			// lab->cmd = lab->cmd->next;
		// }
		lab = lab->next;
	}
}
