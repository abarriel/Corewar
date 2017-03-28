/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 05:29:40 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/12 03:45:38 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(d = (char*)malloc(sizeof(*s) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		d[i] = (*f)(s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
