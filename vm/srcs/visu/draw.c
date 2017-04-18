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

#include "vm.h"

void			ft_draw_map(t_env *p)
{
	int			i;
	int			i2;
	int			i3;
	int			i4;
	float		size;

	i = -1;
	i3 = 0;
	size = (((HEIGHT - 20)) / (MAP_SIZE_Y)) - 1;
	while (++i < MAP_SIZE_Y)
	{
		i2 = 0;
		while (i2 < MAP_SIZE_X)
		{
			i4 = 0;
			if (p->core->mem_c[i3] == 10 || p->core->mem_c[i3] == 20 ||
				p->core->mem_c[i3] == 30 || p->core->mem_c[i3] == 40)
				i4 = 2;
			chose_color_case(p, i3);
			ft_draw_square((((i2) * (size + 1)) + (i4 / 2)) + 18, ((i) *
				(size + 1)) + 18 + (i4 / 2), size - i4, p);
			i2++;
			i3++;
		}
	}
}

void			ft_draw_score(t_env *p)
{
	t_player	*player;
	int			i;
	static int	i2[4] = {0, 0, 0, 0};

	player = p->core->player;
	i = 0;
	while (p->core->player)
	{
		if (p->core->player->nb_live > 0)
		{
			if ((i2[i / 50]) + 1 <= (WIDTH - (HEIGHT) - 150))
				(i2[i / 50]) += 5;
		}
		else if (p->core->player->nb_live == 0 && (i2[i / 50]) > 0)
			(i2[i / 50])--;
		p->l = WIDTH - (HEIGHT) - 150;
		p->h = 20;
		ft_draw_rectangle((HEIGHT + 100), 270 + i, p);
		modif_color_for_player(p, i);
		p->l = (i2[i / 50]);
		ft_draw_rectangle((HEIGHT + 100), 270 + i, p);
		p->core->player = p->core->player->next;
		i += 50;
	}
	p->core->player = player;
}

void			ft_draw_arena(t_env *p)
{
	ft_modif_color(15, 15, 15, p);
	ft_draw_square(10, 10, (HEIGHT - 20), p);
	ft_draw_map(p);
}

void			ft_draw_menu(t_env *p)
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

void			ft_draw_background(t_env *p)
{
	int			i;

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
