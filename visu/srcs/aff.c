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

#include "../includes/visualisateur.h"

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

void 		ft_draw_arena(t_env *p)
{
	p->r = 255;
	p->v = 255;
	p->b = 255;
	p->h = (HEIGHT) - 20;
	p->l = (WIDTH  * 0.7) - 20;
	ft_draw_rectangle(10, 10, p);
}

void		ft_draw_menu(t_env *p)
{
	p->r = 55;
	p->v = 55;
	p->b = 55;
	p->h = 200;
	p->l = WIDTH - (WIDTH * 0.7) - 10;
	ft_draw_rectangle((WIDTH  * 0.7), 10, p);
	p->r = 55;
	p->v = 55;
	p->b = 55;
	p->h = (HEIGHT) - 230;
	p->l = WIDTH - (WIDTH * 0.7) - 10;
	ft_draw_rectangle((WIDTH  * 0.7), 220, p);
}

void		ft_draw_background(t_env *p)
{
	int		i;

	i = 0;
	while (i < (HEIGHT * WIDTH * 4))
	{
		(p->ret)[i] = 32;
		(p->ret)[i + 1] = 32;
		(p->ret)[i + 2] = 32;
		(p->ret)[i + 3] = 0;
		i += 4;
	}
}

void		ft_draw(t_env *p)
{
	ft_draw_background(p);
	ft_draw_arena(p);
	ft_draw_menu(p);
}
