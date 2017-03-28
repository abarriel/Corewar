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

int		cmp_struct_op(char *op, t_op *op_struct)
{
	int	index;

	index = 0;
	while (index < 16)
	{
		if (!ft_strcmp(op, op_struct[index].mnemonique))
			return (index);
		index++;
	}
	return (-1);
}

void	handles_instructions(t_asm *a, t_cmd *c, t_op *op_struct)
{
	char	**args;
	size_t	index;

	index = 0;
	args = ft_strsplit(c->args, SEPARATOR_CHAR);
	while (args[index])
		index++;
	if (index != op_struct[c->nb_struct].nbr_args)
		invalid_error(c->op, index);
	index = 0;
	while (index != op_struct[c->nb_struct].nbr_args)
	{
		skip_space(&args[index]);
		c->type[index] = args[index];
		index++;
	}
	// c->type[index] = NULL;
}

void	handles_cmd_name(t_asm *a, t_cmd *c, t_op *op_struct, int count_line)
{
	int	i;

	i = 0;
	while (c)
	{
		if ((c->nb_struct = cmp_struct_op(c->op, op_struct)) <= -1)
			return (token_error(c->op, count_line + i, ft_strlen(c->op) + 1));
		else
		{
			c->line += i;
			// a->count_line = count_line  + i;
			handles_instructions(a, c, op_struct);
			check_instructions(a, c, op_struct);
		}
		i++;
		c = c->next;
	}
}

void	handles_op(t_asm *a, t_lab *l, t_op *op_struct)
{
	while (l)
	{
		handles_cmd_name(a, l->cmd, op_struct, l->count_line);
		l = l->next;
	}
}

void	check_operation(t_asm *a, t_lab *l)
{
	t_op	*op_struct;

	op_struct = get_op();
	handles_op(a, l, op_struct);
	// print_label(l);
}
