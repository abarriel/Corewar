/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:29:02 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/20 23:14:04 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	find_player_nb(t_core *core)
{
	int			i;
	t_player	*p;

	i = 1;
	p = core->player;
	while (p)
	{
		while (already_use(core, i))
			i++;
		if (p->nb == 0)
			p->nb = i;
		i++;
		p = p->next;
	}
}

int		main(int argc, char **argv)
{
	t_core	*core;

	core = new_core();
	parcing(argc, argv, core);
	init_core(core);
	if (core->visu == 0)
	{
		if (core->debug == 0)
			run(core);
		else
			debug_run(core);
	}
	else
		go_visu(core);
	return (0);
}
