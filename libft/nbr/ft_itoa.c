/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 12:46:03 by exam              #+#    #+#             */
/*   Updated: 2017/01/09 00:13:21 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_litoa(long int n)
{
	int			len;
	long int	nb_tmp;
	char		*str;

	if (!n)
		return (ft_strdup("0"));
	len = ((n <= 0) ? 1 : 0);
	nb_tmp = n;
	while (++len && nb_tmp)
		nb_tmp /= 10;
	if (!(str = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	nb_tmp = n;
	while (nb_tmp != 0)
	{
		str[--len] = '0' + ((n < 0) ? -1 : 1) * (nb_tmp % 10);
		nb_tmp /= 10;
	}
	if (n < 0)
		*str = '-';
	return (str);
}

char		*ft_luitoa(unsigned long int n)
{
	int					len;
	unsigned long int	nb_tmp;
	char				*str;

	if (!n)
		return (ft_strdup("0"));
	len = 0;
	nb_tmp = n;
	while (++len && nb_tmp)
		nb_tmp /= 10;
	if (!(str = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	nb_tmp = n;
	while (nb_tmp != 0)
	{
		str[--len] = '0' + (nb_tmp % 10);
		nb_tmp /= 10;
	}
	return (str);
}

char		*ft_uitoa(unsigned int n)
{
	int			len;
	size_t		tmp;
	char		*str;

	tmp = n;
	len = ((n <= 0) ? 1 : 0);
	while (++len && tmp)
		tmp /= 10;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	tmp = n;
	str[--len] = '\0';
	*str = '0';
	while (tmp)
	{
		str[--len] = '0' + (tmp % 10);
		tmp /= 10;
	}
	return (str);
}

static char	*ft_itoaneg(char *str, int tmp, int len)
{
	int		l;

	l = len - 1;
	if (tmp == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = -tmp;
	while (tmp)
	{
		str[--len] = '0' + (tmp % 10);
		tmp /= 10;
	}
	*str = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*str;

	tmp = n;
	len = ((n <= 0) ? 1 : 0);
	while (++len && tmp)
		tmp /= 10;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	tmp = n;
	str[--len] = '\0';
	*str = '0';
	if (tmp >= 0)
		while (tmp)
		{
			str[--len] = '0' + (tmp % 10);
			tmp /= 10;
		}
	else
		return (ft_itoaneg(str, tmp, len));
	return (str);
}
