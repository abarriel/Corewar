/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 21:07:31 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 23:51:15 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			exec_fork(void *core, void *pro)
{
	t_core				*cor;
	t_process			*pr;
	t_process			*new;
	unsigned short int	jmp;

	pr = (t_process*)pro;
	cor = (t_core*)core;
	new = dup_process(pr);
	jmp = 0;
	jmp += ((unsigned int)(cor->mem[(pr->pc + 1)]) * 256);
	jmp += (unsigned int)(cor->mem[(pr->pc + 2)]);
	new->pc = (new->pc + (((short int)jmp % MEM_SIZE) % IDX_MOD)) % MEM_SIZE;
	cor->mem_c[new->pc] = 16 * new->player->color + 1;
	new->next = cor->process;
	cor->process = new;
	return (3);
}

int			exec_zjmp(void *core, void *pro)
{
	t_core				*cor;
	t_process			*pr;
	unsigned short int	jmp;

	pr = (t_process*)pro;
	if (pr->carry == 0)
		return (3);
	jmp = 0;
	cor = (t_core*)core;
	jmp += (unsigned int)(cor->mem[(pr->pc + 1) % MEM_SIZE]) * 256;
	jmp += (unsigned int)(cor->mem[(pr->pc + 2) % MEM_SIZE]);
	cor->mem_c[pr->pc] = pr->player->color * 16;
	pr->pc = (pr->pc +
	(uns_int(real_int(jmp % MEM_SIZE) % IDX_MOD))) % MEM_SIZE;
	return (0);
}

void		exec_op(t_core *core, t_process *pro)
{
	int	exec;

	if (pro->op->mnemonique)
	{
		if (pro->op->cde_oct == 0 || checker_arg(core, pro) == 1)
			exec = pro->op->f(core, pro);
		else
			exec = -1;
	}
	else
		exec = 1;
	if (exec == -1)
	{
		core->mem_c[pro->pc] = pro->player->color * 16;
		if (pro->op->cde_oct == 1)
			pro->pc = (pro->pc + size_args(core->mem[(pro->pc + 1) %
			MEM_SIZE], 4 - 2 * pro->op->l_size)) % MEM_SIZE;
		else
			pro->pc = (pro->pc + 1) % MEM_SIZE;
	}
	else
	{
		core->mem_c[pro->pc] = pro->player->color * 16;
		pro->pc = (pro->pc + exec) % MEM_SIZE;
	}
}
