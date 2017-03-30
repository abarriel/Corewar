/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 03:15:35 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/19 22:42:12 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;

	if (!(d = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ft_memcpy(d, s, ft_strlen(s) + 1);
	return (d);
}
