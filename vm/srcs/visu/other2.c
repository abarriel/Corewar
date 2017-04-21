/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:14:47 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/23 16:15:52 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			print_nb_live2(t_env *p, int i, char *str)
{
	if (i == 0)
		mlx_string_put(p->mlx, p->win, 1350, 750, 0x0e74c3c, str);
	if (i == 1)
		mlx_string_put(p->mlx, p->win, 1350, 950, 0x2ecc71, str);
	if (i == 2)
		mlx_string_put(p->mlx, p->win, 1700, 750, 0x03498db, str);
	if (i == 3)
		mlx_string_put(p->mlx, p->win, 1700, 950, 0x0f1c40f, str);
	free(str);
}

void			print_nb_live(t_env *p)
{
	char		*str;
	t_player	*tmp;
	int			i;

	i = 0;
	tmp = p->core->player;
	while (i < 4)
	{
		if (p->core->player)
		{
			str = ft_itoa(p->core->player->nb_live);
			print_nb_live2(p, i, str);
			p->core->player = p->core->player->next;
		}
		i++;
	}
	p->core->player = tmp;
}

void			check_button_hit2(int button, int x, int y, t_env *p)
{
	if (button == 1)
	{
		if ((x <= (HEIGHT) + 405) && (x >= (HEIGHT) + 335) && (y <=
			(HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn3_s = 80;
			p->but->btn3_px = (HEIGHT) + 330;
			p->but->btn3_py = (HEIGHT) - 125;
			if (p->core->cycle_sec - 5 > 0)
				p->core->cycle_sec -= 5;
		}
		if ((x <= (HEIGHT) + 565) && (x >= (HEIGHT) + 485) && (y <=
			(HEIGHT) - 50) && (y >= (HEIGHT) - 120))
		{
			p->but->btn4_s = 80;
			p->but->btn4_px = (HEIGHT) + 480;
			p->but->btn4_py = (HEIGHT) - 125;
			if ((p->core->cycle_sec + 5) <= 2005)
				p->core->cycle_sec += 5;
		}
	}
}

void			print_player_name2(t_env *p, int i, char *str)
{
	if (i == 0)
		mlx_string_put(p->mlx, p->win, 1300, 700, 0x0e74c3c, str);
	if (i == 1)
		mlx_string_put(p->mlx, p->win, 1300, 900, 0x2ecc71, str);
	if (i == 2)
		mlx_string_put(p->mlx, p->win, 1650, 700, 0x03498db, str);
	if (i == 3)
		mlx_string_put(p->mlx, p->win, 1650, 900, 0x0f1c40f, str);
}
