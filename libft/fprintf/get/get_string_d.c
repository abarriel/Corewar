/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 22:46:26 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/11 22:45:20 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_zero(t_flag *f)
{
	int	len;

	len = 0;
	if (f->pre_len > 0)
	{
		len = f->pre_len - f->slen;
		if (f->aq == 1 && f->signe == 0 && f->plus == 1)
			len++;
	}
	else
		len = (f->champs - f->pre_len) - f->slen;
	if ((f->signe == 1 && f->plus == 1) || f->neg == 1 || f->aq == 1)
		len--;
	if (((f->pre_len <= 0) && f->zero == 0) || len < 0)
		len = 0;
	if (len >= 2 && f->conv == 'p' && f->preci <= 0)
		len -= 2;
	return (len);
}

void	handles_sign(t_flag *f, t_conv *c)
{
	if (f->plus == 1 && f->signe == 1)
		c->sp = ft_strjoin("+", c->sp);
	if (f->aq == 1 && f->neg == 0 && f->left == 0)
		c->sp = ft_strjoin(" ", c->sp);
	if (f->neg == 1)
		c->sp = ft_strjoin("-", c->sp);
}

void	string_sp(t_flag *f, t_conv *c)
{
	c->tlen = ft_strlen(c->s) + ft_strlen(c->sp);
	if (f->has == 1)
	{
		if (if_so(f->conv, "oO"))
			c->tlen += 1;
		if (if_so(f->conv, "xXp"))
			c->tlen += 2;
	}
	c->len_aq = f->champs - c->tlen;
	if (f->aq == 1 && c->i >= 0 && f->left == 1)
		c->len_aq--;
	if (c->len_aq < 0)
		c->len_aq = 0;
	c->aq = ft_strsetc(c->tmp, ' ', c->len_aq);
}

void	string_zero(t_flag *f, t_conv *c)
{
	c->len_zero = len_zero(f);
	c->sp = ft_strsetc(c->sp, '0', c->len_zero);
	handles_sign(f, c);
}
