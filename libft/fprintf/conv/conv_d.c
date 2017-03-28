/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 23:53:25 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/08 22:17:21 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_d(t_stock *s, t_flag *f)
{
	t_conv			*c;

	c = start_conv();
	if (f->ll == 1)
		c->i = va_arg(s->aps, long long int);
	else if (f->l == 1 || f->conv == 'D')
		c->i = va_arg(s->aps, long int);
	else if (f->h == 1 && f->conv != 'D')
		c->i = (short)va_arg(s->aps, int);
	else if (f->hh == 1)
		c->i = (char)va_arg(s->aps, int);
	else
		c->i = va_arg(s->aps, int);
	c->tmp = ft_litoa(c->i);
	c->s = c->tmp;
	mod_d(f, c);
}

void	conv_u(t_stock *s, t_flag *f)
{
	t_conv			*c;

	c = start_conv();
	if (f->ll == 1)
		c->i = va_arg(s->aps, unsigned long long int);
	else if (f->hh == 1 && f->conv != 'U')
		c->i = (unsigned char)va_arg(s->aps, unsigned int);
	else if (f->l == 1 || (f->conv == 'U'))
		c->i = va_arg(s->aps, unsigned long int);
	else if (f->h == 1 && f->conv == 'u')
		c->i = (unsigned short)va_arg(s->aps, int);
	else
		c->i = va_arg(s->aps, unsigned int);
	c->tmp = ft_luitoa(c->i);
	c->s = c->tmp;
	mod_d(f, c);
}
