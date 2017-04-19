/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_entry_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 22:49:20 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 22:49:22 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int						is_a_champ(char *str)
{
	if ((ft_strrncmp(str, "roc.", 4)) || ft_strlen(str) == 4)
		return (1);
	return (0);
}

unsigned long int		chatoli(char **str)
{
	unsigned long int final;

	final = 0;
	final |= ((unsigned long)(*str)[0] << 56);
	final |= ((unsigned long)(*str)[1] << 48);
	final |= ((unsigned long)(*str)[2] << 40);
	final |= ((unsigned long)(*str)[3] << 32);
	final |= ((unsigned long)(*str)[4] << 24);
	final |= ((unsigned long)(*str)[5] << 16);
	final |= ((unsigned long)(*str)[6] << 8);
	final |= ((unsigned long)(*str)[7]);
	return (final);
}

size_t					ft_endian(size_t n)
{
	size_t	r;

	r = 0;
	r += ((n & 0xff000000) / 0x1000000);
	r += ((n & 0xff0000) / 0x100);
	r += ((n & 0xff00) * 0x100);
	r += ((n & 0xff) * 0x10000);
	return (r);
}
