/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:29:02 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/18 23:47:11 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
void print_map(t_core *core)
{
	unsigned char *map = core->mem;
	char *color = core->mem_c;
	int magic = 4;
	int i = 0;
	int j = 0;

	ft_printf("Map: \n");
	while (i < ( MEM_SIZE / 6) )
	{
		while (j < 64)
		{
			//if(i == core->process->pc)
			//	ft_putstr("\033[4m");
			if (color[i] >= 1)
			{
				//ft_printf("{%d}[%d]",i, core->process->pc);
				if (i == core->process->pc)
				{
					// BLINK
					magic = 1;
					// Bold
					//magic = 1;
					ft_printf("\033[%d;32m%.2x", magic, map[i]);
					//ft_printf("\033[%d;32m%.2x", magic, map[i]);

				}
				else
					ft_printf("{1}%.2x", map[i]);
			}
		*else if (color[i] == 2)
				ft_printf("{2}%.2x", map[i]);
			else if (color[i] == 20)
				ft_printf("\033[4;32m%.2x", map[i]);
			else if (color[i] == 3)
				ft_printf("{3}%.2x", map[i]);
			else if (color[i] == 30)
				ft_printf("\033[4;33m%.2x", map[i]);
			else if (color[i] == 4)
				ft_printf("{4}%.2x", map[i]);
			else if (color[i] == 40)
				ft_printf("\033[4;34m%.2x", map[i]);
			else if (color[i] == 10)
			{
				ft_printf("\033[31m%.2x", map[i]);
			}
			else
				ft_printf("%.2x", map[i]);
			j++;
			//ft_putstr(RESET);
			i++;
		}
		j = 0;
		ft_printf("\n");
	}
	ft_printf("\n");
}
*/
void print_map(t_core *core)
{
	unsigned char *map = core->mem;
	char *color = core->mem_c;
	int i = 0;
	int j = 0;
	int magic = 0;

	ft_printf("Map: \n");
	ft_printf("       00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63\n");
	ft_printf("       -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

	while (i < MEM_SIZE)
	{
		ft_printf("%4d | ", i);
		while (j < 64)
		{
			if (color[i] == 1)
				ft_printf("{1}%.2x", map[i]);
			else if (color[i] == 2)
				ft_printf("{2}%.2x", map[i]);
			else if (color[i] == 20)
				ft_printf("\033[4;32m%.2x", map[i]);
			else if (color[i] == 3)
				ft_printf("{3}%.2x", map[i]);
			else if (color[i] == 30)
				ft_printf("\033[4;33m%.2x", map[i]);
			else if (color[i] == 4)
				ft_printf("{4}%.2x", map[i]);
			else if (color[i] == 40)
				ft_printf("\033[4;34m%.2x", map[i]);
			else if (color[i] == 10)
				ft_printf("\033[4;1;31m%.2x", map[i]);
			else if (color[i] == 11)
				ft_printf("{8}%.2x", map[i]);
			else
				ft_printf("%.2x", map[i]);
			ft_printf("\033[0m ");
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
	int i;
	t_player *tmp;

	tmp = core->player;
	while (tmp)
	{
		i = 0;
		ft_printf("\nName: [%s]\n", tmp->name);
		ft_printf("Magic: [%x]\n", tmp->magic);
		ft_printf("Comment: [%s]\n", tmp->comment);
		ft_printf("prog_size: [%d]\n", tmp->weight);
		ft_printf("ID: [%02x%02x%02x%02x]\n", tmp->id[0], tmp->id[1], tmp->id[2], tmp->id[3]);
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

void print_res(t_core *core)
{
	t_player *player;
	t_player *winner;

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

void print_reg(t_core *core)
{
	int i;
	t_process *tmp;

	tmp = core->process;
	while (tmp)
	{
		i = 0;
		ft_printf("\nName: [%s]\n", tmp->player->name);
		ft_printf("ID: [%02x%02x%02x%02x]\n", tmp->player->id[0], tmp->player->id[1], tmp->player->id[2], tmp->player->id[3]);
		ft_printf("pc: %d\n", tmp->pc);
		ft_printf("registre: \n");
		while (i < REG_NUMBER)
		{
			ft_printf("%2d : %.2x%.2x%.2x%.2x\n", i + 1, tmp->reg[i][0], tmp->reg[i][1], tmp->reg[i][2], tmp->reg[i][3]);
			i++;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void print_color(t_core *core)
{
	char *map = core->mem_c;
	char *color = core->mem_c;
	int i = 0;
	int j = 0;
	int magic = 0;

	ft_printf("Map: \n");
	ft_printf("       00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63\n");
	ft_printf("       -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");

	while (i < MEM_SIZE)
	{
		ft_printf("%4d | ", i);
		while (j < 64)
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
			j++;
			i++;
		}
		j = 0;
		ft_printf("\n");
	}
	ft_printf("\n");
}

void print_data(t_core *core)
{
	ft_printf("cycle        : %7d\nlast check   : %7d\ncycle to die : %7d\n", core->cycle, core->last_check, core->die_cycle);
}

void debug_run(t_core *core)
{
	char *line;

	ft_printf("%s\n", "Usage :\n	map  : print map\n	run -> value : run value cycle\n	reg  : print registers\n	core : print information about core programme\n	exit : exit");
	while (1)
	{
		get_next_line(0, &line);
		if (ft_strcmp(line, "exit") == 0)
			exit (0);
		else if (ft_strcmp(line, "run") == 0)
		{
			free(line);
			get_next_line(0, &line);
			core->dump = ft_atoi(line);
			if (core->dump != 0)
				run(core);
			else
				ft_printf("%s\n", "Incorect value");
		}
		else if (ft_strcmp(line, "map") == 0)
			print_map(core);
		else if (ft_strcmp(line, "color") == 0)
			print_color(core);
		else if (ft_strcmp(line, "core") == 0)
			print_data(core);
		else if (ft_strcmp(line, "reg") == 0)
			print_reg(core);
		else
			ft_printf("%s\n", "Usage :\n	map : print map\n	run -> value : run value cycle\n	reg : print registers\n	core : print information about core programme\n	exit : exit");
		free(line);
	}
}

int		main(int argc, char **argv)
{
	t_core	*core;

	core = new_core();
	parcing(argc, argv, core);
	print_player(core);
	init_core(core);
	// print_map(core);
	if (core->visu == 0)
	{
		if (core->debug == 0)
  		run(core);
		else
			debug_run(core);
	}
	else
		go_visu(core);
	print_res(core);
	return (0);
}
