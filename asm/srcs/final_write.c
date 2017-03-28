/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 08:53:16 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/27 08:53:17 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
** LABEL SANS ARG , NE TROUVER PAS QUAND JE CHERCHE LE LABEL NORMAL
** JE DOIS FOUTRE CMD->BYTES DANS LE LABEL->BYTES
** ARGS SANS LABEL A GERER AUSSI JE DOI NEXT LE PARSER DE LABEL ET C TOUT
**/
void f_write_cmd(t_asm *a, t_cmd *c, t_op op_t)
{
	short index;

	index = 0;
	while(index != op_t.nbr_args)
	{
		if (c->typs[index] & T_REG)
			write(a->fd_cor,&(c->r[index]),sizeof(c->r[index]));
		if (c->typs[index] & T_DIR)
		{
			if ((!op_t.idk && op_t.idk1) || (op_t.idk & op_t.idk1))
			write(a->fd_cor,&(c->d2[index]),sizeof(c->d2[index]));
			else
			write(a->fd_cor,&(c->d4[index]),sizeof(c->d4[index]));
		}
		if (c->typs[index] & T_IND)
			write(a->fd_cor,&(c->ind[index]),sizeof(c->ind[index]));
		index++;
	}
}
void final_write(t_asm *a, t_header *h, t_lab *l, t_op *op_struct)
{
	write(a->fd_cor, h, sizeof(t_header));
	while(l)
	{
		while(l->cmd)
		{
			write (a->fd_cor,&(l->cmd->code),sizeof(l->cmd->code));
			if (op_struct[l->cmd->nb_struct].idk == 1)
				write(a->fd_cor, &(l->cmd->barg), sizeof(l->cmd->barg));
			f_write_cmd(a,l->cmd, op_struct[l->cmd->nb_struct]);
			l->cmd = l->cmd->next;
		}
			
		l = l->next;
	}
}
