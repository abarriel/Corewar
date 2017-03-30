/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:16:37 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/09 00:10:33 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	size_t			v;
	int				size;

	v = (unsigned int)c;
	size = count_bits(c);
	if (size <= 7)
		return (ft_putchar(c));
	else if (size <= 11)
		ft_putchar(((v >> 6) & 31) | 192);
	else if (size <= 16)
	{
		ft_putchar(((v >> 12) & 15) | 224);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	else
	{
		ft_putchar(((v >> 18) & 7) | 240);
		ft_putchar(((v >> 12) & 63) | 128);
		ft_putchar(((v >> 6) & 63) | 128);
	}
	ft_putchar((v & 63) | 128);
}
