/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 01:54:33 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/24 01:54:36 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			print_nb_live(t_env *p)
{
	char		*str;
	t_player	*tmp;
	int			i;

	i = -1;
	tmp = p->core->player;
	str = ft_itoa(p->core->player->nb_live);
	while (++i < 4)
	{
		if (i == 0 || i == 1)
			mlx_string_put(p->mlx, p->win, 1350, 750 + (200 * i), 0x0e74c3c,
				str);
		if (i == 2)
			mlx_string_put(p->mlx, p->win, 1700, 750, 0x03498db, str);
		if (i == 3)
			mlx_string_put(p->mlx, p->win, 1700, 950, 0x0f1c40f, str);
		if (p->core->player->next == NULL)
			str = "";
		else
		{
			p->core->player = p->core->player->next;
			str = ft_itoa(p->core->player->nb_live);
		}
	}
	p->core->player = tmp;
}

void			print_player_name(t_env *p)
{
	char		*str;
	t_player	*tmp;
	int			i;

	i = -1;
	tmp = p->core->player;
	str = tmp->name;
	while (++i < 4)
	{
		if (i == 0 || i == 1)
			mlx_string_put(p->mlx, p->win, 1300, 700 + (100 * i), 0x0e74c3c,
				str);
		if (i == 2)
			mlx_string_put(p->mlx, p->win, 1650, 700, 0x03498db, str);
		if (i == 3)
			mlx_string_put(p->mlx, p->win, 1650, 900, 0x0f1c40f, str);
		if (p->core->player->next == NULL)
			str = "N/A";
		else
		{
			p->core->player = p->core->player->next;
			str = p->core->player->name;
		}
	}
	p->core->player = tmp;
}

void			print_players(t_env *p)
{
	char		*str;
	t_player	*tmp;
	int			i;

	i = -1;
	tmp = p->core->player;
	str = ft_strncpy(str, tmp->name, 4);
	while (++i < 4)
	{
		if (i == 0)
			mlx_string_put(p->mlx, p->win, (HEIGHT + 40), 270 + (50 * i),
				0x0e74c3c, str);
		if (i == 1)
			mlx_string_put(p->mlx, p->win, (HEIGHT + 40), 270 + (50 * i),
				0x02ecc71, str);
		if (i == 2)
			mlx_string_put(p->mlx, p->win, (HEIGHT + 40), 270 + (50 * i),
				0x03498db, str);
		if (i == 3)
			mlx_string_put(p->mlx, p->win, (HEIGHT + 40), 270 + (50 * i),
				0x0f1c40f, str);
		if (p->core->player->next == NULL)
			str = "N/A";
		else
		{
			p->core->player = p->core->player->next;
			str = ft_strncpy(str, p->core->player->name, 4);
		}
	}
	p->core->player = tmp;
}

void			print_info(t_env *p)
{
	char		*str;

	str = "CYCLES       : ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 520, 0x0FFFFFF, str);
	str = ft_itoa(p->core->cycle);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 200), 520, 0x0e74c3c, str);
	str = "LAST CHECK   : ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 570, 0x0FFFFFF, str);
	str = ft_itoa(p->core->last_check);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 200), 570, 0x0e74c3c, str);
	str = "CYCLE / SEC  : ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 620, 0x0FFFFFF, str);
	str = ft_itoa(p->core->cycle_sec);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 200), 620, 0x0e74c3c, str);
	str = "CYCLE DELTA  : ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 380), 520, 0x0FFFFFF, str);
	str = ft_itoa(CYCLE_DELTA);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 530), 520, 0x0e74c3c, str);
	str = "CYCLE TO DIE : ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 380), 570, 0x0FFFFFF, str);
	str = ft_itoa(p->core->die_cycle);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 530), 570, 0x0e74c3c, str);
}

void			print_text(t_env *p)
{
	print_players(p);
	print_player_name(p);
	print_info(p);
	print_nb_live(p);
}
