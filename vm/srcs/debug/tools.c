/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 05:45:22 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/20 23:13:22 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_usage(void)
{
	ft_putstr("Usage: ./corewar [-dump N -n N -f -debug N]");
	ft_putstr("<champion1.cor> <...>\n\n");
	ft_putstr("    -dump nbr_cycles : Au bout de nbr_cycles cycles ");
	ft_putstr("d’exécution, dump la mémoire sur la sortie standard,");
	ft_putstr(" puis quitte la partie.\n");
	ft_putstr("    -debug           : Debug avec plusieurs option\n");
	ft_putstr("    -n numer         : Fixe le numéro du prochain joueur.\n");
	ft_putstr("    -f               : interface graphique mlx\n");
	exit(0);
}

void	print_line_norm(void)
{
	ft_putstr("Usage :\n	map  : print map\n ");
	ft_putstr("run -> value : run value cycle\n");
	ft_putstr("	reg  : print registers\n	core : ");
	ft_putstr("print information about core programme\n	exit : exit\n");
}

void	debug_run_(t_core *core, char *line)
{
	get_next_line(0, &line);
	if (ft_strcmp(line, "exit") == 0)
		exit(0);
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
		print_line_norm();
	free(line);
}

void	debug_run(t_core *core)
{
	char	*line;

	line = NULL;
	ft_putstr("Usage :\n	map  : print map\n ");
	ft_putstr("run -> value : run value cycle\n");
	ft_putstr("	reg  : print registers\n	core : ");
	ft_putstr("print information about core programme\n	exit : exit\n");
	while (1)
		debug_run_(core, line);
}
