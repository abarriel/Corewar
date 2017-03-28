/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 01:53:37 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/24 01:53:38 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisateur.h"

void		ft_draw_map(t_env *p)
{
	int i;
	int i2;
	int e;
	float size;

	e = 1;
	i = 0;
	size = (((HEIGHT - 20)) / (MAP_SIZE_Y)) - e;
	while (i < MAP_SIZE_Y)
	{
		i2 = 0;
		while (i2 < MAP_SIZE_X)
		{	
			ft_modif_color(35, 35, 35 , p);
			ft_draw_square(((i2) * (size + e)) + 18, ((i) * (size + e)) + 18, size, p);
			i2++;
		}
		i++;
	}
}

void		ft_draw_score(t_env *p)
{
	ft_modif_color(20, 20, 20, p);
	p->l = WIDTH - (HEIGHT) - 150;
	p->h = 20;
	ft_draw_rectangle((HEIGHT + 100), 270, p);
	ft_modif_color(60, 76, 231, p);
	p->l = (p->cycle_count) / 10;
	p->h = 20;
	ft_draw_rectangle((HEIGHT + 100), 270, p);

	ft_modif_color(20, 20, 20, p);
	p->l = WIDTH - (HEIGHT) - 150;
	p->h = 20;
	ft_draw_rectangle((HEIGHT + 100), 320, p);
	ft_modif_color(113, 204, 46, p);
	p->l = (p->cycle_count) / 10;
	p->h = 20;
	ft_draw_rectangle((HEIGHT + 100), 320, p);

	ft_modif_color(20, 20, 20, p);
	p->l = WIDTH - (HEIGHT) - 150;
	p->h = 20;
	ft_draw_rectangle((HEIGHT + 100), 370, p);
	ft_modif_color(219, 152, 52, p);
	p->l = (p->cycle_count) / 10;
	p->h = 20;
	ft_draw_rectangle((HEIGHT + 100), 370, p);

	ft_modif_color(20, 20, 20, p);
	p->l = WIDTH - (HEIGHT) - 150;
	p->h = 20;
	ft_draw_rectangle((HEIGHT + 100), 420, p);
	ft_modif_color(15, 196, 241, p);
	p->l = (p->cycle_count) / 10;
	p->h = 20;
	ft_draw_rectangle((HEIGHT + 100), 420, p);
}


void 		ft_draw_arena(t_env *p)
{
	ft_modif_color(15, 15, 15, p);
	ft_draw_square(10, 10, (HEIGHT - 20), p);
	ft_draw_map(p);
}

void		ft_draw_menu(t_env *p)
{
	ft_modif_color(35, 35, 35, p);
	p->h = 200;
	p->l = WIDTH - (HEIGHT + 10);
	ft_draw_rectangle((HEIGHT), 10, p);

	p->h = (HEIGHT) - 230;
	p->l = WIDTH - (HEIGHT + 10);
	ft_draw_rectangle((HEIGHT), 220, p);
	ft_modif_color(30, 30, 30, p);
	p->h = 235;
	p->l = WIDTH - (HEIGHT + 50);
	ft_draw_rectangle((HEIGHT) + 20, 240, p);

	ft_modif_color(30, 30, 30, p);
	p->h = 600;
	p->l = WIDTH - (HEIGHT + 50);
	ft_draw_rectangle((HEIGHT) + 20, 490, p);
}

void		ft_draw_background(t_env *p)
{
	int		i;

	i = 0;
	while (i < (HEIGHT * WIDTH * 4))
	{
		(p->ret)[i] = 20;
		(p->ret)[i + 1] = 20;
		(p->ret)[i + 2] = 20;
		(p->ret)[i + 3] = 0;
		i += 4;
	}
}