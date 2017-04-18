/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:52:41 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/18 11:52:42 by lcharvol         ###   ########.fr       */
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
		ft_modif_color(20, 20, 20, p);
		ft_draw_rectangle((HEIGHT + 100), 270 + i, p);
		modif_color_for_player(p, i);
		p->l = (i2[i / 50]);
		ft_draw_rectangle((HEIGHT + 100), 270 + i, p);
		p->core->player = p->core->player->next;
		i += 50;
	}
	p->core->player = player;
}
