/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 00:36:09 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/20 09:17:44 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_flags_(t_flag *t)
{
	t->l = 0;
	t->ll = 0;
	t->h = 0;
	t->hh = 0;
	t->jz = 0;
	t->neg = 0;
	t->plus = 0;
	t->pre_len = 0;
	t->champs = 0;
	t->slen = 0;
	t->color_nfun = 0;
}

t_flag		*set_flags(int fd)
{
	t_flag		*t;

	if (!(t = (t_flag*)malloc(sizeof(t_flag))))
		return (NULL);
	t->conv = 0;
	t->final_len = 0;
	t->signe = 0;
	t->fd = fd;
	t->has = 0;
	t->zero = 0;
	t->left = 0;
	t->aq = 0;
	t->sta = 0;
	t->b_sta = 0;
	t->preci = 0;
	set_flags_(t);
	return (t);
}

t_stock		*set_stock(const char *format, int fd)
{
	t_stock		*new_stock;

	if (!(new_stock = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	new_stock->str = (char *)format;
	new_stock->f_len = 0;
	new_stock->color_nfun = 0;
	new_stock->fd = fd;
	return (new_stock);
}

t_conv		*start_conv(void)
{
	t_conv		*c;

	if (!(c = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	c->s = NULL;
	c->aq = NULL;
	c->sp = NULL;
	c->tmp = NULL;
	c->x = "";
	c->len_aq = 0;
	c->len_zero = 0;
	c->tlen = 0;
	c->final_len = 0;
	c->i = 0;
	return (c);
}

void		free_c(t_conv *c)
{
	free(c->s);
	free(c->aq);
	free(c->sp);
	free(c->tmp);
	free(c);
}
