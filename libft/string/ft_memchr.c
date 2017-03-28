/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:24:51 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/23 05:48:18 by abarriel         ###   ########.fr       */
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
