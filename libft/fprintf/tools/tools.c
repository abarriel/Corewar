/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 23:12:00 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/09 00:31:00 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		if_so(char conv, char *symb)
{
	char *tmp;

	tmp = NULL;
	if (symb)
		tmp = symb;
	while (symb && *symb)
	{
		if (conv == *symb)
			return (symb - tmp);
		symb++;
	}
	return (0);
}

int		putstr_per(char *str, int fd)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	write(fd, str, i);
	return (i);
}

char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*d;
	char	*tmp;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	d = ft_strjoin(tmp, s3);
	ft_strdel(&tmp);
	return (d);
}

char	*ft_strjoin_four(char *s1, char *s2, char *s3, char *s4)
{
	char	*d;
	char	*tmp;

	if (!s1 || !s2 || !s3 || !s4)
		return (NULL);
	d = ft_strjoin(s1, s2);
	tmp = ft_strjoin(d, s3);
	ft_strdel(&d);
	d = ft_strjoin(tmp, s4);
	ft_strdel(&tmp);
	return (d);
}
