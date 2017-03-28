/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 22:15:21 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/08 22:16:16 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_c(t_stock *s, t_flag *f)
{
	t_conv			*c;

	c = start_conv();
	f->slen = 1;
	f->aq = 0;
	if (f->l == 1)
		f->conv = 'C';
	if (f->conv == 'C')
		c->wch = (wchar_t)va_arg(s->aps, int);
	else
		c->wch = (char)va_arg(s->aps, int);
	print_c(f, c);
}

void	conv_s(t_stock *s, t_flag *f)
{
	t_conv			*c;

	c = start_conv();
	if (f->sta < 0 && f->preci == 1)
		f->pre_len = f->sta * -1;
	if (f->conv == '%')
	{
		c->s = "%";
		return (print_s(f, c));
	}
	if (f->l == 1)
		f->conv = 'S';
	if (f->conv == 'S')
	{
		if ((c->wst = va_arg(s->aps, wchar_t*)) == 0)
			c->wst = L"(null)";
	}
	else
	{
		if ((c->s = va_arg(s->aps, char *)) == 0)
			c->s = "(null)";
	}
	print_s(f, c);
}
