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

int		cmp_struct_op(char *op)
{
	int	index;

	index = 0;
	while (index < 16)
	{
		if (!ft_strcmp(op, g_op[index].mnemonique))
			return (index);
		index++;
	}
	return (-1);
}

void	handles_instructions(t_cmd *c)
{
	char	**args;
	size_t	index;

	index = 0;
	args = ft_strsplit(c->args, SEPARATOR_CHAR);
	while (args[index])
		index++;
	if ((char)index != g_op[c->nb_struct].nbr_args)
		invalid_error(c->op, index);
	index = 0;
	while ((char)index != g_op[c->nb_struct].nbr_args)
	{
		skip_space(&args[index]);
		c->type[index] = args[index];
		index++;
	}
}

void	handles_cmd_name(t_asm *a, t_cmd *c, int count_line)
{
	int	i;

	i = 0;
	while (c)
	{
		if ((c->nb_struct = cmp_struct_op(c->op)) <= -1)
			return (token_error(c->op, count_line + i, ft_strlen(c->op) + 1));
		else
		{
			c->line += i;
			handles_instructions(c);
			check_instructions(a, c);
		}
		i++;
		c = c->next;
	}
}

void	handles_op(t_asm *a, t_lab *l)
{
	while (l)
	{
		handles_cmd_name(a, l->cmd, l->count_line);
		l = l->next;
	}
}

void	check_operation(t_asm *a, t_lab *l)
{
	handles_op(a, l);
}
