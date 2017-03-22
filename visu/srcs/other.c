/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:42:27 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/23 15:48:03 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualisateur.h"

int			ft_is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

void		ft_modif_color(int r, int v, int b, t_env *p)
{
	p->r = r;
	p->v = v;
	p->b = b;
}