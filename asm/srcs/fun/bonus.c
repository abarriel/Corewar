/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:21:31 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/31 16:21:32 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void bonus(t_asm *a, t_lab *l, t_header *h, t_op *op)
{
	unsigned int size;
	ft_printf("\n\n\n");
	if (!l)
	{
		ft_printf("No instructions found for %s\n",h->prog_name);
		exit(0);
	}
	size =h->prog_size;
	ft_printf("Dumping annotated program on standar output\n");
	ft_printf("Programme size : \e[38;5;6m%d\033[0;m bytes",size);
}
