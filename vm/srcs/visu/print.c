/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 01:54:33 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/20 00:35:43 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			print_player_name(t_env *p)
{
	char		*str;
	t_player	*tmp;
	int			i;

	i = -1;
	tmp = p->core->player;
	str = tmp->name;
	str[5] = '\0';
	while (++i < 4)
	{
		if (i >= 0 && i <= 3)
			print_player_name2(p, i, str);
		if (p->core->player->next == NULL)
			str = "N/A";
		else
		{
			p->core->player = p->core->player->next;
			str = p->core->player->name;
			str[5] = '\0';
		}
	}
	p->core->player = tmp;
}

void			print_players_extented(t_env *p, int i, char *str)
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
}

void			print_players(t_env *p)
{
	char		*str;
	t_player	*tmp;
	int			i;

	i = -1;
	tmp = p->core->player;
	str = tmp->name;
	str[12] = '\0';
	while (++i < 4)
	{
		if (i >= 0 && i <= 3)
			print_players_extented(p, i, str);
		if (p->core->player->next == NULL)
			str = "N/A";
		else
		{
			p->core->player = p->core->player->next;
			str = p->core->player->name;
			str[12] = '\0';
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
	free(str);
	str = "LAST CHECK   : ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 570, 0x0FFFFFF, str);
	str = ft_itoa(p->core->last_check);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 200), 570, 0x0e74c3c, str);
	free(str);
	print_info2(p, str);
	if (p->core->die_cycle > 0)
		str = ft_itoa(p->core->die_cycle);
	else
		str = ft_itoa(0);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 530), 570, 0x0e74c3c, str);
	free(str);
}

void			print_text(t_env *p)
{
	print_players(p);
	print_player_name(p);
	print_info(p);
	print_nb_live(p);
}
