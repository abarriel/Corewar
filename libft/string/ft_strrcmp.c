/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 21:36:09 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/23 05:48:22 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** REVERSE FIRST STRING, EXAMPLE  ALLAN.S -> S.NALLA  THEN S2 = S. THEN FREE
*/

int		ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	char	*r1;
	int		i;

	i = 0;
	r1 = ft_strrcpy((char *)s1);
	if (n == 0)
		return (0);
	else
	{
		while (--n && *r1 && *s2 && r1[i] == s2[i])
		{
			i++;
		}
	}
	i = r1[i] - s2[i];
	ft_strdel(&r1);
	return (i);
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
