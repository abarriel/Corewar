/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:34:28 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/09 04:03:41 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (n == 0 || dest == src)
		return (dest);
	while (n != '\0')
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
