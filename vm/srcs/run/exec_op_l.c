/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:18:53 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 20:50:10 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	exec_lfork(void *core, void *pro)
{
	t_core				*cor;
	t_process			*pr;
	t_process			*new;
	unsigned short int	jmp;

	pr = (t_process*)pro;
	cor = (t_core*)core;
	new = dup_process(pr);
	jmp = 0;
	jmp += (unsigned int)(cor->mem[(pr->pc + 1) % MEM_SIZE]) * 256;
	jmp += (unsigned int)(cor->mem[(pr->pc + 2) % MEM_SIZE]);
	new->pc = (new->pc + (jmp % MEM_SIZE)) % MEM_SIZE;
	cor->mem_c[new->pc] = 16 * new->player->color + 1;
	new->next = cor->process;
	cor->process = new;
	return (3);
}

int	exec_ld(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = get_n_arg(cr, pr, 1, 0);
	pr->carry = 1;
	insert_in_reg(get_n_reg(cr, pr, 2), 0, res);
	return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int	exec_lld(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = chatoi(&(cr->mem[(pr->pc + get_n_arg(cr, pr, 1, 0)) % MEM_SIZE]));
	pr->carry = 1;
	insert_in_reg(get_n_reg(cr, pr, 2), 0, res);
	return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int	exec_ldi(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;
	int				add;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	add = real_int(get_n_arg(cr, pr, 1, 0) % MEM_SIZE) +
	real_int((get_n_arg(cr, pr, 2, 0) % MEM_SIZE));
	res = chatoi(&(cr->mem[uns_int((add % IDX_MOD) + pr->pc) % MEM_SIZE]));
	insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
	return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
}

int	exec_lldi(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;
	int				add;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	add = real_int(get_n_arg(cr, pr, 1, 0) % MEM_SIZE) +
	real_int((get_n_arg(cr, pr, 2, 0) % MEM_SIZE));
	res = chatoi(&(cr->mem[uns_int((add % MEM_SIZE) + pr->pc) % MEM_SIZE]));
	pr->carry = 1;
	insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
	return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
}
