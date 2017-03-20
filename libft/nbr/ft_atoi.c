/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 04:08:34 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/06 07:47:26 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	nga;
	int	numar;

	i = 0;
	nga = 0;
	numar = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		nga = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		numar = numar * 10;
		numar = numar + (str[i] - '0');
		i++;
	}
	if (nga == 1)
		return (-numar);
	else
		return (numar);
}

int		len_check_max(char *str)
{
	int i;
	int u;

	u = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		u++;
	}
	if (u > 10)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	i;
	int		u;
	long	nga;
	long	numar;

	i = 0;
	numar = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	nga = (str[i] == '-') ? 1 : 0;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	u = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		u = (str[i] == '0') ? u - 1 : u;
		numar = numar * 10;
		numar = numar + (str[i] - '0');
		i++;
	}
	if (len_check_max((char *)str) == 1)
		return (-1);
	numar = (nga == 1) ? numar * -1 : numar;
	return (numar);
}

int		ft_atoi_p(char **s)
{
	int		i;
	char	*str;
	int		nga;
	int		numar;

	str = *s;
	i = 0;
	nga = 0;
	numar = 0;
	while (str[i] == ' ')
		i++;
	nga = (str[i] == '-') ? 1 : 0;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		numar = numar * 10;
		numar = numar + (str[i] - '0');
		i++;
	}
	*s = (str + i);
	numar = (nga == 1) ? numar * -1 : numar;
	return (numar);
}
