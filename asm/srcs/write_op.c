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

char 	write_c(t_cmd *c, t_op op_t)
{	
	char typs;
	ft_printf("{9}[%c]")
	// typs = 
	// c->code = op_t.code;
	// c->type = 
	// c->type = 
	// ft_printf("{9}{%#x}\n",c->code);
	
}
void	handles_code(t_asm *a, t_cmd *c, t_op *op_struct)
{
	int	i;

	i = 0;
	while (c)
	{
		// ft_printf("{9}{%s}{%d}{%s}\n",c->op, c->nb_struct,op_struct[c->nb_struct].mnemonique);
		c->code = op_struct[c->nb_struct].code;
		c->type = write_c(c,op_struct[c->nb_struct]);
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
