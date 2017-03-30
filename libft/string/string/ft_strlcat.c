/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:26:05 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/12 02:55:03 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	q;

	i = 0;
	q = 0;
	i = ft_strnlen(dst, size);
	len = i;
	while (src[q] && i < size - 1)
	{
		dst[i] = src[q];
		i++;
		q++;
	}
	if (len < size)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
