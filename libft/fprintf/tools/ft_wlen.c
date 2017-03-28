/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 21:07:03 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/09 01:41:17 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_cstrwlen_(t_conv *c, t_flag *f, int size)
{
	if (size <= 16)
	{
		if (c->i + 3 > f->pre_len && (f->pre_len != 0 || f->preci == 1))
			return (-1);
		c->i += 3;
	}
	else
	{
		if (c->i + 4 > f->pre_len && (f->pre_len != 0 || f->preci == 1))
			return (-1);
		c->i += 4;
	}
	return (0);
}

int		ft_cstrwlen(t_conv *c, t_flag *f)
{
	int				size;

	size = count_bits(*c->wtmp);
	if (size <= 7)
	{
		if (c->i + 1 > f->pre_len && (f->pre_len != 0 || f->preci == 1))
			return (-1);
		c->i++;
		return (0);
	}
	else if (size <= 11)
	{
		if (c->i + 2 > f->pre_len && (f->pre_len != 0 || f->preci == 1))
			return (-1);
		c->i += 2;
	}
	else if ((ft_cstrwlen_(c, f, size)) == -1)
		return (-1);
	return (0);
}

size_t	ft_strnwlen(t_conv *c, t_flag *f)
{
	c->i = 0;
	c->wtmp = c->wst;
	while (c->wtmp && *c->wtmp)
	{
		if (ft_cstrwlen(c, f) == -1)
			return (c->i);
		c->wtmp++;
	}
	return (c->i);
}
