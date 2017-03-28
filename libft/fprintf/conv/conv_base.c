/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 22:17:44 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/09 07:56:41 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_nbase(t_conv *c, t_flag *f, char i, char cap_x)
{
	if (f->h == 1)
		c->i = (unsigned short)c->i;
	if (f->l == 1 || f->ll == 1 || f->conv == 'O' || f->conv == 'B')
		c->tmp = ft_litoa_base_neg(c->i, i, cap_x);
	else
		c->tmp = ft_itoa_base_neg(c->i, i, cap_x);
	c->s = c->tmp;
}

void	conv_base(t_stock *s, t_flag *f, char i)
{
	t_conv	*c;
	char	cap_x;

	c = start_conv();
	cap_x = (f->conv == 'X') ? 1 : 0;
	if (f->hh == 1 && f->conv != 'O' && f->conv != 'B')
		c->i = (unsigned char)va_arg(s->aps, int);
	else if (f->ll == 1)
		c->i = va_arg(s->aps, long long int);
	else if (f->l == 1 || f->conv == 'O' || f->conv == 'B')
		c->i = va_arg(s->aps, long int);
	else if (f->h == 1)
		c->i = (short)va_arg(s->aps, int);
	else
		c->i = va_arg(s->aps, int);
	if (c->i < 0)
		conv_nbase(c, f, i, cap_x);
	else
	{
		c->tmp = ft_itoa_base(c->i, i, cap_x);
		c->s = c->tmp;
		f->plus = 1;
	}
	mod_base(f, c);
}
