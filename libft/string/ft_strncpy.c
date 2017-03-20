/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 03:41:42 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/09 00:07:18 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	len;

	len = ft_strlen(src);
	if (len >= n)
		ft_memcpy(dest, src, n);
	else
	{
		ft_memcpy(dest, src, n);
		ft_bzero(dest + len, n - len);
	}
	return (dest);
}
