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
