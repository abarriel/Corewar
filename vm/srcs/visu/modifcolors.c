/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:27:17 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/18 11:27:18 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			chose_color_case(t_env *p, int i3)
{
	ft_modif_color(35, 35, 35, p);
	if (p->core->mem_c[i3] == 1 || p->core->mem_c[i3] == 10)
		ft_modif_color(60, 76, 231, p);
	else if (p->core->mem_c[i3] == 11)
		ft_modif_color(50, 66, 195, p);
	else if (p->core->mem_c[i3] == 2 || p->core->mem_c[i3] == 20)
		ft_modif_color(113, 204, 46, p);
	else if (p->core->mem_c[i3] == 21)
		ft_modif_color(83, 164, 36, p);
	else if (p->core->mem_c[i3] == 3 || p->core->mem_c[i3] == 30)
		ft_modif_color(219, 152, 52, p);
	else if (p->core->mem_c[i3] == 31)
		ft_modif_color(189, 122, 42, p);
	else if (p->core->mem_c[i3] == 4 || p->core->mem_c[i3] == 40)
		ft_modif_color(15, 193, 241, p);
	else if (p->core->mem_c[i3] == 41)
		ft_modif_color(15, 193, 241, p);
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
