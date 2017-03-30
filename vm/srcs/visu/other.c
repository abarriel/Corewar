/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:42:27 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/23 15:48:03 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		go_visu(t_core *core)
{
	t_env 	*p;
  	t_but 	*but;

  	p = (t_env *)malloc(sizeof(t_env));
  	p->but = (t_but *)malloc(sizeof(t_but));
  	p->core = core;
  	ft_start_struct(p, but);
  	p->mlx = mlx_init();
  	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Corewar");
  	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
  	visu(p, but, core);
	print_player(core);
	mlx_loop(p->mlx);
	return (0);
}

int			ft_is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

void		ft_modif_color(int r, int v, int b, t_env *p)
{
	p->r = r;
	p->v = v;
	p->b = b;
}
