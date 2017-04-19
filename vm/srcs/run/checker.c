/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:22:52 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 20:40:46 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_all_arg(t_core *core, t_process *pro, int index, int *ok)
{
	if (index == REG_CODE)
	{
		if (core->mem[(pro->pc + 1 + *ok) % MEM_SIZE] > REG_NUMBER)
			return (0);
		if (core->mem[(pro->pc + 1 + *ok) % MEM_SIZE] < 1)
			return (0);
		(*ok)++;
	}
	else if (index == DIR_CODE)
	{
		if (!pro->op->l_size)
			(*ok) += 4;
		else
			(*ok) += 2;
	}
	else if (index == IND_CODE)
		(*ok) += 2;
	return (1);
}

int		check_cde_rest(unsigned char index, t_process *pro)
{
	if (pro->op->nbr_args == 2)
	{
		if (15 & index)
			return (0);
	}
	if (pro->op->nbr_args == 1)
	{
		if (63 & index)
			return (0);
	}
	if (pro->op->nbr_args == 3)
	{
		if (3 & index)
			return (0);
	}
	return (1);
}

int		check_cde_oct(t_core *core, t_process *pro)
{
	int				ok;
	unsigned char	cde;
	unsigned char	index;
	int				arg;

	arg = 0;
	ok = 1;
	index = core->mem[(pro->pc + 1) % MEM_SIZE];
	while (arg != pro->op->nbr_args)
	{
		cde = apply_mask(index, arg + 1);
		if (cde & pro->op->type[arg])
		{
			if (!(check_all_arg(core, pro, cde, &ok)))
				return (0);
		}
		else
			return (0);
		arg++;
	}
	if (!check_cde_rest(index, pro))
		return (0);
	return (1);
}

int		checker_arg(t_core *core, t_process *pro)
{
	int	pc;

	pc = pro->pc;
	if (pro->op->cde_oct == 1)
	{
		if (!(check_cde_oct(core, pro)))
			return (0);
		pc += 1;
	}
	return (1);
}
