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
	while (core->player)
	{
		ft_printf("Name: [%s]\n", core->player->name);
		ft_printf("Comment: [%s]\n", core->player->comment);
		ft_printf("prog_size: [%d]\n\n", core->player->weight);
		core->player = core->player->next;
	}
}

int		main(int argc, char **argv)
{
	t_core	*core;

	core = new_core();
	parcing(argc, argv, core);
	if (core->visu == 1)
		visu(core);
	//print_player(core);
	//init_core(core);
	//run(core);
	//print_res(core);
	return (0);
}
