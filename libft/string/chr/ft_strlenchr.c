/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 01:18:48 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/20 01:18:50 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlchr(char *s, int c)
{
	size_t	n;
	char	c1;
	size_t	len;

	len = 0;
	n = ft_strlen(s) + 1;
	c1 = (unsigned char)c;
	while (n != '\0')
	{
		if (*s != c1)
		{
			s++;
			len++;
		}
		else
			return (len);
		n--;
	}
	return (0);
}
