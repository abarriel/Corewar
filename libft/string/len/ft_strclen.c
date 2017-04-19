/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 04:01:40 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/24 03:47:29 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strclen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

size_t		ft_strslen(const char *s, char *c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len] != '\0')
	{
		while (c[i] != '\0')
		{
			if (s[len] == c[i])
				return (len);
			i++;
		}
		i = 0;
		len++;
	}
	return (len);
}
