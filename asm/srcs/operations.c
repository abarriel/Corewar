/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 04:06:20 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/24 10:24:25 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
** SKIP LE CMP AVEC LE PREMIER MAILLION CAR IL NEXISTE PAS
*/
int	cmp_struct_op(char *op, t_op *op_struct)
{
	int index;

	index = 0;
	while(index < 16)
	{
		if (!ft_strcmp(op,op_struct[index].mnemonique))
			return(index);	
		// ft_printf("{2}%s\n",op_struct[index].mnemonique);
		index++;
	}
	return (-1);
}

void handles_instructions(t_asm *a, t_cmd *c, t_op *op_struct)
{
	
}

void handles_cmd_name(t_asm *a, t_cmd *c, t_op *op_struct)
{
	int i;

	i = 0;
	while (c)
		{
			if ((c->nb_struct = cmp_struct_op(c->op, op_struct)) == -1)
				return (token_error(c->op, a->count_line, ft_strlen(c->op) + 1));
			else
				handles_instructions(a,c,op_struct);
			// ft_printf("{9}\t%s struc:%d\n",c->op, i);
			// ft_printf("{5}%s\n",c->args);
			c = c->next;
		}
		// ft_printf("\n");

}
void handles_op(t_asm *a, t_lab *l, t_op *op_struct)
{
	while (l)
	{
		// ft_printf("{8}%s:\n",l->label);
		handles_cmd_name(a, l->cmd, op_struct);
		l = l->next;
	}
}
void check_operation(t_asm *a, t_lab *l)
{
	t_op *op_struct;

	op_struct = get_op();
	// t_lab	*lab;
	// op = get_op();
	handles_op(a, l, op_struct);
	// print_label(l);
}	