/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 00:45:43 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/11 07:02:28 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *d;

	if (!s)
		return (NULL);
	if (!(d = (char*)malloc(sizeof(char) * (len) + 1)))
		return (NULL);
	d = ft_strncpy(d, &s[start], len);
	d[len] = '\0';
	return (d);
}
