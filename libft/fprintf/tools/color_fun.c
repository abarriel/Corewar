/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 01:22:41 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/19 19:59:32 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_color(int fd, char color_nfun)
{
	if (color_nfun == 1)
		ft_putstr_fd(RED, fd);
	if (color_nfun == 2)
		ft_putstr_fd(GREEN, fd);
	if (color_nfun == 3)
		ft_putstr_fd(BLUE, fd);
	if (color_nfun == 4)
		ft_putstr_fd(PURPLE, fd);
	if (color_nfun == 5)
		ft_putstr_fd(YELLOW, fd);
	if (color_nfun == 6)
		ft_putstr_fd(AZUR, fd);
	if (color_nfun == 7)
		ft_putstr_fd(PEACH, fd);
	if (color_nfun == 8)
		ft_putstr_fd(APPLE, fd);
	if (color_nfun == 9)
		ft_putstr_fd(OR, fd);
}

void	color_fun__(t_stock *s)
{
	char *tmp;

	if (ft_strncmp(s->str, "{6}", 3) == 0)
		s->color_nfun = 6;
	else if (ft_strncmp(s->str, "{7}", 3) == 0)
		s->color_nfun = 7;
	else if (ft_strncmp(s->str, "{8}", 3) == 0)
		s->color_nfun = 8;
	else if (ft_strncmp(s->str, "{9}", 3) == 0)
		s->color_nfun = 9;
	if (s->color_nfun > 0)
	{
		tmp = s->str;
		s->str = ft_strsub(tmp, 3, ft_strlen(s->str) - 3);
	}
}

void	color_fun_(t_stock *s)
{
	char *tmp;

	if (ft_strncmp(s->str, "{1}", 3) == 0)
		s->color_nfun = 1;
	else if (ft_strncmp(s->str, "{2}", 3) == 0)
		s->color_nfun = 2;
	else if (ft_strncmp(s->str, "{3}", 3) == 0)
		s->color_nfun = 5;
	else if (ft_strncmp(s->str, "{4}", 3) == 0)
		s->color_nfun = 3;
	else if (ft_strncmp(s->str, "{5}", 3) == 0)
		s->color_nfun = 4;
	else
	{
		color_fun__(s);
		return ;
	}
	if (s->color_nfun > 0)
	{
		tmp = s->str;
		s->str = ft_strsub(tmp, 3, ft_strlen(s->str) - 3);
	}
}

void	color_fun(t_stock *s)
{
	char *tmp;

	if (ft_strncmp(s->str, "{RED}", 5) == 0)
		s->color_nfun = 1;
	else if (ft_strncmp(s->str, "{GRE}", 5) == 0)
		s->color_nfun = 2;
	else if (ft_strncmp(s->str, "{BLU}", 5) == 0)
		s->color_nfun = 3;
	else if (ft_strncmp(s->str, "{PUR}", 5) == 0)
		s->color_nfun = 4;
	else if (ft_strncmp(s->str, "{YEL}", 5) == 0)
		s->color_nfun = 5;
	else
	{
		color_fun_(s);
		return ;
	}
	if (s->color_nfun > 0)
	{
		tmp = s->str;
		s->str = ft_strsub(tmp, 5, ft_strlen(s->str) - 5);
	}
}
