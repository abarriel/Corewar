/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 22:57:55 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/08 23:02:12 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	len_s(t_flag *f, t_conv *c)
{
	c->tlen = (f->conv == 'S') ? ft_strnwlen(c, f) : ft_strlen(c->s);
	if (f->preci == 1 && f->pre_len < c->tlen && f->conv != '%')
	{
		c->tlen = f->pre_len;
		c->s = ft_strsub(c->s, 0, f->pre_len);
	}
}

void	string_sp_s(t_flag *f, t_conv *c)
{
	len_s(f, c);
	c->len_aq = f->champs - c->tlen;
	if (c->len_aq < 0)
		c->len_aq = 0;
	if (f->zero == 0)
		c->aq = ft_strsetc(c->aq, ' ', c->len_aq);
	else
		c->aq = ft_strsetc(c->aq, '0', c->len_aq);
}
