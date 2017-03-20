/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 00:20:26 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/10 02:07:41 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_x_o(t_flag *f, t_conv *c)
{
	if (f->conv == 'X')
		c->x = "0X";
	if (f->conv == 'x' || f->conv == 'p')
		c->x = "0x";
	if (f->conv == 'o' || f->conv == 'O')
	{
		if (c->len_zero > 0)
			c->x = "";
		else
			c->x = "0";
	}
}

void	print_d(t_flag *f, t_conv *c)
{
	string_zero(f, c);
	string_sp(f, c);
	put_color(f->fd, f->color_nfun);
	if (f->left == 1 && f->aq == 1 && c->i >= 0)
		c->s = ft_strjoin_four(" ", c->sp, c->s, c->aq);
	else if (f->left == 1)
		c->s = ft_strjoin_three(c->sp, c->s, c->aq);
	else
		c->s = ft_strjoin_three(c->aq, c->sp, c->s);
	ft_putstr_fd(c->s, f->fd);
	if (f->color_nfun > 0)
		ft_putstr_fd(RESET, f->fd);
	f->final_len = ft_strlen(c->s);
	free_c(c);
}

void	print_base(t_flag *f, t_conv *c)
{
	string_zero(f, c);
	string_sp(f, c);
	put_color(f->fd, f->color_nfun);
	if (f->has == 1)
		get_x_o(f, c);
	if (f->left == 1 && f->aq == 1 && c->i >= 0)
		c->s = ft_strjoin_four(" ", c->sp, c->s, c->aq);
	else if (f->left == 1)
		c->s = ft_strjoin_four(c->x, c->sp, c->s, c->aq);
	else
		c->s = ft_strjoin_four(c->aq, c->x, c->sp, c->s);
	ft_putstr_fd(c->s, f->fd);
	if (f->color_nfun > 0)
		ft_putstr_fd(RESET, f->fd);
	f->final_len = ft_strlen(c->s);
	free_c(c);
}
