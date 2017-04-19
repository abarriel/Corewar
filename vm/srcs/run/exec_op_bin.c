/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:18:59 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 20:48:25 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	exec_add(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = chatoi(pr->reg[cr->mem[(pr->pc + 2) % MEM_SIZE] - 1]) +
	chatoi(pr->reg[cr->mem[(pr->pc + 3) % MEM_SIZE] - 1]);
	if (res == 0)
		pr->carry = 1;
	else
		pr->carry = 0;
	insert_in_reg(pr->reg[cr->mem[(pr->pc + 4) % MEM_SIZE] - 1], 0, res);
	return (5);
}

int	exec_sub(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = chatoi(pr->reg[cr->mem[(pr->pc + 2) % MEM_SIZE] - 1]) -
	chatoi(pr->reg[cr->mem[(pr->pc + 3) % MEM_SIZE] - 1]);
	if (res == 0)
		pr->carry = 1;
	else
		pr->carry = 0;
	insert_in_reg(pr->reg[cr->mem[(pr->pc + 4) % MEM_SIZE] - 1], 0, res);
	return (5);
}

int	exec_and(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = get_n_arg(cr, pr, 1, 1) & get_n_arg(cr, pr, 2, 1);
	pr->carry = 1;
	insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
	return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int	exec_or(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = get_n_arg(cr, pr, 1, 1) | get_n_arg(cr, pr, 2, 1);
	pr->carry = 1;
	insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
	return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int	exec_xor(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = get_n_arg(cr, pr, 1, 1) ^ get_n_arg(cr, pr, 2, 1);
	pr->carry = 1;
	insert_in_reg(get_n_reg(cr, pr, 3), 0, res);
	return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}
