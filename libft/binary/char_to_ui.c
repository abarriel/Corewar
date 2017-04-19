/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 01:05:20 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/20 01:05:58 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	chatohi(unsigned char *str)
{
	unsigned int	final;

	final = 0;
	final |= ((unsigned int)(str)[0] << 8);
	final |= ((unsigned int)(str)[1]);
	return (final);
}
