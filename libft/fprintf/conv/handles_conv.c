/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 21:25:01 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/08 22:20:23 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handles_warning(t_flag *f)
{
	if (f->jz == 1 && !if_so(f->conv, "%cs"))
		f->l = 1;
	if (if_so(f->conv, "uUpxXoObB"))
	{
		f->signe = 0;
		f->aq = 0;
	}
	if (f->preci == 1 && !if_so(f->conv, "%csCS"))
		f->zero = 0;
	if (f->signe == 1)
		f->aq = 0;
	if (f->left == 1)
		f->zero = 0;
	if (f->pre_len < 0)
	{
		f->champs = f->pre_len * -1;
		f->pre_len = 0;
	}
	if (f->conv == 'p')
	{
		f->l = 1;
		f->has = 1;
		f->h = 0;
	}
}

void	handles_conv(t_flag *f, t_stock *s)
{
	handles_warning(f);
	if (f->conv == 'd' || f->conv == 'i' || f->conv == 'D')
		return (conv_d(s, f));
	if (f->conv == 'u' || f->conv == 'U')
		return (conv_u(s, f));
	if (f->conv == 'o' || f->conv == 'O')
		return (conv_base(s, f, 8));
	if (f->conv == 'x' || f->conv == 'X' || f->conv == 'p')
		return (conv_base(s, f, 16));
	if (f->conv == 'c' || f->conv == 'C')
		return (conv_c(s, f));
	if (f->conv == 's' || f->conv == 'S' || f->conv == '%')
		return (conv_s(s, f));
	if (f->conv == 'b' || f->conv == 'B')
		return (conv_base(s, f, 2));
}
