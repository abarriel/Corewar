/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:29:02 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/29 10:12:58 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void print_map(t_core *core)
{
	unsigned char *map = core->mem;
	char *color = core->mem_c;
	int i = 0;
	int j = 0;
	int magic = 0;

	ft_printf("Map: \n");
	while (i < MEM_SIZE)
	{
		while (j < 64)
		{
			if (color[i] == 1)
				ft_printf("{1}%.2x", map[i]);
			else if (color[i] == 2)
				ft_printf("{2}%.2x", map[i]);
			else if (color[i] == 20)
				ft_printf("\033[4;32m%.2x", map[i]);
			else if (color[i] == 3)
				ft_printf("{3}%.2x", map[i]);
			else if (color[i] == 30)
				ft_printf("\033[4;33m%.2x", map[i]);
			else if (color[i] == 4)
				ft_printf("{4}%.2x", map[i]);
			else if (color[i] == 40)
				ft_printf("\033[4;34m%.2x", map[i]);
			else if (color[i] == 10)
			{
				// if (i == core->process->pc)
				// {
				// 	// BLINK 
				// 	magic = 5;
				// 	// Bold
				// 	//magic = 1;
				// 	ft_printf("\033[%d;31m%.2x", magic, map[i]);
				// 	//ft_printf("\033[%d;32m%.2x", magic, map[i]);
					
				// }
				// else	
					ft_printf("{1}%.2x", map[i]);
			}
			else
				ft_printf("%.2x", map[i]);
			j++;
			i++;
		}
		j = 0;
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_player(t_core *core)
{
	int i;
	t_player *tmp;

	tmp = core->player;
	while (tmp)
	{
		i = 0;
		ft_printf("\nName: [%s]\n", tmp->name);
		ft_printf("Magic: [%x]\n", tmp->magic);
		ft_printf("Comment: [%s]\n", tmp->comment);
		ft_printf("prog_size: [%d]\n", tmp->weight);
		ft_printf("ID: [%02x%02x%02x%02x]\n", tmp->id[0], tmp->id[1], tmp->id[2], tmp->id[3]);
		ft_printf("last_live: [%d]\n", tmp->last_live);
		ft_printf("nb_live: [%d]\n", tmp->nb_live);
		ft_printf("Programme: [");
		while (i < tmp->weight)
		{
			ft_printf("%.2x", tmp->prog[i]);
			i++;
		}
		ft_printf("]\n");
		tmp = tmp->next;
	}
}

void print_res(t_core *core)
{
	t_player *player;
	t_player *winner;

	player = core->player;
	winner = core->player;
	while (player)
	{
		if (player->last_live > winner->last_live)
			winner = player;
		player = player->next;
	}
	print_winner(winner);
}

int		main(int argc, char **argv)
{
	t_core	*core;

	core = new_core();
	parcing(argc, argv, core);
	print_player(core);
	init_core(core);
	// print_map(core);
	if (core->visu == 0)
  		run(core);
	else
		go_visu(core);
	print_res(core);
	return (0);
}
