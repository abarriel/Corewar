/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 10:13:08 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/21 16:26:17 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		check_button_hit(int button, int x, int y, t_env *p)
{
	if (button == 1)
	{
		if ((x <= (HEIGHT) + 105) && (x >= (HEIGHT) + 35) && (y <=
			(HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn1_s = 80;
			p->but->btn1_px = (HEIGHT) + 30;
			p->but->btn1_py = (HEIGHT) - 125;
			p->pause = 0;
		}
		if ((x <= (HEIGHT) + 265) && (x >= (HEIGHT) + 185) && (y <=
			(HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn2_s = 80;
			p->but->btn2_px = (HEIGHT) + 180;
			p->but->btn2_py = (HEIGHT) - 125;
			p->pause = 1;
		}
	}
	check_button_hit2(button, x, y, p);
}

static int	ft_loop_key_hook(t_env *p)
{
	int		cycle_sec_tmp;
	int		cycle_tmp;

	cycle_sec_tmp = p->core->cycle_sec;
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->ret = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
		&(p->size_line), &(p->endian));
	cycle_tmp = p->core->cycle;
	if (p->pause == 0 && p->core->nb_player != 0 && p->core->dump != 0)
	{
		while (cycle_sec_tmp != 0)
		{
			run_visu(p->core);
			cycle_sec_tmp--;
		}
	}
	if (cycle_tmp == p->core->cycle && p->pause == 0 && p->melenchon == 0)
		print_res_visu(p->core, p);
	ft_draw(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_put_image_to_window(p->mlx, p->win, p->img2, 0, 0);
	print_text(p);
	init_but(p);
	return (0);
}

int			ft_key_hook(int keycode, t_env *p)
{
	int		i;

	i = 1;
	if (keycode == ECHAP)
		exit(1);
	if (keycode == SPACE)
	{
		if (p->pause == 1)
			p->pause = 0;
		else if (p->pause == 0)
			p->pause = 1;
	}
	if (keycode == RIGHT && p->core->cycle_sec <= 2000)
		p->core->cycle_sec++;
	if (keycode == LEFT)
	{
		if (p->core->cycle_sec - 1 > 0)
			p->core->cycle_sec--;
	}
	ft_loop_key_hook(p);
	return (0);
}

int			ft_mouse_hook(int button, int x, int y, t_env *p)
{
	check_button_hit(button, x, y, p);
	ft_loop_key_hook(p);
	return (0);
}

int			visu(t_env *p, t_core *c)
{
	p->core = c;
	ft_loop_key_hook(p);
	mlx_hook(p->win, 2, 2, ft_key_hook, p);
	mlx_mouse_hook(p->win, ft_mouse_hook, p);
	mlx_loop_hook(p->mlx, ft_loop_key_hook, p);
	return (0);
}
