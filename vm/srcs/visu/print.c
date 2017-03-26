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

void		print_players(t_env *p)
{
	char *str;
	
	str = "P1";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 270, 0x0e74c3c, str);
	str = "P2";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 320, 0x02ecc71, str);
	str = "P3";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 370, 0x03498db, str);
	str = "P4";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 420, 0x0f1c40f, str);
}

void		print_info(t_env *p)
{

	char *str;
	
	str = "CYCLES: ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 520, 0x0e74c3c, str);
	str = ft_itoa(p->cycle_count);
	mlx_string_put(p->mlx, p->win, (HEIGHT + 170), 520, 0x0e74c3c, str);
	str = "PROCESSES: ";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 50), 580, 0x0e74c3c, str);
	str = "0";
	mlx_string_put(p->mlx, p->win, (HEIGHT + 170), 580, 0x0e74c3c, str);
}

void		print_text(t_env *p)
{
	print_players(p);
	print_info(p);
}