/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:24:39 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 20:58:06 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		insert_op(t_process *pro, unsigned char *mem, t_op *tab_op)
{
	if (mem[pro->pc] < 17 && mem[pro->pc] > 0)
		pro->op = &tab_op[mem[pro->pc] - 1];
	else
		pro->op = &tab_op[16];
	pro->cycle_left = pro->op->nbr_cycles;
}

void		lunch_op(t_core *core)
{
	t_process	*pro;

	pro = core->process;
	while (pro)
	{
		if (pro->op == NULL)
			insert_op(pro, core->mem, core->op);
		pro = pro->next;
	}
}

void		decrease(t_core *core)
{
	t_process	*pro;

	pro = core->process;
	while (pro)
	{
		if (pro->cycle_left)
			pro->cycle_left -= 1;
		pro = pro->next;
	}
}
