/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 00:15:33 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/10 02:07:33 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_flag *f, t_conv *c)
{
	size_t	nlen;

	string_zero_c(f, c);
	string_sp_c(f, c);
	put_color(f->fd, f->color_nfun);
	if (f->left == 1)
	{
		c->s = ft_strjoin(c->sp, c->aq);
		ft_putstr_fd(c->sp, f->fd);
		f->conv != 'C' ? ft_putchar_fd(c->wch, f->fd) : ft_putwchar(c->wch);
		ft_putstr_fd(c->aq, f->fd);
	}
	else
	{
		c->s = ft_strjoin(c->aq, c->sp);
		ft_putstr_fd(c->s, f->fd);
		f->conv != 'C' ? ft_putchar_fd(c->wch, f->fd) : ft_putwchar(c->wch);
	}
	if (f->color_nfun > 0)
		ft_putstr_fd(RESET, f->fd);
	nlen = (f->conv != 'C') ? 1 : ft_wcharlen(c->wch);
	f->final_len = ft_strlen(c->s) + nlen;
	free_c(c);
}

void	print_s(t_flag *f, t_conv *c)
{
	string_sp_s(f, c);
	put_color(f->fd, f->color_nfun);
	if (f->conv == 'S' && f->left == 1)
	{
		ft_putnwstr(c, f);
		ft_putstr_fd(c->aq, f->fd);
	}
	else if (f->left == 1)
		c->s = ft_strjoin(c->s, c->aq);
	else if (f->conv == 'S')
	{
		ft_putstr_fd(c->aq, f->fd);
		ft_putnwstr(c, f);
	}
	else
		c->s = ft_strjoin(c->aq, c->s);
	if (f->conv != 'S')
		ft_putstr_fd(c->s, f->fd);
	else
		c->tlen = ft_strlen(c->aq) + c->tlen;
	if (f->color_nfun > 0)
		ft_putstr_fd(RESET, f->fd);
	f->final_len = (f->conv == 'S') ? c->tlen : ft_strlen(c->s);
	free_c(c);
}
