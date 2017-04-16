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
	ft_printf("\n\n");
	if (!l)
	{
		ft_printf("No instructions found for %s\n",h->prog_name);
		exit(0);
	}
	size = swap_uint(a->total_bytes);
	// h->prog_size = 
	ft_printf("Dumping annotated program on standar output\n");
	ft_printf("Programme size : \e[38;5;6m%d\033[0;m bytes\n",size);
	ft_printf("Name :\"\e[38;5;6m%s\033[0;m\"\n",h->prog_name);
	ft_printf("Comment :\"\e[38;5;6m%s\033[0;m\"\n\n",h->comment);
	while(l)
	{
		ft_printf("%3d : ",l->bytes);
		ft_printf("%s\n",l->label);
		while(l->cmd)
		{
			ft_printf("\t %d %s\n",l->cmd->bytes, l->cmd->op);
			ft_printf("\t%5d\n",1);
			l->cmd = l->cmd->next;
		}
		l = l->next;
	}

}
