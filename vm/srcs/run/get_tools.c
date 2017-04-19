/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:21:27 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/19 20:57:09 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char	*cp_reg(unsigned char *dest, unsigned char *src)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int				size_arg(unsigned char oc_cde, int d_size, int i)
{
	unsigned int	cde;

	if (i == 1)
		cde = (oc_cde & 192) >> 6;
	else if (i == 2)
		cde = (oc_cde & 48) >> 4;
	else
		cde = (oc_cde & 12) >> 2;
	if (cde == 1)
		return (1);
	if (cde == 3)
		return (2);
	return (d_size);
}

int				size_args(unsigned char oc_cde, int d_size)
{
	int	res;

	res = 0;
	res += size_arg(oc_cde, d_size, 1);
	res += size_arg(oc_cde, d_size, 2);
	if (oc_cde & 12)
		res += size_arg(oc_cde, d_size, 3);
	return (2 + res);
}

unsigned char	*get_n_reg(t_core *core, t_process *process, int arg)
{
	unsigned char	*reg;
	int				dec;
	int				i;

	i = 1;
	dec = 0;
	while (i < arg)
	{
		dec += size_arg(core->mem[(process->pc + 1) % MEM_SIZE],
		4 - 2 * process->op->l_size, i);
		i++;
	}
	reg = process->reg[core->mem[(process->pc + 2 + dec) % MEM_SIZE] - 1];
	return (reg);
}
