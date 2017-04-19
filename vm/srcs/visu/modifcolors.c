/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifcolors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:27:17 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/19 23:07:57 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			chose_color_case(t_env *p, int i3)
{
	ft_modif_color(35, 35, 35, p);
	if (p->core->mem_c[i3] == 0x30)
		ft_modif_color(187, 3, 3, p);
	else if (p->core->mem_c[i3] == 0x31)
		ft_modif_color(249, 4, 4, p);
	else if (p->core->mem_c[i3] == 0x32)
		ft_modif_color(124, 2, 2, p);
	else if (p->core->mem_c[i3] == 0x34)
		ft_modif_color(253, 76, 76, p);
	else if (p->core->mem_c[i3] == 0x20)
		ft_modif_color(3, 187, 3, p);
	else if (p->core->mem_c[i3] == 0x21)
		ft_modif_color(4, 249, 4, p);
	else if (p->core->mem_c[i3] == 0x22)
		ft_modif_color(2, 124, 2, p);
	else if (p->core->mem_c[i3] == 0x24)
		ft_modif_color(76, 253, 76, p);
	else if (p->core->mem_c[i3] == 0x10)
		ft_modif_color(3, 3, 187, p);
	else if (p->core->mem_c[i3] == 0x11)
		ft_modif_color(4, 4, 249, p);
	else if (p->core->mem_c[i3] == 0x12)
		ft_modif_color(2, 2, 124, p);
	else if (p->core->mem_c[i3] == 0x14)
		ft_modif_color(76, 76, 253, p);
	else if (p->core->mem_c[i3] == 0x40)
		ft_modif_color(0, 223, 223, p);
	else if (p->core->mem_c[i3] == 0x41)
		ft_modif_color(0, 255, 255, p);
	else if (p->core->mem_c[i3] == 0x42)
		ft_modif_color(0, 191, 191, p);
	else if (p->core->mem_c[i3] == 0x44)
		ft_modif_color(139, 253, 253, p);
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
