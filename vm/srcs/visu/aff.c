/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:31:16 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/05 20:31:20 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_draw_rectangle(int start_x, int start_y, t_env *p)
{
	int		i;
	int		i2;
	int		t;

	i2 = 0;
	t = 0;
	while (i2 < (p->h * 4))
	{
		i = 0;
		while (i < (p->l * 4))
		{
			p->ret[i + t + ((start_y * WIDTH * 4) + (start_x * 4))] = p->r;
			p->ret[i + t + 1 + ((start_y * WIDTH * 4) + (start_x * 4))] = p->v;
			p->ret[i + t + 2 + ((start_y * WIDTH * 4) + (start_x * 4))] = p->b;
			p->ret[i + t + 3 + ((start_y * WIDTH * 4) + (start_x * 4))] = 0;
			i += 4;
		}
		i2 += 4;
		t += (WIDTH * 4);
	}
}

void		ft_draw_square(int start_x, int start_y, int size, t_env *p)
{
	int		i;
	int		i2;
	int		tmp;

	i2 = 0;
	tmp = 0;
	while (i2 < (size * 4))
	{
		i = 0;
		while (i < (size * 4))
		{
			p->ret[i + tmp + ((start_y * WIDTH * 4) +
				(start_x * 4))] = p->r;
			p->ret[i + tmp + 1 + ((start_y * WIDTH * 4) +
				(start_x * 4))] = p->v;
			p->ret[i + tmp + 2 + ((start_y * WIDTH * 4) +
				(start_x * 4))] = p->b;
			p->ret[i + tmp + 3 + ((start_y * WIDTH * 4) +
				(start_x * 4))] = 0;
			i += 4;
		}
		i2 += 4;
		tmp += (WIDTH * 4);
	}
}

void		ft_draw_title(t_env *p)
{
	int		n;
	int		r;

	p->img2 = mlx_xpm_file_to_image(p->mlx, "title2.xpm", &n, &r);
	p->ret2 = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
		&(p->size_line), &(p->endian));
}

void		ft_draw_button(t_env *p)
{
	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 20,(HEIGHT) - 135 , 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn1_px, p->but->btn1_py , p->but->btn1_s, p);

	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 170,(HEIGHT) - 135 , 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn2_px, p->but->btn2_py, p->but->btn2_s, p);

	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 320,(HEIGHT) - 135 , 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn3_px, p->but->btn3_py, p->but->btn3_s, p);

	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 470,(HEIGHT) - 135 , 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn4_px, p->but->btn4_py, p->but->btn4_s, p);

	ft_modif_color(25, 25, 25, p);
	ft_draw_square((HEIGHT) + 620,(HEIGHT) - 135 , 100, p);
	ft_modif_color(35, 35, 35, p);
	ft_draw_square(p->but->btn5_px, p->but->btn5_py, p->but->btn5_s, p);
}

void		ft_draw(t_env *p)
{
	ft_draw_background(p);
	ft_draw_arena(p);
	ft_draw_menu(p);
	ft_draw_score(p);
	ft_draw_title(p);
	ft_draw_button(p);
}
