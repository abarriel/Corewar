/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifcolors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:27:17 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/20 00:50:05 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			chose_color_case_2(t_env *p, int i3)
{
	if (p->core->mem_c[i3] == 0x30)
		ft_modif_color(219, 152, 52, p);
	else if (p->core->mem_c[i3] == 0x31)
		ft_modif_color(209, 142, 42, p);
	else if (p->core->mem_c[i3] == 0x32)
		ft_modif_color(199, 132, 32, p);
	else if (p->core->mem_c[i3] == 0x34)
		ft_modif_color(189, 122, 22, p);
	else if (p->core->mem_c[i3] == 0x40)
		ft_modif_color(15, 196, 241, p);
	else if (p->core->mem_c[i3] == 0x41)
		ft_modif_color(15, 186, 231, p);
	else if (p->core->mem_c[i3] == 0x42)
		ft_modif_color(15, 176, 221, p);
	else if (p->core->mem_c[i3] == 0x44)
		ft_modif_color(15, 166, 211, p);
}

void			chose_color_case(t_env *p, int i3)
{
	ft_modif_color(35, 35, 35, p);
	if (p->core->mem_c[i3] > 0x2F)
		chose_color_case_2(p, i3);
	else if (p->core->mem_c[i3] == 0x20)
		ft_modif_color(113, 204, 46, p);
	else if (p->core->mem_c[i3] == 0x21)
		ft_modif_color(103, 194, 36, p);
	else if (p->core->mem_c[i3] == 0x22)
		ft_modif_color(93, 184, 26, p);
	else if (p->core->mem_c[i3] == 0x24)
		ft_modif_color(83, 174, 16, p);
	else if (p->core->mem_c[i3] == 0x10)
		ft_modif_color(60, 76, 231, p);
	else if (p->core->mem_c[i3] == 0x11)
		ft_modif_color(50, 66, 221, p);
	else if (p->core->mem_c[i3] == 0x12)
		ft_modif_color(40, 56, 211, p);
	else if (p->core->mem_c[i3] == 0x14)
		ft_modif_color(30, 46, 201, p);
}

void			modif_color_for_player(t_env *p, int i)
{
	if (i == 0)
		ft_modif_color(60, 76, 231, p);
	if (i == 50)
		ft_modif_color(113, 204, 46, p);
	if (i == 100)
		ft_modif_color(219, 152, 52, p);
	if (i == 150)
		ft_modif_color(15, 196, 241, p);
}
