/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 02:32:24 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/11 22:23:16 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *l, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	i = 0;
	j = 0;
	len = ft_strlen(l);
	if (!l)
		return ((char *)big);
	while (big[i] != '\0' && len + i <= n)
	{
		if (ft_strncmp(big + i, l, len) == 0)
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}
