/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_map_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 22:54:20 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/20 00:04:53 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_reg(t_core *core)
{
	int			i;
	t_process	*tmp;
	int			j;

	j = 0;
	tmp = core->process;
	while (tmp)
	{
		j++;
		i = 0;
		ft_printf("\nName: [%s]\n", tmp->player->name);
		ft_printf("ID: [%02x%02x%02x%02x]\n", tmp->player->id[0],
		tmp->player->id[1], tmp->player->id[2], tmp->player->id[3]);
		ft_printf("pc: %d\n", tmp->pc);
		ft_printf("carry: %d\n", tmp->carry);
		ft_printf("registre: \n");
		while (i < REG_NUMBER)
		{
			ft_printf("%2d : %.2x%.2x%.2x%.2x\n", i + 1, tmp->reg[i][0],
			tmp->reg[i][1], tmp->reg[i][2], tmp->reg[i][3]);
			i++;
		}
		tmp = tmp->next;
	}
	ft_printf("\nnb_process : %d\n", j);
}

void	print_color(t_core *core)
{
	char	*map;
	char			*color;
	int				i;
	int				j;

	i = 0;
	j = 0;
	map = core->mem_c;
	color = core->mem_c;
	print_info_map();
	while (i < MEM_SIZE)
	{
		ft_printf("%4d | ", i);
		while (j < 64)
		{
			print_color_map(color, (unsigned char*)map, i);
			j++;
			i++;
		}
		j = 0;
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_data(t_core *core)
{
	ft_putstr("cycle        : ");
	ft_printf("%7d\n", core->cycle);
	ft_printf("last check   : %7d\n", core->last_check);
	if (core->die_cycle > 0)
		ft_printf("cycle to die : %7d\n", core->die_cycle);
	else
		ft_putstr("cycle to die :       0\n");
}
