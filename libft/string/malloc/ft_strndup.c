/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 22:42:36 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/20 05:15:58 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t i)
{
	char	*d;

	if (!(d = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	d[i] = '\0';
	ft_memcpy(d, s, i);
	return (d);
}
