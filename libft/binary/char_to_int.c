/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 01:05:16 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/20 01:06:15 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	chatoi(unsigned char *str)
{
	unsigned int	final;

	final = 0;
	final |= ((unsigned int)(str)[0] << 24);
	final |= ((unsigned int)(str)[1] << 16);
	final |= ((unsigned int)(str)[2] << 8);
	final |= ((unsigned int)(str)[3]);
	return (final);
}
