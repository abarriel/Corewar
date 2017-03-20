/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:42:27 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/11 07:02:40 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s || !f)
		return (NULL);
	if (!(d = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		d[i] = (*f)(j, s[i]);
		i++;
		j++;
	}
	d[i] = '\0';
	return (d);
}
