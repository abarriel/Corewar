/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run__.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:25:28 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 20:58:14 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	free_process(t_process **pro)
{
	t_process	*tmp;
	int			i;

	i = 0;
	tmp = *pro;
	while (i < REG_NUMBER)
	{
		free(tmp->reg[i]);
		i++;
	}
	free(tmp->reg);
	free(tmp);
	tmp = NULL;
}

void	check_proces(t_process **pro)
{
	t_process	*tmp;
	t_process	*last;

	last = NULL;
	tmp = *pro;
	while (tmp)
	{
		if (tmp->life_flag == 0)
		{
			if (last)
				last->next = tmp->next;
			else
				*pro = tmp->next;
			free_process(&tmp);
		}
		else
		{
			tmp->life_flag = 0;
			last = tmp;
		}
		if (tmp)
			tmp = tmp->next;
		else
			tmp = *pro;
	}
}

void	upd_color_die(t_core *core)
{
	char	*map;
	int		i;

	map = core->mem_c;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (map[i] % 16 == 2)
			map[i] -= 2;
		if (map[i] % 16 == 4)
			map[i] -= 4;
		i++;
	}
}

void	die_check(t_core *core)
{
	static int nb_check = 0;

	if ((core->cycle - core->last_check) == core->die_cycle
		|| core->die_cycle < 0)
	{
		nb_check++;
		core->nb_player = count_live(core->player);
		if (core->nb_player >= NBR_LIVE || nb_check == MAX_CHECKS)
		{
			nb_check = 0;
			core->die_cycle -= CYCLE_DELTA;
		}
		check_proces(&core->process);
		core->last_check = core->cycle;
		upd_color_die(core);
	}
}
