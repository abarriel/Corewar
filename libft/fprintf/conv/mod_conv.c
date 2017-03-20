/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 23:44:45 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/08 22:22:13 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_base(t_flag *f, t_conv *c)
{
	if ((ft_strcmp("0", c->s)) == 0)
	{
		if (f->preci == 1 || (if_so(f->conv, "oOBb") && f->has == 1))
			c->s = "";
		if (f->has == 1 && if_so(f->conv, "xX") && f->conv != 'p')
			f->has = 0;
	}
	if (c->i < 0 && !if_so(f->conv, "uUpXxoOBb"))
	{
		f->neg = 1;
		c->s = ft_strsub(c->s, 1, ft_strlen(c->s) - 1);
	}
	f->slen = ft_strlen(c->s);
	if (f->has == 1 && f->pre_len <= 0)
	{
		if (if_so(f->conv, "oObB"))
			f->slen += 1;
		if (if_so(f->conv, "xX"))
			f->slen += 2;
	}
	if (f->pre_len > 0 && (f->neg == 1 || (f->signe == 1 && f->plus == 1)))
		f->slen--;
	print_base(f, c);
}

void	mod_d(t_flag *f, t_conv *c)
{
	if ((ft_strcmp("0", c->s)) == 0 && f->preci == 1)
		c->s = "";
	if (c->i >= 0)
		f->plus = 1;
	else if (!if_so(f->conv, "uU"))
	{
		f->neg = 1;
		c->s = ft_strsub(c->s, 1, ft_strlen(c->s) - 1);
	}
	f->slen = ft_strlen(c->s);
	if (f->pre_len > 0 && (f->neg == 1 || (f->signe == 1 && f->plus == 1)))
		f->slen--;
	print_d(f, c);
}
