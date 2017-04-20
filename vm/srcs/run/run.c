/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 21:53:55 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/20 17:52:34 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process	*dup_process(t_process *pro)
{
	t_process	*new;
	int			i;

	new = (t_process*)malloc(sizeof(t_process));
	new->pc = pro->pc;
	new->life_flag = pro->life_flag;
	new->cycle_left = 0;
	new->op = NULL;
	new->carry = pro->carry;
	new->player = pro->player;
	new->reg = (unsigned char**)malloc(sizeof(unsigned char *) * REG_NUMBER);
	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = (unsigned char*)malloc(sizeof(unsigned char) * REG_SIZE);
		new->reg[i] = cp_reg(new->reg[i], pro->reg[i]);
		i++;
	}
	return (new);
}

void		exec(t_core *core)
{
	t_process	*pro;

	pro = core->process;
	while (pro)
	{
		if (pro->op != NULL && pro->cycle_left == 0)
		{
			exec_op(core, pro);
			core->mem_c[pro->pc] = pro->player->color * 16 + 1;
			pro->op = NULL;
		}
		else
		{
			core->mem_c[pro->pc] = pro->player->color * 16 + 1;
			pro = pro->next;
		}
	}
}

int			count_live(t_player *players)
{
	t_player	*tmp;
	int			res;

	res = 0;
	tmp = players;
	while (tmp)
	{
		res += tmp->nb_live;
		tmp->nb_live = 0;
		tmp = tmp->next;
	}
	return (res);
}

void		run_visu(t_core *core)
{
	core->cycle += 1;
	lunch_op(core);
	decrease(core);
	exec(core);
	die_check(core);
	if (core->dump != -1)
		core->dump--;
	if (core->dump == 0)
		print_map(core);
}

void		run(t_core *core)
{
	while (core->nb_player != 0 && core->dump != 0)
	{
		core->cycle += 1;
		lunch_op(core);
		decrease(core);
		exec(core);
		die_check(core);
		if (core->dump != -1)
			core->dump--;
	}
	if (core->nb_player == 0)
		print_res(core);
	if (core->dump != -1)
		print_map(core);
}
