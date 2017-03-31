/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 10:13:08 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/23 15:44:28 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_loop_key_hook(t_env *p)
{
	char	*str;
	int     cycle_sec_tmp;

	cycle_sec_tmp = p->core->cycle_sec;
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->ret = mlx_get_data_addr(p->img, &(p->bits_per_pixel), 
		&(p->size_line), &(p->endian));
	if (p->pause == 0 && p->core->nb_player != 0 && p->core->dump != 0)
	{
		while (cycle_sec_tmp != 0)
		{
			run_visu(p->core, p);
			cycle_sec_tmp--;
		}	
	}
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
	int		j;

	i = 1;
	if (keycode == ECHAP)
		exit(1);
	ft_loop_key_hook(p);
	return (0);
}

int			ft_mouse_hook(int button, int x, int y, t_env *p)
{
	check_button_hit(button, x, y, p);
	ft_loop_key_hook(p);
	return (0);
}

void		check_button_hit(int button, int x, int y, t_env *p)
{
	if (button == 1)
	{
		if ((x <= (HEIGHT) + 105) && (x >= (HEIGHT) + 35) && (y <= (HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn1_s = 80;
			p->but->btn1_px = (HEIGHT) + 30;
			p->but->btn1_py = (HEIGHT) - 125;
			p->pause = 0;
		}
		if ((x <= (HEIGHT) + 265) && (x >= (HEIGHT) + 185) && (y <= (HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn2_s = 80;
			p->but->btn2_px = (HEIGHT) + 180;
			p->but->btn2_py = (HEIGHT) - 125;
			p->pause = 1;
		}
		if ((x <= (HEIGHT) + 405) && (x >= (HEIGHT) + 335) && (y <= (HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn3_s = 80;
			p->but->btn3_px = (HEIGHT) + 330;
			p->but->btn3_py = (HEIGHT) - 125;
			p->core->cycle_sec--;
		}
		if ((x <= (HEIGHT) + 565) && (x >= (HEIGHT) + 485) && (y <= (HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn4_s = 80;
			p->but->btn4_px = (HEIGHT) + 480;
			p->but->btn4_py = (HEIGHT) - 125;
			p->core->cycle_sec++;
		}
		if ((x <= (HEIGHT) + 705) && (x >= (HEIGHT) + 635) && (y <= (HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn5_s = 80;
			p->but->btn5_px = (HEIGHT) + 630;
			p->but->btn5_py = (HEIGHT) - 125;
			p->cycle_count = 1;
		}
	}
}

int			visu(t_env *p, t_but *but, t_core *c)
{
	p->core = c;
	ft_loop_key_hook(p);
	mlx_hook(p->win, 2, 2, ft_key_hook, p);
	mlx_mouse_hook(p->win, ft_mouse_hook, p);
	mlx_loop_hook(p->mlx, ft_loop_key_hook, p);
	return (0);
}
