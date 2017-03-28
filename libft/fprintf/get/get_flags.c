/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 22:24:12 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/19 15:21:46 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_conv(char *n_arg, t_flag *f)
{
	char	*flags;
	short	i;

	flags = "sSpdDioOuUXxcCbB%";
	i = 0;
	if (*n_arg == '\0')
		return (f->conv == 'W');
	while (flags && flags[i] && flags[i] != *n_arg)
		i++;
	if (i < 17)
	{
		f->conv = flags[i];
		return (0);
	}
	return (1);
}

void	get_modif(char *s, t_flag *f)
{
	if (*s == 'j' || *s == 'z')
		f->jz = 1;
	if (*s == 'l' && *(s + 1) != 'l' && f->ll == 0)
		f->l = 1;
	if (*s == 'l' && *(s + 1) == 'l' && f->ll == 0)
		f->ll = 1;
	if (*s == 'h' && *(s + 1) != 'h' && f->hh == 0)
		f->h = 1;
	if (*s == 'h' && *(s + 1) == 'h' && f->hh == 0)
		f->hh = 1;
}

void	get_bonus_(int i, t_flag *f)
{
	if (f->pre_len != 1 && i == 4)
		f->pre_len = f->sta;
	if (f->pre_len == 0 && i == 2)
		f->pre_len = f->sta;
	if (f->pre_len < 0)
	{
		f->sta = f->pre_len;
		f->pre_len = f->champs;
	}
}

void	get_bonus(t_stock *t, t_flag *f)
{
	int i;

	i = f->sta;
	if (f->sta == 0)
		return ;
	f->sta = va_arg(t->aps, int);
	if (f->champs != 1 && i == 3)
		f->champs = f->sta;
	if (f->champs == 0 && i == 1)
		f->champs = f->sta;
	if (f->champs < 0)
	{
		f->champs *= -1;
		f->left = 1;
	}
	get_bonus_(i, f);
	if (f->b_sta == 2)
	{
		f->sta = va_arg(t->aps, int);
		get_bonus_(i, f);
	}
}

void	get_flags(char *s, t_flag *f)
{
	get_modif(s, f);
	if (*s == '+')
		f->signe = 1;
	if (*s == '*')
		f->b_sta += 1;
	if (*s == '*' && f->preci == 0)
		f->sta = (f->champs > 1) ? 3 : 1;
	if (*s == '*' && f->preci == 1)
		f->sta = (f->pre_len > 1) ? 4 : 2;
	if (*s == '#')
		f->has = 1;
	if (*s == '0' && f->champs == 0)
		f->zero = 1;
	if (f->champs == 0 && ft_isdigit(*s) && f->pre_len == 0)
		f->champs = ft_atoi(s);
	if (*s == '-')
		f->left = 1;
	if (*s == ' ')
		f->aq = 1;
	if (*s == '.')
	{
		f->preci = 1;
		f->pre_len = ft_atoi(s + 1);
	}
}
