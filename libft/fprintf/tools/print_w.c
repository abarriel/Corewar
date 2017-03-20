/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_w.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 21:09:09 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/09 00:30:03 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnwchar_(t_conv *c, t_flag *f, size_t v, int size)
{
	if (size <= 16)
	{
		if ((c->i += 3) > f->pre_len && (f->pre_len != 0 || f->preci == 1))
			return (-1);
		ft_putchar(((v >> 12) & 15) | 224);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	else
	{
		if ((c->i += 4) > f->pre_len && (f->pre_len != 0 || f->preci == 1))
			return (-1);
		ft_putchar(((v >> 18) & 7) | 240);
		ft_putchar(((v >> 12) & 63) | 128);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	ft_putchar((v & 63) | 128);
	return (0);
}

int		ft_putnwchar(t_conv *c, t_flag *f)
{
	unsigned int	v;
	int				size;

	v = (unsigned int)*c->wst;
	size = count_bits(*c->wst);
	if (size <= 7)
	{
		if (++c->i > f->pre_len && (f->pre_len != 0 || f->preci == 1))
			return (-1);
		ft_putchar(*c->wst);
		return (0);
	}
	else if (size <= 11)
	{
		if ((c->i += 2) > f->pre_len && (f->pre_len != 0 || f->preci == 1))
			return (-1);
		ft_putchar(((v >> 6) & 31) | 192);
		ft_putchar((v & 63) | 128);
	}
	else
		ft_putnwchar_(c, f, v, size);
	return (0);
}

void	ft_putnwstr(t_conv *c, t_flag *f)
{
	c->i = 0;
	while (c->wst && *c->wst)
	{
		if (ft_putnwchar(c, f) == -1)
			return ;
		c->wst++;
	}
}
