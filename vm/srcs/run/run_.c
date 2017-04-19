/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:24:39 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/20 00:10:23 by cseccia          ###   ########.fr       */
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

t_process	*moove_last(t_core *core, t_process *pro)
{
	t_process	*tmp;
	t_process	*last;
	t_process	*res;

	if (!core->process->next)
		return (core->process);
	last = NULL;
	tmp = core->process;
	while (tmp != pro)
	{
		last = tmp;
		tmp = tmp->next;
	}
	res = tmp->next;
	if (!res)
		return (res);
	if (last)
		last->next = tmp->next;
	else
		core->process = tmp->next;
	last = tmp;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->next = NULL;
	return (res);
}
