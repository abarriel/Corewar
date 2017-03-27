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
	// t_op	*op_struct;

	// op_struct = get_op();
	write(a->fd_cor, h, sizeof(t_header));
	// write(a->fd_cor, &(h->magic), sizeof(COREWAR_EXEC_MAGIC));
	// write(a->fd_cor, &(h->prog_name), sizeof(h->prog_name + 1));
	// write(a->fd_cor, &(a->total_bytes), sizeof(a->total_bytes));
	// write(a->fd_cor, &(h->comment), sizeof(h->comment));
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
