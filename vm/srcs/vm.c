/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:29:02 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/25 08:23:20 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void run(t_core *core)
{
	while (core->nb_player != 0)
	{
		//lunch_op(core);
		//decrease(core);
		//exec(core);
		//upd_core(core);
	}
}

void	print_player(t_core *core)
{
	int i;
	while (core->player)
	{
		i = 0;
		ft_printf("\nName: [%s]\n", core->player->name);
		ft_printf("Magic: [%x]\n", core->player->magic);
		ft_printf("Comment: [%s]\n", core->player->comment);
		ft_printf("prog_size: [%d]\n", core->player->weight);
		ft_printf("ID: [%02x%02x%02x%02x]\n", core->player->id[0], core->player->id[1], core->player->id[2], core->player->id[3]);
		ft_printf("last_live: [%d]\n", core->player->last_live);
		ft_printf("nb_live: [%d]\n", core->player->nb_live);
		ft_printf("Programme: [");
		while (i < core->player->weight)
		{
			ft_printf("%.2x", core->player->prog[i]);
			i++;
		}
		ft_printf("]\n");
		core->player = core->player->next;
	}
}

int		main(int argc, char **argv)
{
	t_core	*core;

	core = new_core();
	parcing(argc, argv, core);
	print_player(core);
	//init_core(core);
	//run(core);
	//print_res(core);
	return (0);
}
