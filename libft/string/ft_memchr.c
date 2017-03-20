/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:24:51 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/19 21:19:37 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	c1;

	c1 = (unsigned char)c;
	s = (unsigned char *)src;
	while (n != '\0')
	{
		if (*s != c1)
			s++;
		else
			return (s);
		n--;
	}
	return (NULL);
}

int		ft_strrcmp(char *s1, char *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (n)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		++d1;
		++d2;
		--n;
	}
	return (0);
}
