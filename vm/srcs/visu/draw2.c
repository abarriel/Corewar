/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:52:41 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/20 00:27:57 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			print_info2(t_env *p, char *str)
{
	str = "CYCLE / SEC  : ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 620, 0x0FFFFFF, str);
	str = ft_itoa(p->core->cycle_sec);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 200), 620, 0x0e74c3c, str);
	free(str);
	str = "CYCLE DELTA  : ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 380), 520, 0x0FFFFFF, str);
	str = ft_itoa(CYCLE_DELTA);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 530), 520, 0x0e74c3c, str);
	free(str);
	str = "CYCLE TO DIE : ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 380), 570, 0x0FFFFFF, str);
	if (p->melenchon == 1)
	{
		str = "Partie terminée!";
		mlx_string_put(p->mlx, p->win, (HEIGHT + 380), 620, 0x0FFFFFF, str);
	}
}

void			ft_draw_rectangle(int start_x, int start_y, t_env *p)
{
	int			i;
	int			i2;
	int			t;

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

void			ft_draw_square(int start_x, int start_y, int size, t_env *p)
{
	int			i;
	int			i2;
	int			tmp;

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
			if (p->core->mem_c[i3] == 0x11 || p->core->mem_c[i3] == 0x21 ||
				p->core->mem_c[i3] == 0x31 || p->core->mem_c[i3] == 0x41)
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
			(i2[i / 50]) = (WIDTH - (HEIGHT) - 150);
		else if (p->core->player->nb_live == 0 &&
			(i2[i / 50]) > 0 && p->pause == 0)
			(i2[i / 50])--;
		p->l = WIDTH - (HEIGHT) - 150;
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
