/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 21:34:55 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/20 01:08:38 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrcpy(char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	tmp = ft_strnew(i);
	while (i > 0)
	{
		tmp[j] = s[i - 1];
		j++;
		i--;
	}
	return (tmp);
}
