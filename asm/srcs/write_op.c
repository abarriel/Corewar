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
			ft_printf("{9}[%s]{%p}-",c->type[index],c->r);
		}
		if (c->typs[index] & T_DIR)
		{
			ft_printf("{8}[%s] -",c->type[index]);
		}
		if (c->typs[index] & T_IND)
		{
			c->r = 		
			ft_printf("{6}[%s] -",c->type[index]);
		}
		index++;
	}
}

void	handles_code(t_asm *a, t_cmd *c, t_op *op_struct)
{
	int	i;

	i = 0;
	while (c)
	{
		// ft_printf("{9}{%s}{%d}{%s}\n",c->op, c->nb_struct,op_struct[c->nb_struct].mnemonique);
		c->code = op_struct[c->nb_struct].code;
		ft_printf("{9}[%p]",c->code);
		// ft_printf("{8}{T_REG | T_IND | T_DIR = %d}{T_DIR | T_REG %d}",T_REG | T_IND | T_DIR, T_DIR | T_REG );
		if (op_struct[c->nb_struct].idk == 1)
			write_c(c,op_struct[c->nb_struct]);
		write_arg(c, op_struct[c->nb_struct]);
		ft_printf("{8}[%p]",(int)c->barg);
		ft_printf("\n");
		c = c->next;
	}
}

void	write_op(t_asm *a, t_lab *l)
{
	t_op	*op_struct;

	op_struct = get_op();
	while (l)
	{
		handles_code(a, l->cmd, op_struct);
		l = l->next;
	}
}
