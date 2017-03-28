/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 19:55:20 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/09 00:12:42 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_litoa_base_neg(unsigned long int n, int nb_base, int i)
{
	int					len;
	unsigned long int	tmp;
	char				*str;
	char				*base;

	base = "0123456789ABCDEF";
	if (i == 0)
		base = "0123456789abcdef";
	len = 0;
	tmp = n;
	while (++len && tmp)
		tmp /= nb_base;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	while (len)
	{
		if (n % nb_base > 9)
			str[--len] = base[n % nb_base];
		else
			str[--len] = '0' + (n % nb_base);
		n /= nb_base;
	}
	return (str);
}

char		*ft_itoa_base_neg(unsigned int n, int nb_base, int i)
{
	int			len;
	size_t		tmp;
	char		*str;
	char		*base;

	base = "0123456789ABCDEF";
	if (i == 0)
		base = "0123456789abcdef";
	len = 0;
	tmp = n;
	while (++len && tmp)
		tmp /= nb_base;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	while (len)
	{
		if (n % nb_base > 9)
			str[--len] = base[n % nb_base];
		else
			str[--len] = '0' + (n % nb_base);
		n /= nb_base;
	}
	return (str);
}

char		*ft_itoa_base(long int n, int nb_base, int i)
{
	int				len;
	long int		tmp;
	char			*str;
	char			*base;

	base = "0123456789ABCDEF";
	if (i == 0)
		base = "0123456789abcdef";
	len = 0;
	tmp = n;
	while (++len && tmp)
		tmp /= nb_base;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	while (len)
	{
		if (n % nb_base > 9)
			str[--len] = base[n % nb_base];
		else
			str[--len] = '0' + (n % nb_base);
		n /= nb_base;
	}
	return (str);
}
