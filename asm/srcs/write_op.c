/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 00:39:07 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/26 00:39:19 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void 	write_c(t_cmd *c, t_op op_t)
{	
	short index;
	int mask;

	c->barg = 0;
	mask = 6;
	index = 0;
	while(index != op_t.nbr_args)
	{
		if (c->typs[index] & T_REG)
		{
			c->barg |= (REG_CODE) << mask;
			// ft_printf("{9}[%08b]\n",(REG_CODE) << mask);
		}
		if (c->typs[index] & T_DIR)
		{
			c->barg |= (DIR_CODE) << mask;
			// ft_printf("{9}[%08b]\n",(DIR_CODE) << mask);
		}
		if (c->typs[index] & T_IND)
		{
			c->barg |= (IND_CODE) << mask;
			// ft_printf("{9}[%08b]\n",(IND_CODE) << mask);
		}
		index++;
		
		mask -= 2;
	}
}

void 	write_arg(t_cmd *c, t_op op_t)
{
	char *tmp;
	short index;
	short get_reg;

	index = 0;
	while(index != op_t.nbr_args)
	{
		if (c->typs[index] & T_REG)
		{	
			tmp = (c->type[index] + 1);
			get_reg = ft_atoi(tmp);
			c->r[index] = get_reg;
			ft_dprintf(2,"{RED}[%s]{%p}-",c->type[index],c->r[index]);
			// write(1,&(c->r[index]),sizeof(c->r[index]));
			c->bytes += sizeof(c->r[index]);
		}
		if (c->typs[index] & T_DIR)
		{
			tmp = (c->type[index] + 1);
			ft_dprintf(2,"{8}[%s]",c->type[index]);
			if ((!op_t.idk && op_t.idk1) || (op_t.idk & op_t.idk1))
			{
			c->d2[index] = ft_atoi(tmp);
			ft_dprintf(2,"{8}{%p}-",c->d2[index]);	
			c->d2[index] = swap_usint(c->d2[index]);
			// write(1,&(c->d2[index]),sizeof(c->d2[index]));
			c->bytes += sizeof(c->d2[index]);
			}
			else
			{
			c->d4[index] = ft_atoi(tmp);
			ft_dprintf(2,"{3}{%p}-",c->d4[index]);
			c->d4[index] = swap_uint(c->d4[index]);
			// write(1,&(c->d4[index]),sizeof(c->d4[index]));
			c->bytes += sizeof(c->d4[index]);
			}
		}
		if (c->typs[index] & T_IND)
		{
			c->ind[index] = ft_atoi(c->type[index]);
			ft_dprintf(2,"{6}[%s]{%p} -",c->type[index],c->ind[index]);
			c->ind[index] = swap_usint(c->ind[index]);
			// write(1,&(c->ind[index]),sizeof(c->ind[index]));
			c->bytes += sizeof(c->ind[index]);
			}
		index++;
	}
}

void	handles_code(t_asm *a, t_cmd *c, t_op *op_struct)
{
	int	i;
	static int tmp;

	i = 0;
	while (c)
	{	
		c->code = op_struct[c->nb_struct].code;
		ft_dprintf(2,"{9}[%p]",c->code);
		c->bytes += sizeof(c->code);
		// write(1,&(c->code),sizeof(c->code));
		if (op_struct[c->nb_struct].idk == 1)
		{
			write_c(c,op_struct[c->nb_struct]);
			ft_dprintf(2,"{5}[%p]",(int)c->barg);
			// write(1,&(c->barg),sizeof(c->barg));
			c->bytes += sizeof(c->barg);
		}
		write_arg(c, op_struct[c->nb_struct]);
		tmp += c->bytes;
		c->t_bytes = tmp;
		ft_dprintf(2,"{2}%hd- [%hd]",c->bytes,c->t_bytes);
		ft_dprintf(2,"%hd\n",tmp);
		c = c->next;
	}
	a->total_bytes = tmp; 
}

void	write_op(t_asm *a, t_lab *l)
{
	t_op	*op_struct;

	op_struct = get_op();
	while (l)
	{
		handles_code(a, l->cmd, op_struct);
		l = l->next;
		if(l)
		l->bytes = a->total_bytes;
	}
	a->total_bytes = swap_uint(a->total_bytes);
}
