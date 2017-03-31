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

void		init_but(t_env *p)
{
	p->but->btn1_s = 70;
	p->but->btn1_px = (HEIGHT) + 35;
	p->but->btn1_py = (HEIGHT) - 120;
	p->but->btn2_s = 70;
	p->but->btn2_px = (HEIGHT) + 185;
	p->but->btn2_py = (HEIGHT) - 120;
	p->but->btn3_s = 70;
	p->but->btn3_px = (HEIGHT) + 335;
	p->but->btn3_py = (HEIGHT) - 120;
	p->but->btn4_s = 70;
	p->but->btn4_px = (HEIGHT) + 485;
	p->but->btn4_py = (HEIGHT) - 120;
	p->but->btn5_s = 70;
	p->but->btn5_px = (HEIGHT) + 635;
	p->but->btn5_py = (HEIGHT) - 120;
}


void		ft_start_struct(t_env *p, t_but *but)
{
	p->r = 0;
	p->v = 0;
	p->b = 0;
	p->pause = 1;
	p->speed = 1;
	p->cycle_count = p->core->cycle;
	p->map_size_x = 0;
	p->map_size_y = 0;
	p->but->btn1_s = 70;
	p->but->btn1_py = (HEIGHT) - 120;
	p->but->btn1_px = (HEIGHT) + 35;
	p->but->btn2_s = 70;
	p->but->btn2_px = (HEIGHT) + 185;
	p->but->btn2_py = (HEIGHT) - 120;
	p->but->btn3_s = 70;
	p->but->btn3_px = (HEIGHT) + 335;
	p->but->btn3_py = (HEIGHT) - 120;
	p->but->btn4_s = 70;
	p->but->btn4_px = (HEIGHT) + 485;
	p->but->btn4_py = (HEIGHT) - 120;
	p->but->btn5_s = 70;
	p->but->btn5_px = (HEIGHT) + 635;
	p->but->btn5_py = (HEIGHT) - 120;
}

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
