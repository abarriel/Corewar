/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 22:28:41 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/08 22:44:14 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_zero_c(t_flag *f, t_conv *c)
{
	int		len;
	size_t	nlen;

	len = 0;
	nlen = (f->conv == 'C') ? ft_wcharlen(c->wch) : 1;
	if (f->zero == 1)
		len = f->champs - nlen;
	if (f->champs <= 1)
		len = 0;
	return (len);
}

void	string_sp_c(t_flag *f, t_conv *c)
{
	size_t	len;

	len = ft_wcharlen(c->wch);
	if (f->conv == 'c')
		len = 0;
	c->tlen = len + ft_strlen(c->sp);
	c->len_aq = f->champs - c->tlen;
	if (f->l == 0 && f->conv != 'C')
		c->len_aq -= 1;
	if (c->len_aq < 0)
		c->len_aq = 0;
	c->aq = ft_strsetc(c->aq, ' ', c->len_aq);
}

void	string_zero_c(t_flag *f, t_conv *c)
{
	c->len_zero = len_zero_c(f, c);
	c->sp = ft_strsetc(c->sp, '0', c->len_zero);
}
