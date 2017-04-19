/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 22:53:20 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 22:53:25 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_info_map(void)
{
	ft_putstr("Map: \n");
	ft_putstr("       00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 ");
	ft_putstr("18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38");
	ft_putstr(" 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55");
	ft_putstr(" 56 57 58 59 60 61 62 63\n");
	ft_putstr("       -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --");
	ft_putstr(" -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --");
	ft_putstr(" -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --");
	ft_putstr(" -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");
}

void	print_color_map(char *color, unsigned char *map, int i)
{
	if (color[i] == 0x10)
		ft_printf("{1}%.2x", map[i]);
	else if (color[i] == 0x20)
		ft_printf("{2}%.2x", map[i]);
	else if (color[i] == 0x21)
		ft_printf("\033[4;1;32m%.2x", map[i]);
	else if (color[i] == 0x30)
		ft_printf("{3}%.2x", map[i]);
	else if (color[i] == 0x31)
		ft_printf("\033[4;1;33m%.2x", map[i]);
	else if (color[i] == 0x40)
		ft_printf("{4}%.2x", map[i]);
	else if (color[i] == 0x41)
		ft_printf("\033[4;1;34m%.2x", map[i]);
	else if (color[i] == 0x11)
		ft_printf("\033[4;1;31m%.2x", map[i]);
	else if (color[i] == 0x12)
		ft_printf("{8}%.2x", map[i]);
	else if (color[i] == 0x22)
		ft_printf("{9}%.2x", map[i]);
	else
		ft_printf("%.2x", map[i]);
	ft_printf("\033[0m ");
}

void	print_map(t_core *core)
{
	unsigned char	*map;
	char			*color;
	int				i;
	int				j;

	i = 0;
	j = 0;
	map = core->mem;
	color = core->mem_c;
	print_info_map();
	while (i < MEM_SIZE)
	{
		ft_printf("%4d | ", i);
		while (j < 64)
		{
			print_color_map(color, map, i);
			j++;
			i++;
		}
		j = 0;
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_player(t_core *core)
{
	size_t		i;
	t_player	*tmp;

	tmp = core->player;
	while (tmp)
	{
		i = 0;
		ft_printf("\nName: [%s]\n", tmp->name);
		ft_printf("Magic: [%x]\n", tmp->magic);
		ft_printf("Comment: [%s]\n", tmp->comment);
		ft_printf("prog_size: [%d]\n", tmp->weight);
		ft_printf("ID: [%02x%02x%02x%02x]\n", tmp->id[0],
		tmp->id[1], tmp->id[2], tmp->id[3]);
		ft_printf("last_live: [%d]\n", tmp->last_live);
		ft_printf("nb_live: [%d]\n", tmp->nb_live);
		ft_printf("Programme: [");
		while (i < tmp->weight)
		{
			ft_printf("%.2x", tmp->prog[i]);
			i++;
		}
		ft_printf("]\n");
		tmp = tmp->next;
	}
}

void	print_res(t_core *core)
{
	t_player	*player;
	t_player	*winner;

	player = core->player;
	winner = core->player;
	while (player)
	{
		if (player->last_live > winner->last_live)
			winner = player;
		player = player->next;
	}
	print_winner(winner);
}
