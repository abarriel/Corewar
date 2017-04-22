/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tools_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:22:56 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/22 16:34:46 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	insert_in_color(char *map, int index, unsigned char color, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		map[(index + i) % MEM_SIZE] = color;
		i++;
	}
}

void	insert_in_reg(unsigned char *reg, int index, unsigned int cpy)
{
	reg[index] = (cpy & 0xFF000000) >> 24;
	reg[(index + 1) % MEM_SIZE] = (cpy & 0x00FF0000) >> 16;
	reg[(index + 2) % MEM_SIZE] = (cpy & 0x0000FF00) >> 8;
	reg[(index + 3) % MEM_SIZE] = (cpy & 0x000000FF);
}

int		real_int(unsigned int nb)
{
	if (nb < 2048)
		return (nb);
	return (nb - 4096);
}

int		uns_int(int nb)
{
	if (nb < 0)
	{
		if (nb > -2048)
			return (nb + 4096);
		return (nb + 4096);
	}
	return (nb);
}
