/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:40:45 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 20:46:25 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		exec_live(void *core, void *pro)
{
	t_core			*cor;
	t_process		*pr;
	t_player		*pla;
	unsigned char	id[4];
	int				i;

	i = 0;
	pr = (t_process*)pro;
	cor = (t_core*)core;
	pla = cor->player;
	while (i < 4)
	{
		id[i] = cor->mem[(pr->pc + i + 1) % MEM_SIZE];
		i++;
	}
	pr->life_flag = 1;
	while (pla && !cmp_4_oct(&pla->id[0], &id[0]))
		pla = pla->next;
	if (pla)
	{
		pla->nb_live++;
		pla->last_live = cor->cycle;
		i = 0;
		while (i < 4)
		{
			cor->mem_c[(pr->pc + i + 1) % MEM_SIZE] = pla->color * 16 + 4;
			i++;
		}
	}
	return (5);
}

int		exec_st(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = get_n_arg(cr, pr, 1, 1);
	if (cr->mem[(pr->pc + 1) % MEM_SIZE] == (unsigned char)80)
		insert_in_reg(get_n_reg(cr, pr, 2), 0, res);
	else
	{
		insert_in_color(cr->mem_c, (pr->pc + get_n_arg(cr, pr, 2, 1))
			% MEM_SIZE, pr->player->color * 16 + 2, 4);
		insert_in_reg(cr->mem, ((unsigned short int)(pr->pc +
			((short int)get_n_arg(cr, pr, 2, 1) % IDX_MOD))
		% MEM_SIZE) % MEM_SIZE, res);
	}
	return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 4));
}

int		exec_sti(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;
	int				add;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = get_n_arg(cr, pr, 1, 1);
	add = real_int(get_n_arg(cr, pr, 2, 0) % MEM_SIZE) +
	real_int((get_n_arg(cr, pr, 3, 0) % MEM_SIZE));
	insert_in_color(cr->mem_c, uns_int((add % IDX_MOD) + pr->pc) % MEM_SIZE,
	pr->player->color * 16 + 2, 4);
	insert_in_reg(cr->mem, uns_int((add % IDX_MOD) + pr->pc) % MEM_SIZE, res);
	get_n_arg(cr, pr, 3, 0);
	return (size_args(cr->mem[(pr->pc + 1) % MEM_SIZE], 2));
}

int		exec_aff(void *core, void *pro)
{
	t_process		*pr;
	t_core			*cr;
	unsigned int	res;

	cr = (t_core*)core;
	pr = (t_process*)pro;
	res = chatoi(pr->reg[cr->mem[(pr->pc + 2) % MEM_SIZE] - 1]) % 256;
	return (3);
}
